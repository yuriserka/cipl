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

SymbolTypes ast_assign_type_check(AST *ast) {
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);

  if (lhs->type != AST_SYM_REF) {
    CIPL_PRINTF_COLOR(BRED, "lvalue required as left operand of assignment");
    return SYM_INVALID;
  }

  SymbolTypes lhs_t = ast_validate_types(lhs);
  SymbolTypes rhs_t = ast_validate_types(rhs);

  printf("ASSIGN_T: { LHS_T: %s, RHS_T: %s }\n", symbol_type_from_enum(lhs_t),
         symbol_type_from_enum(rhs_t));

  SymbolTypes max_t = MAX(lhs_t, rhs_t);

  if (max_t >= SYM_PTR) {
    if (lhs_t <= SYM_REAL || rhs_t <= SYM_REAL) {
      Cursor beg = {.line = rhs->rule_pos.first_line,
                    .col = rhs->rule_pos.first_column};
      Cursor end = {.line = rhs->rule_pos.last_line,
                    .col = rhs->rule_pos.last_column};
      LineInfo *li = list_peek(&lines, beg.line - 1);
      CIPL_PERROR_CURSOR_RANGE(
          "incompatible types when assigning to type " BGRN "'%s'" RESET
          " from type " BGRN "'%s'" RESET "\n",
          li->text, beg, end, symbol_canonical_type_from_enum(lhs_t),
          symbol_canonical_type_from_enum(rhs_t));
      return SYM_INVALID;
    }
  }

  return max_t;
}
