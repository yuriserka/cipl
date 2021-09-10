#include "data-structures/ast/types/bin-op.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/io.h"

AST *ast_binop_init(char *op, AST *l, AST *r) {
  BinOpAST *ast = calloc(1, sizeof(BinOpAST));
  ast->op = strdup(op);
  return ast_cast(AST_BIN_OP, 2, ast, l, r);
}

void ast_binop_free(AST *ast) {
  BinOpAST *binop_ast = ast->value.binop;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(binop_ast->op);
  free(binop_ast);
}

SymbolValues ast_binop_eval(AST *ast) { return (SymbolValues){.integer = 0}; }

void ast_binop_print(AST *ast) {
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);
  BinOpAST *binop_ast = ast->value.binop;
  printf("bin_op: { op: '%s', ", binop_ast->op);
  ast_print(lhs);
  ast_print(rhs);
  printf("}");
}

void ast_binop_print_pretty(AST *ast, int depth) {
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);
  BinOpAST *binop_ast = ast->value.binop;

  for (int i = depth; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<binary-op>\n");

  for (int i = depth + 1; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BBLU, "%s\n", binop_ast->op);

  ast_print_pretty(lhs, depth + 1);
  ast_print_pretty(rhs, depth + 1);
}
