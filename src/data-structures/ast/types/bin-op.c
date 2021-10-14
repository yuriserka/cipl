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

// only god knows how this works
static bool print_cast(SymbolTypes t1, SymbolTypes t2, bool cmp, int depth) {
  if (!should_cast(t1, t2)) return false;

  if (cmp) {
    if (t2 > SYM_PTR) {
      printf("%*.s" BMAG "<%s>" RESET "\n", (depth + 1) * 4, "",
             t1 < (t2 - SYM_PTR) ? "inttofl" : "fltoint");
    } else {
      printf("%*.s" BMAG "<%s>" RESET "\n", (depth + 1) * 4, "",
             t1 < t2 ? "inttofl" : "fltoint");
    }
  }
  return true;
}

void ast_binop_print_pretty(AST *ast, int depth) {
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);

  BinOpAST *binop_ast = ast->value.binop;

  printf("%*.s" BMAG "<binary-op>" RESET "\n", depth * 4, "");
  printf("%*.s" WHT "%s" RESET "\n", (depth + 1) * 4, "", binop_ast->op);

  bool lcast = print_cast(lhs->value_type, rhs->value_type, true, depth);
  ast_print_pretty(lhs, depth + 1 + lcast);

  print_cast(rhs->value_type, lhs->value_type, false, depth);
  ast_print_pretty(rhs, depth + 1);
}

static bool is_relop(char *op) {
  const int is_dless = !strcmp(op, "<<");
  const int is_dgreat = !strcmp(op, ">>");
  return (*op == '<' || *op == '>') && (!is_dless && !is_dgreat);
}

static void invalid_bin_op(AST *lhs, AST *rhs, char *op) {
  Cursor beg = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
  Cursor end = {.col = beg.col + 1, .line = beg.line};
  LineInfo *li = list_peek(&lines, beg.line - 1);
  CIPL_PERROR_CURSOR_RANGE(
      "invalid operands to binary " WHT "'%s'" RESET " (have " BGRN "'%s'" RESET
      " and " BGRN "'%s'" RESET ")\n",
      li->text, beg, end, op, symbol_canonical_type_from_enum(lhs->value_type),
      symbol_canonical_type_from_enum(rhs->value_type));
  ++errors_count;
}

static bool is_rel_equality(char *op) { return (*op == '!' || *op == '='); }

static void handle_mismatch_comparison(AST *lhs, AST *rhs) {
  Cursor beg = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
  Cursor end = {.col = beg.col + 1, .line = beg.line};
  LineInfo *li = list_peek(&lines, beg.line - 1);
  if (!can_compare(lhs->value_type, rhs->value_type)) {
    CIPL_PERROR_CURSOR_RANGE(
        "comparison between " BGRN "'%s'" RESET " and " BGRN "'%s'" RESET "\n",
        li->text, beg, end, symbol_canonical_type_from_enum(lhs->value_type),
        symbol_canonical_type_from_enum(rhs->value_type));
    ++errors_count;
  }
}

static void handle_comparison_chain(AST *lhs, AST *rhs) {
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

static void handle_mismatch_equality(AST *lhs, AST *rhs, char *op) {
  invalid_bin_op(lhs, rhs, op);
}

static void handle_mismatch_arithmetic(AST *lhs, AST *rhs, char *op) {
  Cursor c = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
  LineInfo *li = list_peek(&lines, c.line - 1);
  if (lhs->value_type < SYM_PTR || rhs->value_type < SYM_PTR) {
    CIPL_PERROR_CURSOR(
        BGRN "'%s'" RESET " used in arithmetic\n", li->text, c,
        symbol_canonical_type_from_enum(
            lhs->value_type > SYM_REAL ? lhs->value_type : rhs->value_type));
    ++errors_count;
  } else {
    invalid_bin_op(lhs, rhs, op);
  }
}

static void handle_div_by_zero(AST *lhs, AST *rhs) {
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
    AST *param = list_peek(&params_l->value, 0);
    if (!can_assign(param->value_type, list_type - SYM_PTR)) {
      CIPL_PERROR_CURSOR_RANGE(
          "expected " BGRN "'%s'" RESET " as argument but list is of type " BGRN
          "'%s'" RESET "\n",
          li->text, beg, end,
          symbol_canonical_type_from_enum(param->value_type),
          symbol_canonical_type_from_enum(list_type - SYM_PTR));
      ++errors_count;
    }
  }
}

static void handle_mismatch_mapfil(AST *lhs, AST *rhs, char *op) {
  Cursor beg = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
  Cursor end = {.col = beg.col + 1, .line = beg.line};
  LineInfo *li = list_peek(&lines, beg.line - 1);
  char tmp[1024] = "";

  if (lhs->type == AST_SYM_REF && lhs->value.symref->symbol->kind == FUNC) {
    handle_mapfil_mismatch_params(lhs, rhs->value_type);
  }

  if (lhs->value_type > SYM_PTR) {
    CIPL_PERROR_CURSOR_RANGE("return type of " BBLU "'%s'" RESET " is not " BGRN
                             "'%s'" RESET " or " BGRN "'%s'" RESET "\n",
                             li->text, beg, end,
                             lhs->value.symref->symbol->name,
                             symbol_canonical_type_from_enum(SYM_INT),
                             symbol_canonical_type_from_enum(SYM_REAL));
    ++errors_count;
    return;
  }

  if (lhs->type != AST_SYM_REF) {
    invalid_bin_op(lhs, rhs, op);
  } else {
    Symbol *lhs_sym = lhs->value.symref->symbol;
    if (!lhs_sym->kind == FUNC || rhs->value_type < SYM_PTR) {
      if (lhs_sym->kind == FUNC) {
        char *func_str = symbol_canonical_type_function(lhs);
        sprintf(tmp, "%s", func_str);
        free(func_str);
      } else {
        sprintf(tmp, "%s", symbol_canonical_type_from_enum(lhs->value_type));
      }
      CIPL_PERROR_CURSOR_RANGE(
          "invalid operands to binary " WHT "'%s'" RESET " (have " BGRN
          "'%s'" RESET " and " BGRN "'%s'" RESET ")\n",
          li->text, beg, end, op, tmp,
          symbol_canonical_type_from_enum(rhs->value_type));
      ++errors_count;
    }
  }
}

static void handle_mismatch_cons(AST *lhs, AST *rhs, char *op) {
  invalid_bin_op(lhs, rhs, op);
}

SymbolTypes ast_binop_type_check(AST *ast) {
  BinOpAST *binop_ast = ast->value.binop;
  AST *lhs = list_peek(&ast->children, 0), *rhs = list_peek(&ast->children, 1);
  ast_validate_types(lhs);
  ast_validate_types(rhs);

  switch (binop_ast->op[0]) {
    case ':':
      if (!can_cons_list(lhs->value_type, rhs->value_type)) {
        handle_mismatch_cons(lhs, rhs, binop_ast->op);
      }
      if (rhs->value_type == SYM_PTR) return lhs->value_type + SYM_PTR;
      return MAX(rhs->value_type, SYM_PTR);
    case '<':
    case '>': {
      if (is_relop(binop_ast->op)) {
        if (!can_compare(lhs->value_type, rhs->value_type)) {
          handle_mismatch_comparison(lhs, rhs);
        } else if (lhs->type == AST_BIN_OP || rhs->type == AST_BIN_OP) {
          handle_comparison_chain(lhs, rhs);
        }
        return SYM_INT;
      } else {
        handle_mismatch_mapfil(lhs, rhs, binop_ast->op);
        if (*binop_ast->op == '<') return MAX(rhs->value_type, SYM_PTR);
        return MAX((MIN(lhs->value_type, SYM_PTR) + SYM_PTR) % 6, SYM_PTR);
      }
    } break;
    case '&':
    case '|':
      // anything can be part of a boolean expression and it returns a SYM_INT
      return SYM_INT;
    default: {
      if (is_rel_equality(binop_ast->op)) {
        if (!can_compare(lhs->value_type, rhs->value_type)) {
          handle_mismatch_equality(lhs, rhs, binop_ast->op);
        }
        return SYM_INT;
      } else if (!can_arith(lhs->value_type, rhs->value_type)) {
        handle_mismatch_arithmetic(lhs, rhs, binop_ast->op);
      } else if (*binop_ast->op == '/' && rhs->type == AST_NUMBER) {
        handle_div_by_zero(lhs, rhs);
      }
    }
  }

  return MAX(lhs->value_type, rhs->value_type);
}

static void arith_gen_code(AST *lhs, AST *rhs, char *op, FILE *out) {
  int temp = current_context->t9n->temp;

  fprintf(out, "pop $%d\n\n", temp + 1);
  fprintf(out, "pop $%d\n\n", temp);

  fprintf(out, "param $%d\n", temp);
  fprintf(out, "call get_var_val, 1\n");
  fprintf(out, "pop $%d\n\n", temp + 2);
  fprintf(out, "param $%d\n", temp + 1);
  fprintf(out, "call get_var_val, 1\n");
  fprintf(out, "pop $%d\n\n", temp + 3);

  if (lhs->value_type < rhs->value_type)
    fprintf(out, "inttofl $%d, $%d\n\n", temp + 2, temp + 2);
  if (rhs->value_type < lhs->value_type)
    fprintf(out, "inttofl $%d, $%d\n\n", temp + 3, temp + 3);

  switch (op[0]) {
    case '+':
      fprintf(out, "add");
      break;
    case '-':
      fprintf(out, "sub");
      break;
    case '*':
      fprintf(out, "mul");
      break;
    case '/':
      fprintf(out, "div");
      break;
  }

  fprintf(out, " $%d, $%d, $%d\n\n", temp + 3, temp + 2, temp + 3);
  t9n_alloc_from_other(temp + 2, MAX(lhs->value_type, rhs->value_type),
                       temp + 3, out);
}

void ast_binop_gen_code(AST *ast, FILE *out) {
  BinOpAST *binop_ast = ast->value.binop;
  AST *lhs = list_peek(&ast->children, 0), *rhs = list_peek(&ast->children, 1);

  ast_gen_code(lhs, out);
  ast_gen_code(rhs, out);

  switch (binop_ast->op[0]) {
    case ':':
      fprintf(out, "// list ctr\n");
      break;
    case '<':
    case '>':
      fprintf(out, "// can be slt/sleq or map/filter\n");
      break;
    case '&':
    case '|':
      fprintf(out, "// boolean op\n");
      break;
    case '=':
      fprintf(out, "// seq then next instruction\n");
      break;
    case '!':
      fprintf(out, "// seq then next label\n");
      break;
    default:
      arith_gen_code(lhs, rhs, binop_ast->op, out);
  }

  fprintf(out, "push $%d\n\n", current_context->t9n->temp + 2);
}
