#include "data-structures/ast/types/params.h"

#include <stdio.h>
#include <stdlib.h>

AST *ast_params_init(ListNode *params) {
  ParamsAST *ast = calloc(1, sizeof(ParamsAST));
  ast->value = params;
  return ast_cast(AST_PARAMS, 0, ast);
}

void ast_params_free(AST *ast) {
  ParamsAST *params_ast = ast->value.params;
  list_free(params_ast->value, ast_child_free);
  free(params_ast);
}

double ast_params_eval(AST *ast) { return 0; }

void ast_params_print(AST *ast) {
  ParamsAST *params_ast = ast->value.params;
  printf("params: { ");
  list_for_each(params_ast->value, ast_child_print);
  printf("}");
}
