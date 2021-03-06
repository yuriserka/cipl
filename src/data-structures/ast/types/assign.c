#include "data-structures/ast/types/assign.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils/casting.h"
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

  printf("%*.s" BMAG "<assign>" RESET "\n", depth * 4, "");
  ast_print_pretty(lhs, depth + 1);

  printf("%*.s" WHT "=" RESET "\n", (depth + 1) * 4, "");

  print_cast(ast->cast_info, depth);

  ast_print_pretty(rhs, depth + 1 + (ast->cast_info.direction == R_CAST));
}

static void handle_lvalue_required(AST *lhs, AST *rhs) {
  Cursor beg = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
  Cursor end = {.col = beg.col + 1, .line = beg.line};
  LineInfo *li = list_peek(&lines, beg.line - 1);
  CIPL_PERROR_CURSOR_RANGE("lvalue required as left operand of assignment\n",
                           li->text, beg, end);
  ++errors_count;
}

static void handle_mismatch_assign(AST *lhs, AST *rhs) {
  Cursor c = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
  LineInfo *li = list_peek(&lines, c.line - 1);
  CIPL_PERROR_CURSOR("incompatible types when assigning to type " BGRN
                     "'%s'" RESET " from type " BGRN "'%s'" RESET "\n",
                     li->text, c,
                     symbol_canonical_type_from_enum(lhs->cast_info.data_type),
                     symbol_canonical_type_from_enum(rhs->cast_info.data_type));
  ++errors_count;
}

static void handle_mismatch_assign_func(AST *lhs, AST *rhs) {
  Cursor c = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
  LineInfo *li = list_peek(&lines, c.line - 1);
  char *t = symbol_canonical_type_function(rhs);
  CIPL_PERROR_CURSOR(
      "assignment to " BGRN "'%s'" RESET " from " BGRN "'%s'" RESET "\n",
      li->text, c, symbol_canonical_type_from_enum(lhs->cast_info.data_type),
      t);
  ++errors_count;
  free(t);
}

CastInfo ast_assign_type_check(AST *ast) {
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);

  if (lhs->type != AST_SYM_REF) {
    handle_lvalue_required(lhs, rhs);
    return cast_info_none();
  }

  if (lhs->value.symref->symbol->kind == FUNC) {
    handle_lvalue_required(lhs, rhs);
    return cast_info_none();
  }

  ast_validate_types(lhs);
  ast_validate_types(rhs);

  if (rhs->type == AST_SYM_REF && rhs->value.symref->symbol->kind == FUNC) {
    handle_mismatch_assign_func(lhs, rhs);
    return cast_info_none();
  }

  if (!lhs->cast_info.data_type || !rhs->cast_info.data_type)
    return cast_info_none();

  if (!can_assign(lhs->cast_info.data_type, rhs->cast_info.data_type))
    handle_mismatch_assign(lhs, rhs);

  return cast_info_with_type(
      cast_info_assign(lhs->cast_info.data_type, rhs->cast_info.data_type),
      MAX(lhs->cast_info.data_type, rhs->cast_info.data_type));
}

void ast_assign_gen_code(AST *ast, FILE *out) {
  AST *rhs = list_peek(&ast->children, 1);

  ast_gen_code(rhs, out);

  cast_gen_code(ast->cast_info, current_context->t9n->temp, out);

  AST *lhs = list_peek(&ast->children, 0);
  Symbol *lhs_sym = lhs->value.symref->symbol;

  fprintf(out, "pop $%d\n", current_context->t9n->temp);
  fprintf(out, "param %s%d\n", t9n_prefix(lhs_sym->kind), lhs_sym->temp);
  fprintf(out, "param $%d\n", current_context->t9n->temp);
  fprintf(out, "call set_var_val, 2\n\n");
}
