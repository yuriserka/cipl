#include "data-structures/ast/ast.h"

#include <stdio.h>
#include <stdlib.h>

AST *ast_cast(AST *ast, AstTypes type, AST *l, AST *r) {
  ast->type = type;
  ast->l = l;
  ast->r = r;
  return ast;
}

double ast_eval(AST *ast) {
  switch (ast->type) {
    case AST_NUMBER_INT:
    case AST_NUMBER_REAL:
      return ast_number_eval(ast);
    case AST_BIN_OP:
      return ast_binop_eval(ast);
    case AST_UNI_OP:
      return ast_uniop_eval(ast);
    default:
      printf("internal error: bad node %d\n", ast->type);
  }
  return 0;
}