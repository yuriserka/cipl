#include "data-structures/ast/bin-op.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/ast/ast.h"

AST *ast_binop_init(char op, AST *l, AST *r) {
  BinOpAST *ast = calloc(1, sizeof(BinOpAST));
  ast->op = op;
  return ast_cast((AST *)ast, AST_BIN_OP, l, r);
}

double ast_binop_eval(AST *ast) {
  BinOpAST *binop_ast = (BinOpAST *)ast;
  switch (binop_ast->op) {
    case '+':
      return ast_eval(ast->l) + ast_eval(ast->r);
    case '-':
      return ast_eval(ast->l) - ast_eval(ast->r);
    case '*':
      return ast_eval(ast->l) * ast_eval(ast->r);
    case '/':
      return ast_eval(ast->l) / ast_eval(ast->r);
  }
  return 0;
}