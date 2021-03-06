#include "data-structures/ast/types/bin-op.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/casting.h"
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

  printf("%*.s" BMAG "<binary-op>" RESET "\n", depth * 4, "");
  printf("%*.s" WHT "%s" RESET "\n", (depth + 1) * 4, "", binop_ast->op);

  if (ast->cast_info.direction == L_CAST) print_cast(ast->cast_info, depth);
  ast_print_pretty(lhs, depth + 1 + (ast->cast_info.direction == L_CAST));

  if (ast->cast_info.direction == R_CAST) print_cast(ast->cast_info, depth);
  ast_print_pretty(rhs, depth + 1 + (ast->cast_info.direction == R_CAST));
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
      li->text, beg, end, op,
      symbol_canonical_type_from_enum(lhs->cast_info.data_type),
      symbol_canonical_type_from_enum(rhs->cast_info.data_type));
  ++errors_count;
}

static bool is_rel_equality(char *op) { return (*op == '!' || *op == '='); }

static void handle_mismatch_comparison(AST *lhs, AST *rhs) {
  Cursor beg = cursor_init_yyloc_between(lhs->rule_pos, rhs->rule_pos);
  Cursor end = {.col = beg.col + 1, .line = beg.line};
  LineInfo *li = list_peek(&lines, beg.line - 1);
  if (!can_compare(lhs->cast_info.data_type, rhs->cast_info.data_type)) {
    CIPL_PERROR_CURSOR_RANGE(
        "comparison between " BGRN "'%s'" RESET " and " BGRN "'%s'" RESET "\n",
        li->text, beg, end,
        symbol_canonical_type_from_enum(lhs->cast_info.data_type),
        symbol_canonical_type_from_enum(rhs->cast_info.data_type));
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
  if (lhs->cast_info.data_type < SYM_PTR ||
      rhs->cast_info.data_type < SYM_PTR) {
    CIPL_PERROR_CURSOR(
        BGRN "'%s'" RESET " used in arithmetic\n", li->text, c,
        symbol_canonical_type_from_enum(lhs->cast_info.data_type > SYM_REAL
                                            ? lhs->cast_info.data_type
                                            : rhs->cast_info.data_type));
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
  AST_TRAVERSE(root, AST_USER_FUNC, {
    AST *key = list_peek(&__AST__->children, 0);
    if (!strcmp(key->value.symref->symbol->name,
                fn->value.symref->symbol->name)) {
      func_decl = __AST__;
      __FOUND__ = 1;
    }
  });
  AST *func_decl_params = list_peek(&func_decl->children, 1);
  ParamsAST *params_l = func_decl_params->value.params;
  if (params_l->size > 1 || !params_l->size) {
    CIPL_PERROR_CURSOR_RANGE(
        "function " BBLU "'%s'" RESET " should have arity 1\n", li->text, beg,
        end, fn->value.symref->symbol->name);
    ++errors_count;
  } else if (list_type > SYM_PTR) {
    AST *param = list_peek(&params_l->value, 0);
    if (!can_assign(param->cast_info.data_type, list_type - SYM_PTR)) {
      CIPL_PERROR_CURSOR_RANGE(
          "expected " BGRN "'%s'" RESET " as argument but list is of type " BGRN
          "'%s'" RESET "\n",
          li->text, beg, end,
          symbol_canonical_type_from_enum(param->cast_info.data_type),
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
    handle_mapfil_mismatch_params(lhs, rhs->cast_info.data_type);
  }

  if (lhs->cast_info.data_type > SYM_PTR) {
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
    if (!lhs_sym->kind == FUNC || rhs->cast_info.data_type < SYM_PTR) {
      if (lhs_sym->kind == FUNC) {
        char *func_str = symbol_canonical_type_function(lhs);
        sprintf(tmp, "%s", func_str);
        free(func_str);
      } else {
        sprintf(tmp, "%s",
                symbol_canonical_type_from_enum(lhs->cast_info.data_type));
      }
      CIPL_PERROR_CURSOR_RANGE(
          "invalid operands to binary " WHT "'%s'" RESET " (have " BGRN
          "'%s'" RESET " and " BGRN "'%s'" RESET ")\n",
          li->text, beg, end, op, tmp,
          symbol_canonical_type_from_enum(rhs->cast_info.data_type));
      ++errors_count;
    }
  }
}

static void handle_mismatch_cons(AST *lhs, AST *rhs, char *op) {
  invalid_bin_op(lhs, rhs, op);
}

CastInfo ast_binop_type_check(AST *ast) {
  BinOpAST *binop_ast = ast->value.binop;
  AST *lhs = list_peek(&ast->children, 0), *rhs = list_peek(&ast->children, 1);
  ast_validate_types(lhs);
  ast_validate_types(rhs);

  CastInfo base_cast_info =
      strcmp(binop_ast->op, ">>") && strcmp(binop_ast->op, "<<")
          ? cast_info_binop(lhs->cast_info.data_type, rhs->cast_info.data_type)
          : cast_info_none();

  switch (binop_ast->op[0]) {
    case ':':
      if (!can_cons_list(lhs->cast_info.data_type, rhs->cast_info.data_type)) {
        handle_mismatch_cons(lhs, rhs, binop_ast->op);
      }
      return cast_info_with_type(
          base_cast_info,
          rhs->cast_info.data_type == SYM_PTR
              ? MAX((MIN(lhs->cast_info.data_type, SYM_PTR) + SYM_PTR) % 6,
                    SYM_PTR)
              : MAX(rhs->cast_info.data_type, SYM_PTR));
    case '<':
    case '>': {
      if (is_relop(binop_ast->op)) {
        if (!can_compare(lhs->cast_info.data_type, rhs->cast_info.data_type)) {
          handle_mismatch_comparison(lhs, rhs);
        } else if (lhs->type == AST_BIN_OP || rhs->type == AST_BIN_OP) {
          handle_comparison_chain(lhs, rhs);
        }
        return cast_info_with_type(base_cast_info, SYM_INT);
      } else {
        handle_mismatch_mapfil(lhs, rhs, binop_ast->op);
        return cast_info_with_type(
            base_cast_info,
            *binop_ast->op == '<'
                ? MAX(rhs->cast_info.data_type, SYM_PTR)
                : MAX((MIN(lhs->cast_info.data_type, SYM_PTR) + SYM_PTR) % 6,
                      SYM_PTR));
      }
    } break;
    case '&':
    case '|':
      // anything can be part of a boolean expression and it returns a SYM_INT
      return cast_info_with_type(base_cast_info, SYM_INT);
    default: {
      if (is_rel_equality(binop_ast->op)) {
        if (!can_compare(lhs->cast_info.data_type, rhs->cast_info.data_type)) {
          handle_mismatch_equality(lhs, rhs, binop_ast->op);
        }
        return cast_info_with_type(base_cast_info, SYM_INT);
      } else if (!can_arith(lhs->cast_info.data_type,
                            rhs->cast_info.data_type)) {
        handle_mismatch_arithmetic(lhs, rhs, binop_ast->op);
      } else if (*binop_ast->op == '/' && rhs->type == AST_NUMBER) {
        handle_div_by_zero(lhs, rhs);
      }
    }
  }

  return cast_info_with_type(
      base_cast_info, MAX(lhs->cast_info.data_type, rhs->cast_info.data_type));
}

static void arith_gen_code(AST *ast, char *op, FILE *out) {
  int temp = current_context->t9n->temp;

  fprintf(out, "pop $%d\n\n", temp + 1);
  fprintf(out, "pop $%d\n\n", temp);

  fprintf(out, "param $%d\n", temp);
  fprintf(out, "call get_var_val, 1\n");
  fprintf(out, "pop $%d\n\n", temp + 2);
  fprintf(out, "param $%d\n", temp + 1);
  fprintf(out, "call get_var_val, 1\n");
  fprintf(out, "pop $%d\n\n", temp + 3);

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
  t9n_alloc_from_other_value(temp + 2, temp + 3, ast->cast_info.data_type, VAR,
                             out);
}

static void rel_gen_code(char *op, FILE *out) {
  int temp = current_context->t9n->temp;

  fprintf(out, "pop $%d\n\n", temp + 1);
  fprintf(out, "pop $%d\n\n", temp);

  fprintf(out, "param $%d\n", temp);
  fprintf(out, "call get_var_val, 1\n");
  fprintf(out, "pop $%d\n\n", temp + 2);
  fprintf(out, "param $%d\n", temp + 1);
  fprintf(out, "call get_var_val, 1\n");
  fprintf(out, "pop $%d\n\n", temp + 3);

  switch (op[0]) {
    case '>': {
      const int oplen = strlen(op);
      fprintf(out, "%s $%d, $%d, $%d\n", oplen == 1 ? "sleq" : "slt", temp + 4,
              temp + 2 + (oplen == 1), temp + 3 - (oplen == 1));
      if (oplen == 1) {
        fprintf(out, "seq $%d, $%d, $%d\n", temp + 5, temp + 3, temp + 2);
        fprintf(out, "not $%d, $%d\n", temp + 5, temp + 5);
        fprintf(out, "and $%d, $%d, $%d\n\n", temp + 3, temp + 4, temp + 5);
      } else {
        fprintf(out, "not $%d, $%d\n\n", temp + 3, temp + 4);
      }
      fprintf(out, "param $%d\n", temp + 3);
      fprintf(out, "call set_bool, 1\n");
      fprintf(out, "pop $%d\n\n", temp + 3);
      t9n_alloc_from_other_value(temp + 2, temp + 3, SYM_INT, VAR, out);
      return;
    };
    case '<':
      fprintf(out, "%s", strlen(op) == 1 ? "slt" : "sleq");
      break;
    case '=':
      fprintf(out, "seq");
      break;
    case '!':
      fprintf(out, "seq $%d, $%d, $%d\n", temp + 3, temp + 2, temp + 3);
      fprintf(out, "not $%d, $%d\n", temp + 3, temp + 3);
      fprintf(out, "param $%d\n", temp + 3);
      fprintf(out, "call set_bool, 1\n");
      fprintf(out, "pop $%d\n\n", temp + 3);
      t9n_alloc_from_other_value(temp + 2, temp + 3, SYM_INT, VAR, out);
      return;
  }

  fprintf(out, " $%d, $%d, $%d\n\n", temp + 3, temp + 2, temp + 3);
  fprintf(out, "param $%d\n", temp + 3);
  fprintf(out, "call set_bool, 1\n");
  fprintf(out, "pop $%d\n\n", temp + 3);
  t9n_alloc_from_other_value(temp + 2, temp + 3, SYM_INT, VAR, out);
}

static void list_cons_gen_code(FILE *out) {
  int temp = current_context->t9n->temp;
  fprintf(out, "pop $%d\n\n", temp);
  fprintf(out, "pop $%d\n\n", temp + 1);
  fprintf(out, "param $%d\n", temp);
  fprintf(out, "param $%d\n", temp + 1);
  fprintf(out, "call list_insert, 2\n");
  fprintf(out, "pop $%d\n", temp + 2);
}

static AST *get_mapfil_param_type(AST *fn_symref) {
  AST *func_decl;
  AST_FIND_NODE(
      root, AST_USER_FUNC,
      {
        if (__AST__) {
          AST *key = list_peek(&__AST__->children, 0);
          if (current_context->name && key &&
              !strcmp(key->value.symref->symbol->name,
                      fn_symref->value.symref->symbol->name)) {
            func_decl = __AST__;
            __FOUND__ = 1;
          }
        }
      },
      { return NULL; });
  AST *params = list_peek(&func_decl->children, 1);
  return list_peek(&params->value.params->value, 0);
}

static int push_globals_for_mapfil(Symbol *fn_name, FILE *out) {
  int qtd_globals = 0;
  AST_TRAVERSE_UNTIL(
      root, AST_DECLARATION,
      {
        if (__AST__->type == AST_USER_FUNC) {
          AST *key = list_peek(&__AST__->children, 0);
          if (!strcmp(key->value.symref->symbol->name, fn_name->name)) {
            __FOUND__ = true;
          }
        }
      },
      {
        AST *var_ast = list_peek(&__AST__->children, 0);
        Symbol *var_sym = var_ast->value.symref->symbol;
        fprintf(out, "push $%d\n", var_sym->temp);
        ++qtd_globals;
      });
  return qtd_globals;
}

static void mapfil_gen_code(AST *ast, AST *lhs, AST *rhs, char *op, FILE *out) {
  AST *lhs_param = get_mapfil_param_type(lhs);
  CastInfo ctx_cast_info = cast_info_mapfil(lhs_param->cast_info.data_type,
                                            rhs->cast_info.data_type);
  switch (*op) {
    case '>': {
      LIST_MAPFIL_TEMPLATE_GEN_CODE(
          current_context,
          {
            fprintf(out, "mov $%d[0], %d\n", __TEMP__ + 2,
                    ast->cast_info.data_type);
          },
          {
            fprintf(out, "push $%d\n", __TEMP__ + 4);
            cast_gen_code(ctx_cast_info, __TEMP__ + 4, out);
            fprintf(out, "pop $%d\n", __TEMP__ + 4);
            fprintf(out, "param $%d\n", __TEMP__ + 4);
            fprintf(
                out, "call func_%s, %d\n", lhs->value.symref->symbol->name,
                1 + push_globals_for_mapfil(lhs->value.symref->symbol, out));
          });
    } break;
    case '<': {
      LIST_MAPFIL_TEMPLATE_GEN_CODE(
          current_context,
          {
            fprintf(out, "mov $%d[0], %d\n", __TEMP__ + 2,
                    ast->cast_info.data_type);
          },
          {
            fprintf(out, "push $%d\n", __TEMP__ + 4);
            cast_gen_code(ctx_cast_info, __TEMP__ + 4, out);
            fprintf(out, "pop $%d\n", __TEMP__ + 4);
            fprintf(out, "param $%d\n", __TEMP__ + 4);
            fprintf(
                out, "call func_%s, %d\n", lhs->value.symref->symbol->name,
                1 + push_globals_for_mapfil(lhs->value.symref->symbol, out));
            fprintf(out, "pop $%d\n", __TEMP__ + 6);
            fprintf(out, "param $%d\n", __TEMP__ + 6);
            fprintf(out, "call get_var_val, 1\n");
            fprintf(out, "pop $%d\n", __TEMP__ + 6);
            fprintf(out, "param $%d\n", __TEMP__ + 6);
            fprintf(out, "call set_bool, 1\n");
            fprintf(out, "pop $%d\n", __TEMP__ + 6);
            fprintf(out, "brz func_%s_list_for_each_L%d_CONTINUE, $%d\n",
                    current_context->name, current_context->t9n->label,
                    __TEMP__ + 6);
            fprintf(out, "push $%d\n", __TEMP__ + 4);
          });
    } break;
  }
}

void bool_gen_code(AST *ast, AST *lhs, AST *rhs, char *op, FILE *out) {
  int tmp = current_context->t9n->temp;

  ast_gen_code(lhs, out);
  if (ast->cast_info.direction == L_CAST)
    cast_gen_code(ast->cast_info, tmp, out);

  fprintf(out, "pop $%d\n", tmp);
  fprintf(out, "param $%d\n", tmp);
  fprintf(out, "call get_var_val, 1\n");
  fprintf(out, "pop $%d\n", tmp + 1);
  fprintf(out, "param $%d\n", tmp + 1);
  fprintf(out, "call set_bool, 1\n");
  fprintf(out, "pop $%d\n", tmp + 1);
  fprintf(out, "push $%d\n\n", tmp);

  int label = current_context->t9n->label;

  fprintf(out, "%s %s_LAZY_EVAL_L%d, $%d\n", *op == '&' ? "brz" : "brnz",
          current_context->name, label, tmp + 1);

  current_context->t9n->label++;
  ast_gen_code(rhs, out);
  if (ast->cast_info.direction == R_CAST)
    cast_gen_code(ast->cast_info, current_context->t9n->temp, out);

  fprintf(out, "jump %s_LAZY_EVAL_L%d_END\n", current_context->name, label);

  fprintf(out, "%s_LAZY_EVAL_L%d:\n", current_context->name, label);
  t9n_alloc_from_constant(tmp + 1, SYM_INT,
                          (NumberValue){
                              .integer = *op != '&',
                          },
                          out);
  fprintf(out, "push $%d\n", tmp + 1);

  fprintf(out, "%s_LAZY_EVAL_L%d_END:\n", current_context->name, label);
  fprintf(out, "pop $%d\n\n", tmp + 1);
  fprintf(out, "pop $%d\n\n", tmp);

  fprintf(out, "param $%d\n", tmp);
  fprintf(out, "call get_var_val, 1\n");
  fprintf(out, "pop $%d\n", tmp + 2);
  fprintf(out, "param $%d\n", tmp + 2);
  fprintf(out, "call set_bool, 1\n");
  fprintf(out, "pop $%d\n\n", tmp + 2);

  fprintf(out, "param $%d\n", tmp + 1);
  fprintf(out, "call get_var_val, 1\n");
  fprintf(out, "pop $%d\n", tmp + 3);
  fprintf(out, "param $%d\n", tmp + 3);
  fprintf(out, "call set_bool, 1\n");
  fprintf(out, "pop $%d\n\n", tmp + 3);

  switch (*op) {
    case '&':
      fprintf(out, "and");
      break;
    case '|':
      fprintf(out, "or");
      break;
  }

  fprintf(out, " $%d, $%d, $%d\n\n", tmp + 3, tmp + 2, tmp + 3);
  fprintf(out, "param $%d\n", tmp + 3);
  fprintf(out, "call set_bool, 1\n");
  fprintf(out, "pop $%d\n\n", tmp + 3);
  t9n_alloc_from_other_value(tmp + 2, tmp + 3, SYM_INT, VAR, out);
}

void ast_binop_gen_code(AST *ast, FILE *out) {
  BinOpAST *binop_ast = ast->value.binop;
  AST *lhs = list_peek(&ast->children, 0), *rhs = list_peek(&ast->children, 1);

  if (*binop_ast->op != '&' && *binop_ast->op != '|') {
    ast_gen_code(lhs, out);
    if (ast->cast_info.direction == L_CAST)
      cast_gen_code(ast->cast_info, current_context->t9n->temp, out);

    ast_gen_code(rhs, out);
    if (ast->cast_info.direction == R_CAST)
      cast_gen_code(ast->cast_info, current_context->t9n->temp, out);
  }

  switch (binop_ast->op[0]) {
    case ':':
      list_cons_gen_code(out);
      break;
    case '<':
    case '>':
      is_relop(binop_ast->op)
          ? rel_gen_code(binop_ast->op, out)
          : mapfil_gen_code(ast, lhs, rhs, binop_ast->op, out);
      break;
    case '=':
    case '!':
      rel_gen_code(binop_ast->op, out);
      break;
    case '&':
    case '|':
      bool_gen_code(ast, lhs, rhs, binop_ast->op, out);
      break;
    default:
      arith_gen_code(ast, binop_ast->op, out);
  }

  fprintf(out, "push $%d\n\n", current_context->t9n->temp + 2);
}
