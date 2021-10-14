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

  printf("%*.s" BMAG "<assign>" RESET "\n", depth * 4, "");
  ast_print_pretty(lhs, depth + 1);

  printf("%*.s" WHT "=" RESET "\n", (depth + 1) * 4, "");

  bool valid_cast = lhs && rhs && should_cast(lhs->value_type, rhs->value_type);

  if (valid_cast)
    printf("%*.s" BMAG "<%s>" RESET "\n", (depth + 1) * 4, "",
           lhs->value_type < rhs->value_type ? "fltoint" : "inttofl");

  ast_print_pretty(rhs, depth + 1 + valid_cast);
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
                     symbol_canonical_type_from_enum(lhs->value_type),
                     symbol_canonical_type_from_enum(rhs->value_type));
  ++errors_count;
}

SymbolTypes ast_assign_type_check(AST *ast) {
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);

  if (lhs->type != AST_SYM_REF) {
    handle_lvalue_required(lhs, rhs);
    return SYM_INVALID;
  }

  if (lhs->value.symref->symbol->kind == FUNC) {
    handle_lvalue_required(lhs, rhs);
    return SYM_INVALID;
  }

  ast_validate_types(lhs);
  ast_validate_types(rhs);

  if (!lhs->value_type || !rhs->value_type) return SYM_INVALID;

  if (!can_assign(lhs->value_type, rhs->value_type)) {
    handle_mismatch_assign(lhs, rhs);
  }

  return MAX(lhs->value_type, rhs->value_type);
}

void ast_assign_gen_code(AST *ast, FILE *out) {
  // AST *lhs = list_peek(&ast->children, 0);
  // AST *rhs = list_peek(&ast->children, 1);

  // ast_gen_code(rhs, out);

  // fprintf(out, "pop $%d\n", current_context->t9n->temp);
}
