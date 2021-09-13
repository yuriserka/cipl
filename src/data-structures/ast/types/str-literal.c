#include "data-structures/ast/types/str-literal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/io.h"

AST *ast_str_init(char *value) {
  StringLiteralAST *ast = calloc(1, sizeof(StringLiteralAST));
  ast->value = strdup(value);
  return ast_cast(AST_STR_LITERAL, 0, ast);
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

  for (int i = depth; i > 0; --i) printf("\t");

  CIPL_PRINTF_COLOR(BYEL, "'%s'\n", str_ast->value);
}
