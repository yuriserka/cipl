#include "data-structures/ast/uni-op.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "data-structures/ast/ast.h"

AST *ast_uniop_init(char op, AST *l) {
  UniOpAST *ast = calloc(1, sizeof(UniOpAST));
  ast->op = op;
  return ast_cast((AST *)ast, AST_UNI_OP, 1, l);
}

double ast_uniop_eval(AST *ast) {
  UniOpAST *uniop_ast = (UniOpAST *)ast;
  AST *lhs = ast->children->data;
  switch (uniop_ast->op) {
    case '!':
      return fabs(ast_eval(lhs));
    case '-':
      return -ast_eval(lhs);
  }
  return 0;
}

void ast_uniop_print(AST *ast) {
  UniOpAST *uniop_ast = (UniOpAST *)ast;
  printf("uni_op: { op: %c, ", uniop_ast->op);
  ast_print(ast->children->data);
  printf("}");
}
