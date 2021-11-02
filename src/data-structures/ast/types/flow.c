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

CastInfo ast_flow_type_check(AST *ast) {
  AST *conditional = list_peek(&ast->children, 0);
  AST *then_branch = list_peek(&ast->children, 1);
  AST *else_branch = list_peek(&ast->children, 2);

  ast_validate_types(conditional);
  ast_validate_types(then_branch);
  ast_validate_types(else_branch);

  return cast_info_none();
}

void ast_flow_gen_code(AST *ast, FILE *out) {
  AST *conditional = list_peek(&ast->children, 0);
  AST *then_branch = list_peek(&ast->children, 1);
  AST *else_branch = list_peek(&ast->children, 2);

  ast_gen_code(conditional, out);

  int curr_tmp = current_context->t9n->temp;

  fprintf(out, "pop $%d\n\n", curr_tmp);
  fprintf(out, "param $%d\n", curr_tmp);
  fprintf(out, "call get_var_val, 1\n");
  fprintf(out, "pop $%d\n\n", curr_tmp + 1);
  // fprintf(out, "seq $%d, $%d, 0\n", curr_tmp + 1, curr_tmp + 1);
  fprintf(out, "param $%d\n", curr_tmp + 1);
  fprintf(out, "call set_bool, 1\n");
  fprintf(out, "pop $%d\n\n", curr_tmp + 1);
  fprintf(out, "brz %s_L%d_ELSE, $%d\n", current_context->name,
          current_context->t9n->label, curr_tmp + 1);
  int label = current_context->t9n->label++;

  ast_gen_code(then_branch, out);

  fprintf(out, "jump %s_L%d_END\n", current_context->name, label);

  fprintf(out, "%s_L%d_ELSE:\n", current_context->name, label);

  ast_gen_code(else_branch, out);

  fprintf(out, "%s_L%d_END:\n", current_context->name, label);
}
