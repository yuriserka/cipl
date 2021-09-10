#include "data-structures/ast/types/declaration.h"

#include <stdio.h>
#include <stdlib.h>

#include "core/globals.h"
#include "utils/io.h"

AST *ast_declaration_init(AST *name) {
  DeclarationAST *ast = calloc(1, sizeof(DeclarationAST));
  return ast_cast(AST_DECLARATION, 1, ast, name);
}

void ast_declaration_free(AST *ast) {
  DeclarationAST *decl_ast = ast->value.declaration;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(decl_ast);
}

SymbolValues ast_declaration_eval(AST *ast) { return (SymbolValues){.integer = 0}; }

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
