#include "data-structures/ast/bin-op.h"

#include <stdio.h>
#include <stdlib.h>

AST *ast_binop_init(char op, AST *l, AST *r) {
  BinOpAST *ast = calloc(1, sizeof(BinOpAST));
  ast->op = op;
  return ast_cast(AST_BIN_OP, 2, ast, l, r);
}

void ast_binop_free(AST *ast) {
  BinOpAST *binop_ast = ast->value.binop;
  list_free(ast->children, ast_child_free);
  free(binop_ast);
}

double ast_binop_eval(AST *ast) {
  BinOpAST *binop_ast = ast->value.binop;
  AST *lhs = ast->children->data;
  AST *rhs = ast->children->next->data;
  switch (binop_ast->op) {
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
  printf("bin_op: { op: %c, ", binop_ast->op);
  ast_print(ast->children->data);
  ast_print(ast->children->next->data);
  printf("}");
}
