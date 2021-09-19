#include "data-structures/ast/types/bin-op.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/io.h"

AST *ast_binop_init(YYLTYPE rule_pos, char *op, AST *l, AST *r) {
  BinOpAST *ast = calloc(1, sizeof(BinOpAST));
  ast->op = strdup(op);
  return ast_cast(AST_BIN_OP, rule_pos, 2, ast, l, r);
}

void ast_binop_free(AST *ast) {
  BinOpAST *binop_ast = ast->value.binop;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(binop_ast->op);
  free(binop_ast);
}

SymbolValues ast_binop_eval(AST *ast) { return (SymbolValues){.integer = 0}; }

void ast_binop_print(AST *ast) {
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);
  BinOpAST *binop_ast = ast->value.binop;
  printf("bin_op: { op: '%s', ", binop_ast->op);
  ast_print(lhs);
  ast_print(rhs);
  printf("}");
}

void ast_binop_print_pretty(AST *ast, int depth) {
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);
  BinOpAST *binop_ast = ast->value.binop;

  for (int i = depth; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<binary-op>\n");

  for (int i = depth + 1; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BBLU, "%s\n", binop_ast->op);

  ast_print_pretty(lhs, depth + 1);
  ast_print_pretty(rhs, depth + 1);
}

SymbolTypes ast_binop_type_check(AST *ast) {
  BinOpAST *binop_ast = ast->value.binop;
  AST *lhs = list_peek(&ast->children, 0), *rhs = list_peek(&ast->children, 1);
  SymbolTypes lhs_t = ast_validate_types(lhs);
  SymbolTypes rhs_t = ast_validate_types(rhs);

  // printf("BINOP_T: { LHS_T: %s, RHS_T: %s }\n", symbol_type_from_enum(lhs_t),
  //        symbol_type_from_enum(rhs_t));
  SymbolTypes max_t = MAX(lhs_t, rhs_t);

  switch (binop_ast->op[0]) {
    case ':':
      break;
    case '<':
    case '>': {
      const int is_dless = !strcmp(binop_ast->op, "<<");
      const int is_dgreat = !strcmp(binop_ast->op, ">>");

      const int is_cmp = !is_dless && !is_dgreat;

      if (is_cmp) {
        if (max_t >= SYM_PTR) {
          if (lhs_t <= SYM_REAL || rhs_t <= SYM_REAL) {
            Cursor beg = {.col = rhs->rule_pos.first_column -
                                 ceil((rhs->rule_pos.first_column -
                                       lhs->rule_pos.last_column) /
                                      2.0),
                          .line = ast->rule_pos.last_line};
            Cursor end = {.col = beg.col + 1, .line = beg.line};
            LineInfo *li = list_peek(&lines, beg.line - 1);
            CIPL_PERROR_CURSOR_RANGE("comparison between " BGRN "'%s'" RESET
                                     " and " BGRN "'%s'" RESET "\n",
                                     li->text, beg, end,
                                     symbol_canonical_type_from_enum(lhs_t),
                                     symbol_canonical_type_from_enum(rhs_t));
            ++errors_count;
            return SYM_INVALID;
          }
        }
      } else {
      }
    } break;
    default:
      if (max_t >= SYM_PTR) {
        if (lhs_t <= SYM_REAL || rhs_t <= SYM_REAL) {
          Cursor c = {
              .col = rhs->rule_pos.first_column -
                     ((rhs->rule_pos.first_column - lhs->rule_pos.last_column) /
                      2),
              .line = ast->rule_pos.last_line};
          LineInfo *li = list_peek(&lines, c.line - 1);
          CIPL_PERROR_CURSOR(
              BGRN "'%s'" RESET " used in arithmetic\n", li->text, c,
              symbol_canonical_type_from_enum(lhs_t > SYM_REAL ? lhs_t
                                                               : rhs_t));
          ++errors_count;
          return SYM_INVALID;
        }
      }
  }

  return max_t;
}
