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

static bool is_relop(char *op) {
  const int is_dless = !strcmp(op, "<<");
  const int is_dgreat = !strcmp(op, ">>");
  return (*op == '<' || *op == '>') && (!is_dless && !is_dgreat);
}

static void invalid_bin_op(AST *lhs, AST *rhs, char *op, SymbolTypes lhs_t,
                           SymbolTypes rhs_t) {
  Cursor beg = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
  Cursor end = {.col = beg.col + 1, .line = beg.line};
  LineInfo *li = list_peek(&lines, beg.line - 1);
  CIPL_PERROR_CURSOR_RANGE(
      "invalid operands to binary " WHT "'%s'" RESET " (have " BGRN "'%s'" RESET
      " and " BGRN "'%s'" RESET ")\n",
      li->text, beg, end, op, symbol_canonical_type_from_enum(lhs_t),
      symbol_canonical_type_from_enum(rhs_t));
  ++errors_count;
}

static bool is_rel_equality(char *op) { return (*op == '!' || *op == '='); }

static void handle_mismatch_comparison(AST *lhs, AST *rhs, SymbolTypes lhs_t,
                                       SymbolTypes rhs_t) {
  Cursor beg = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
  Cursor end = {.col = beg.col + 1, .line = beg.line};
  LineInfo *li = list_peek(&lines, beg.line - 1);
  if (!can_compare(lhs_t, rhs_t)) {
    CIPL_PERROR_CURSOR_RANGE(
        "comparison between " BGRN "'%s'" RESET " and " BGRN "'%s'" RESET "\n",
        li->text, beg, end, symbol_canonical_type_from_enum(lhs_t),
        symbol_canonical_type_from_enum(rhs_t));
    ++errors_count;
  }
}

static void handle_comparison_chain(AST *lhs, AST *rhs, SymbolTypes lhs_t,
                                    SymbolTypes rhs_t) {
  int show_error = lhs->type == AST_BIN_OP ? is_relop(lhs->value.binop->op)
                                           : is_relop(rhs->value.binop->op);
  if (show_error) {
    Cursor beg = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
    Cursor end = {.col = beg.col + 1, .line = beg.line};
    LineInfo *li = list_peek(&lines, beg.line - 1);
    CIPL_PERROR_CURSOR_RANGE("comparisons like " WHT "'X<=Y<=Z'" RESET
                             " do not have their mathematical "
                             "meaning\n",
                             li->text, beg, end);
    ++errors_count;
  }
}

static void handle_mismatch_equality(AST *lhs, AST *rhs, SymbolTypes lhs_t,
                                     SymbolTypes rhs_t, char *op) {
  invalid_bin_op(lhs, rhs, op, lhs_t, rhs_t);
}

static void handle_mismatch_arithmetic(AST *lhs, AST *rhs, SymbolTypes lhs_t,
                                       SymbolTypes rhs_t, char *op) {
  Cursor c = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
  LineInfo *li = list_peek(&lines, c.line - 1);
  if (lhs_t < SYM_PTR || rhs_t < SYM_PTR) {
    CIPL_PERROR_CURSOR(
        BGRN "'%s'" RESET " used in arithmetic\n", li->text, c,
        symbol_canonical_type_from_enum(lhs_t > SYM_REAL ? lhs_t : rhs_t));
    ++errors_count;
  } else {
    invalid_bin_op(lhs, rhs, op, lhs_t, rhs_t);
  }
}

static void handle_div_by_zero(AST *lhs, AST *rhs, SymbolTypes lhs_t,
                               SymbolTypes rhs_t) {
  NumberAST *rhs_num_val = rhs->value.number;
  if (rhs_num_val->sym_type == SYM_INT && !rhs_num_val->value.integer) {
    Cursor c = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
    LineInfo *li = list_peek(&lines, c.line - 1);
    CIPL_PERROR_CURSOR("division by zero\n", li->text, c);
    ++errors_count;
  }
}

static void handle_mapfil_mismatch_params(AST *fn, SymbolTypes list_type) {
  Cursor beg = cursor_init_yylloc_begin(fn->rule_pos);
  Cursor end = cursor_init_yylloc_end(fn->rule_pos);
  LineInfo *li = list_peek(&lines, beg.line - 1);
  AST *func_decl;
  AST_FIND_NODE(root, AST_USER_FUNC,
                {
                  AST *key = list_peek(&__AST__->children, 0);
                  if (!strcmp(key->value.symref->symbol->name,
                              fn->value.symref->symbol->name)) {
                    func_decl = __AST__;
                    __FOUND__ = 1;
                  }
                },
                {});
  AST *func_decl_params = list_peek(&func_decl->children, 1);
  ParamsAST *params_l = func_decl_params->value.params;
  if (params_l->size > 1 || !params_l->size) {
    CIPL_PERROR_CURSOR_RANGE(
        "function " BBLU "'%s'" RESET " should have arity 1\n", li->text, beg,
        end, fn->value.symref->symbol->name);
    ++errors_count;
  } else if (list_type > SYM_PTR) {
    SymbolTypes param_t = ast_validate_types(params_l->value->data);
    if (!can_assign(param_t, list_type - SYM_PTR)) {
      CIPL_PERROR_CURSOR_RANGE(
          "expected " BGRN "'%s'" RESET " as argument but list is of type " BGRN
          "'%s'" RESET "\n",
          li->text, beg, end, symbol_canonical_type_from_enum(param_t),
          symbol_canonical_type_from_enum(list_type - SYM_PTR));
      ++errors_count;
    }
  }
}

static void handle_mismatch_mapfil(AST *lhs, AST *rhs, SymbolTypes lhs_t,
                                   SymbolTypes rhs_t, char *op) {
  Cursor beg = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
  Cursor end = {.col = beg.col + 1, .line = beg.line};
  LineInfo *li = list_peek(&lines, beg.line - 1);
  char tmp[1024] = "";

  if (lhs->type == AST_SYM_REF && lhs->value.symref->symbol->is_fn) {
    handle_mapfil_mismatch_params(lhs, rhs_t);
  }

  if (lhs->type != AST_SYM_REF) {
    CIPL_PERROR_CURSOR_RANGE(
        "invalid operands to binary " WHT "'%s'" RESET " (have " BGRN
        "'%s'" RESET " and " BGRN "'%s'" RESET ")\n",
        li->text, beg, end, op, tmp, symbol_canonical_type_from_enum(rhs_t));
    ++errors_count;
  } else {
    if (!lhs->value.symref->symbol->is_fn || rhs_t < SYM_PTR) {
      if (lhs->value.symref->symbol->is_fn) {
        char *func_str = symbol_canonical_type_function(lhs);
        sprintf(tmp, "%s", func_str);
        free(func_str);
      } else {
        sprintf(tmp, "%s", symbol_canonical_type_from_enum(lhs_t));
      }
      CIPL_PERROR_CURSOR_RANGE(
          "invalid operands to binary " WHT "'%s'" RESET " (have " BGRN
          "'%s'" RESET " and " BGRN "'%s'" RESET ")\n",
          li->text, beg, end, op, tmp, symbol_canonical_type_from_enum(rhs_t));
      ++errors_count;
    }
  }
}

static void handle_mismatch_cons(AST *lhs, AST *rhs, SymbolTypes lhs_t,
                                 SymbolTypes rhs_t, char *op) {
  invalid_bin_op(lhs, rhs, op, lhs_t, rhs_t);
}

SymbolTypes ast_binop_type_check(AST *ast) {
  BinOpAST *binop_ast = ast->value.binop;
  AST *lhs = list_peek(&ast->children, 0), *rhs = list_peek(&ast->children, 1);
  SymbolTypes lhs_t = ast_validate_types(lhs);
  SymbolTypes rhs_t = ast_validate_types(rhs);

  switch (binop_ast->op[0]) {
    case ':':
      if (!can_cons_list(lhs_t, rhs_t)) {
        handle_mismatch_cons(lhs, rhs, lhs_t, rhs_t, binop_ast->op);
      }
      return MAX(rhs_t, SYM_PTR);
    case '<':
    case '>': {
      if (is_relop(binop_ast->op)) {
        if (!can_compare(lhs_t, rhs_t)) {
          handle_mismatch_comparison(lhs, rhs, lhs_t, rhs_t);
        } else if (lhs->type == AST_BIN_OP || rhs->type == AST_BIN_OP) {
          handle_comparison_chain(lhs, rhs, lhs_t, rhs_t);
        }
        return SYM_INT;
      } else {
        handle_mismatch_mapfil(lhs, rhs, lhs_t, rhs_t, binop_ast->op);
        return (*binop_ast->op == '<' ? MAX(rhs_t, SYM_PTR) : lhs_t + SYM_PTR);
      }
    } break;
    case '&':
    case '|':
      // anything can be part of a boolean expression and it returns a SYM_INT
      return SYM_INT;
    default: {
      if (is_rel_equality(binop_ast->op)) {
        if (!can_compare(lhs_t, rhs_t)) {
          handle_mismatch_equality(lhs, rhs, lhs_t, rhs_t, binop_ast->op);
        }
        return SYM_INT;
      } else if (!can_arith(lhs_t, rhs_t)) {
        handle_mismatch_arithmetic(lhs, rhs, lhs_t, rhs_t, binop_ast->op);
      } else if (*binop_ast->op == '/' && rhs->type == AST_NUMBER) {
        handle_div_by_zero(lhs, rhs, lhs_t, rhs_t);
      }
    }
  }

  return MAX(lhs_t, rhs_t);
}
