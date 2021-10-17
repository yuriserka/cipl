#include "data-structures/ast/types/str-literal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/io.h"

AST *ast_str_init(YYLTYPE rule_pos, char *value) {
  StringLiteralAST *ast = calloc(1, sizeof(StringLiteralAST));
  ast->value = strdup(value);
  ast->table_entry = -1;
  return ast_cast(AST_STR_LITERAL, rule_pos, 0, ast);
}

void ast_str_free(AST *ast) {
  StringLiteralAST *str_ast = ast->value.str;
  free(str_ast->value);
  free(str_ast);
}

SymbolValues ast_str_eval(AST *ast) { return (SymbolValues){.integer = 0}; }

void ast_str_print(AST *ast) {
  StringLiteralAST *str_ast = ast->value.str;
  printf("string: %s", str_ast->value);
}

void ast_str_print_pretty(AST *ast, int depth) {
  StringLiteralAST *str_ast = ast->value.str;

  printf("%*.s" BYEL "'%s'" RESET "\n", depth * 4, "", str_ast->value);
}

CastInfo ast_str_type_check(AST *ast) {
  return cast_info_with_type(cast_info_none(), SYM_PTR);
}

void ast_str_gen_code(AST *ast, FILE *out) {
  t9n_alloc_from_literal(current_context->t9n->temp,
                         ast->value.str->table_entry, out);
  fprintf(out, "push $%d\n\n", current_context->t9n->temp);
}
