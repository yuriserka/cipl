#include "data-structures/ast/types/uni-op.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AST *ast_uniop_init(char *op, AST *l) {
  UniOpAST *ast = calloc(1, sizeof(UniOpAST));
  ast->op = strdup(op);
  return ast_cast(AST_UNI_OP, 1, ast, l);
}

void ast_uniop_free(AST *ast) {
  UniOpAST *uniop_ast = ast->value.uniop;
  list_free(ast->children, ast_child_free);
  free(uniop_ast->op);
  free(uniop_ast);
}

double ast_uniop_eval(AST *ast) {
  UniOpAST *uniop_ast = ast->value.uniop;
  AST *lhs = list_peek(&ast->children, 0);
  switch (*uniop_ast->op) {
    case '!':
      return fabs(ast_eval(lhs));
    case '-':
      return -ast_eval(lhs);
  }
  return 0;
}

void ast_uniop_print(AST *ast) {
  UniOpAST *uniop_ast = ast->value.uniop;
  printf("uni_op: { op: '%s', ", uniop_ast->op);
  ast_print(ast->children->data);
  printf("}");
}
