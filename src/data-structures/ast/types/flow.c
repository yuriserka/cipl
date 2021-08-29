#include "data-structures/ast/types/flow.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/context.h"

AST *ast_flow_init(Context *context, AST *cond, AST *then_branch,
                   AST *else_branch) {
  FlowAST *ast = calloc(1, sizeof(FlowAST));
  ast->context = context;
  return ast_cast(AST_FLOW, 3, ast, cond, then_branch, else_branch);
}

void ast_flow_free(AST *ast) {
  FlowAST *flow_ast = ast->value.flow;
  list_free(ast->children, ast_child_free);
  free(flow_ast);
}

double ast_flow_eval(AST *ast) { return 0; }

void ast_flow_print(AST *ast) {
  AST *conditional = list_peek(&ast->children, 0);
  AST *then_branch = list_peek(&ast->children, 1);
  AST *else_branch = list_peek(&ast->children, 2);
  printf("if: { ");
  ast_child_print_aux_label("condition", conditional);
  ast_child_print_aux_label("then", then_branch);
  ast_child_print_aux_label("else", else_branch);
  printf("}");
}