#include "data-structures/ast/types/assign.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils/io.h"

AST *ast_assign_init(YYLTYPE rule_pos, AST *symbol, AST *value) {
  AssignAST *ast = calloc(1, sizeof(AssignAST));
  ast->op = '=';
  return ast_cast(AST_ASSIGN_OP, rule_pos, 2, ast, symbol, value);
}

void ast_assign_free(AST *ast) {
  AssignAST *assign_ast = ast->value.assignop;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(assign_ast);
}

SymbolValues ast_assign_eval(AST *ast) { return (SymbolValues){.integer = 0}; }

void ast_assign_print(AST *ast) {
  AssignAST *assign_ast = ast->value.assignop;
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);
  printf("assing_op: { op: %c, ", assign_ast->op);
  ast_child_print_aux_label("lhs", lhs);
  ast_child_print_aux_label("rhs", rhs);
  printf("}");
}

void ast_assign_print_pretty(AST *ast, int depth) {
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);

  for (int i = depth; i > 0; --i) printf("\t");

  CIPL_PRINTF_COLOR(BMAG, "<assign>\n");
  ast_print_pretty(lhs, depth + 1);

  for (int i = depth + 1; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BBLU, "=\n");

  ast_print_pretty(rhs, depth + 1);
}

static void handle_lvalue_required() {
  CIPL_PRINTF_COLOR(BRED, "lvalue required as left operand of assignment");
  ++errors_count;
}

static void handle_mismatch_assign(AST *lhs, AST *rhs, SymbolTypes lhs_t,
                                   SymbolTypes rhs_t) {
  Cursor c = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
  LineInfo *li = list_peek(&lines, c.line - 1);
  CIPL_PERROR_CURSOR("incompatible types when assigning to type " BGRN
                     "'%s'" RESET " from type " BGRN "'%s'" RESET "\n",
                     li->text, c, symbol_canonical_type_from_enum(lhs_t),
                     symbol_canonical_type_from_enum(rhs_t));
  ++errors_count;
}

SymbolTypes ast_assign_type_check(AST *ast) {
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);

  if (lhs->type != AST_SYM_REF) {
    handle_lvalue_required();
    return SYM_INVALID;
  }

  SymbolTypes lhs_t = ast_validate_types(lhs);
  SymbolTypes rhs_t = ast_validate_types(rhs);

  if (!can_assign(lhs_t, rhs_t)) {
    handle_mismatch_assign(lhs, rhs, lhs_t, rhs_t);
  }

  return MAX(lhs_t, rhs_t);
}
