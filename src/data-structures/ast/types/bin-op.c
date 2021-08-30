#include "data-structures/ast/types/bin-op.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AST *ast_binop_init(char *op, AST *l, AST *r) {
  BinOpAST *ast = calloc(1, sizeof(BinOpAST));
  ast->op = strdup(op);
  return ast_cast(AST_BIN_OP, 2, ast, l, r);
}

void ast_binop_free(AST *ast) {
  BinOpAST *binop_ast = ast->value.binop;
  list_free(ast->children, ast_child_free);
  free(binop_ast->op);
  free(binop_ast);
}

double ast_binop_eval(AST *ast) {
  BinOpAST *binop_ast = ast->value.binop;
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);
  switch (*binop_ast->op) {
    case '+':
      return ast_eval(lhs) + ast_eval(rhs);
    case '-':
      return ast_eval(lhs) - ast_eval(rhs);
    case '*':
      return ast_eval(lhs) * ast_eval(rhs);
    case '/':
      return ast_eval(lhs) / ast_eval(rhs);
  }
  return 0;
}

void ast_binop_print(AST *ast) {
  BinOpAST *binop_ast = ast->value.binop;
  printf("bin_op: { op: '%s', ", binop_ast->op);
  ast_print(ast->children->data);
  ast_print(ast->children->next->data);
  printf("}");
}
