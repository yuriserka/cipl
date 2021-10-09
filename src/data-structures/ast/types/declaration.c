#include "data-structures/ast/types/declaration.h"

#include <stdio.h>
#include <stdlib.h>

#include "core/globals.h"
#include "utils/io.h"

AST *ast_declaration_init(YYLTYPE rule_pos, AST *name) {
  DeclarationAST *ast = calloc(1, sizeof(DeclarationAST));
  return ast_cast(AST_DECLARATION, rule_pos, 1, ast, name);
}

void ast_declaration_free(AST *ast) {
  DeclarationAST *decl_ast = ast->value.declaration;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(decl_ast);
}

SymbolValues ast_declaration_eval(AST *ast) {
  return (SymbolValues){.integer = 0};
}

void ast_declaration_print(AST *ast) {
  printf("declaration: { ");
  ast_print(ast->children->data);
  printf("}");
}

void ast_declaration_print_pretty(AST *ast, int depth) {
  AST *name = list_peek(&ast->children, 0);

  for (int i = depth; i > 0; --i) printf("\t");

  CIPL_PRINTF_COLOR(BMAG, "<declaration>\n");
  ast_print_pretty(name, depth + 1);
}

SymbolTypes ast_declaration_type_check(AST *ast) {
  AST *name = list_peek(&ast->children, 0);
  return ast_validate_types(name);
}

void ast_declaration_gen_code(AST *ast, FILE *out) {
  AST *name = list_peek(&ast->children, 0);
  Symbol *declared = name->value.symref->symbol;
  fprintf(out, "// var %s %s\n",
          symbol_canonical_type_from_enum(declared->type), declared->name);
  switch (declared->type) {
    case SYM_INT:
      // $temp[0] = type
      // $temp[1] = &$var
      fprintf(out, "mema $%d, 2\n", declared->temp);
      fprintf(out, "mov $%d[1], %d\n", declared->temp, declared->value.integer);
      break;
    case SYM_REAL:
      // $temp[0] = type
      // $temp[1] = &$var
      fprintf(out, "mema $%d, 2\n", declared->temp);
      fprintf(out, "mov $%d[1], %lf\n", declared->temp, declared->value.real);
      break;
    default:
      // $temp[0] = type
      // $temp[1] = size
      // $temp[1] = &list per say
      fprintf(out, "mema $%d, 3\n", declared->temp);
  }
  fprintf(out, "mov *$%d, %d\n\n", declared->temp, declared->type);
}
