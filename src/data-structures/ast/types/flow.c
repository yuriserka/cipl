#include "data-structures/ast/types/flow.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/context.h"
#include "utils/io.h"

AST *ast_flow_init(YYLTYPE rule_pos, Context *context, AST *cond,
                   AST *then_branch, AST *else_branch) {
  FlowAST *ast = calloc(1, sizeof(FlowAST));
  ast->context = context;
  return ast_cast(AST_FLOW, rule_pos, 3, ast, cond, then_branch, else_branch);
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

  printf("%*.s" BMAG "<if-else-statement>" RESET "\n", depth * 4, "");

  printf("%*.s" BMAG "<condition>" RESET "\n", (depth + 1) * 4, "");
  ast_print_pretty(conditional, depth + 2);

  printf("%*.s" BMAG "<then-branch>" RESET "\n", (depth + 1) * 4, "");
  ast_print_pretty(then_branch, depth + 2);

  printf("%*.s" BMAG "<else-branch>" RESET "\n", (depth + 1) * 4, "");
  ast_print_pretty(else_branch, depth + 2);
}

SymbolTypes ast_flow_type_check(AST *ast) {
  AST *conditional = list_peek(&ast->children, 0);
  AST *then_branch = list_peek(&ast->children, 1);
  AST *else_branch = list_peek(&ast->children, 2);

  ast_validate_types(conditional);
  ast_validate_types(then_branch);
  ast_validate_types(else_branch);

  return MAX(then_branch->value_type,
             else_branch ? else_branch->value_type : SYM_INVALID);
}
