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

static int is_rel(char *op) {
  const int is_dless = !strcmp(op, "<<");
  const int is_dgreat = !strcmp(op, ">>");
  return (*op == '<' || *op == '>' || *op == '!') && !is_dless && !is_dgreat;
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
    case '>':
    case '=':
    case '!': {
      const int is_dless = !strcmp(binop_ast->op, "<<");
      const int is_dgreat = !strcmp(binop_ast->op, ">>");

      const int is_cmp = !is_dless && !is_dgreat;

      if (is_cmp) {
        if (max_t >= SYM_PTR) {
          if (lhs_t <= SYM_REAL || rhs_t <= SYM_REAL) {
            Cursor beg =
                cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
            Cursor end = {.col = beg.col + 1, .line = beg.line};
            LineInfo *li = list_peek(&lines, beg.line - 1);
            CIPL_PERROR_CURSOR_RANGE("comparison between " BGRN "'%s'" RESET
                                     " and " BGRN "'%s'" RESET "\n",
                                     li->text, beg, end,
                                     symbol_canonical_type_from_enum(lhs_t),
                                     symbol_canonical_type_from_enum(rhs_t));
            ++errors_count;
          }
        } else if (lhs->type == AST_BIN_OP || rhs->type == AST_BIN_OP) {
          int show_error = lhs->type == AST_BIN_OP
                               ? is_rel(lhs->value.binop->op)
                               : is_rel(rhs->value.binop->op);
          if (show_error) {
            Cursor beg =
                cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
            Cursor end = {.col = beg.col + 1, .line = beg.line};
            LineInfo *li = list_peek(&lines, beg.line - 1);
            CIPL_PERROR_CURSOR_RANGE(
                "comparisons like ‘X<=Y<=Z’ do not have their mathematical "
                "meaning\n",
                li->text, beg, end);
            ++errors_count;
          }
        }
      } else {
      }
    } break;
    default:
      if (max_t >= SYM_PTR) {
        if (lhs_t <= SYM_REAL || rhs_t <= SYM_REAL) {
          Cursor c = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
          LineInfo *li = list_peek(&lines, c.line - 1);
          CIPL_PERROR_CURSOR(
              BGRN "'%s'" RESET " used in arithmetic\n", li->text, c,
              symbol_canonical_type_from_enum(lhs_t > SYM_REAL ? lhs_t
                                                               : rhs_t));
          ++errors_count;
        }
      } else if (binop_ast->op[0] == '/' && rhs->type == AST_NUMBER) {
        long rhs_num_val = rhs->value.number->value.integer;
        if (!rhs_num_val) {
          Cursor c = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
          LineInfo *li = list_peek(&lines, c.line - 1);
          CIPL_PERROR_CURSOR("division by zero\n", li->text, c);
          ++errors_count;
        }
      }
  }

  return max_t;
}
