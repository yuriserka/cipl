#include "data-structures/ast/uni-op.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

AST *ast_uniop_init(char op, AST *l) {
  UniOpAST *ast = calloc(1, sizeof(UniOpAST));
  ast->op = op;
  return ast_cast(AST_UNI_OP, 1, ast, l);
}

void ast_uniop_free(AST *ast) {
  UniOpAST *uniop_ast = ast->value.uniop;
  list_free(ast->children, ast_child_free);
  free(uniop_ast);
}

double ast_uniop_eval(AST *ast) {
  UniOpAST *uniop_ast = ast->value.uniop;
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
  UniOpAST *uniop_ast = ast->value.uniop;
  printf("uni_op: { op: %c, ", uniop_ast->op);
  ast_print(ast->children->data);
  printf("}");
}
