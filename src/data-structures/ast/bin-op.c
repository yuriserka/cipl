#include "data-structures/ast/bin-op.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/ast/ast.h"

AST *ast_binop_init(char op, AST *l, AST *r) {
  BinOpAST *ast = calloc(1, sizeof(BinOpAST));
  ast->op = op;
  return ast_cast((AST *)ast, AST_BIN_OP, 2, l, r);
}

double ast_binop_eval(AST *ast) {
  BinOpAST *binop_ast = (BinOpAST *)ast;
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