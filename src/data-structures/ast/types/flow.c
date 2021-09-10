#include "data-structures/ast/types/flow.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/context.h"
#include "utils/io.h"

AST *ast_flow_init(Context *context, AST *cond, AST *then_branch,
                   AST *else_branch) {
  FlowAST *ast = calloc(1, sizeof(FlowAST));
  ast->context = context;
  return ast_cast(AST_FLOW, 3, ast, cond, then_branch, else_branch);
}

void ast_flow_free(AST *ast) {
  FlowAST *flow_ast = ast->value.flow;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(flow_ast);
}

SymbolValues ast_flow_eval(AST *ast) { return (SymbolValues){.integer = 0}; }

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

void ast_flow_print_pretty(AST *ast, int depth) {
  AST *conditional = list_peek(&ast->children, 0);
  AST *then_branch = list_peek(&ast->children, 1);
  AST *else_branch = list_peek(&ast->children, 2);

  for (int i = depth; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<if_else-statement>\n");

  for (int i = depth + 1; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<condition>\n");
  ast_print_pretty(conditional, depth + 2);

  for (int i = depth + 1; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<then_branch>\n");
  ast_print_pretty(then_branch, depth + 2);

  for (int i = depth + 1; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<else_branch>\n");
  ast_print_pretty(else_branch, depth + 2);
}
