#include "data-structures/ast/types/uni-op.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/io.h"

AST *ast_uniop_init(YYLTYPE rule_pos, char *op, AST *l) {
  UniOpAST *ast = calloc(1, sizeof(UniOpAST));
  ast->op = strdup(op);
  return ast_cast(AST_UNI_OP, rule_pos, 1, ast, l);
}

void ast_uniop_free(AST *ast) {
  UniOpAST *uniop_ast = ast->value.uniop;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(uniop_ast->op);
  free(uniop_ast);
}

SymbolValues ast_uniop_eval(AST *ast) { return (SymbolValues){.integer = 0}; }

void ast_uniop_print(AST *ast) {
  UniOpAST *uniop_ast = ast->value.uniop;
  printf("uni_op: { op: '%s', ", uniop_ast->op);
  ast_print(ast->children->data);
  printf("}");
}

void ast_uniop_print_pretty(AST *ast, int depth) {
  AST *rhs = list_peek(&ast->children, 0);
  UniOpAST *uniop_ast = ast->value.uniop;

  printf("%*.s" BMAG "<unary-op>" RESET "\n", depth * 4, "");
  printf("%*.s" WHT "%s" RESET "\n", (depth + 1) * 4, "", uniop_ast->op);

  ast_print_pretty(rhs, depth + 1);
}

static void invalid_uni_op(AST *rhs, char *op) {
  Cursor beg = cursor_init_yylloc_begin(rhs->rule_pos);
  Cursor end = cursor_init_yylloc_end(rhs->rule_pos);
  LineInfo *li = list_peek(&lines, beg.line - 1);
  CIPL_PERROR_CURSOR_RANGE(
      "invalid operands to unary " WHT "'%s'" RESET " (have " BGRN "'%s'" RESET
      ")\n",
      li->text, beg, end, op,
      symbol_canonical_type_from_enum(rhs->cast_info.data_type));
  ++errors_count;
}

static void handle_mismatch_tailop_type(AST *rhs, char *op) {
  invalid_uni_op(rhs, op);
}

static void handle_mismatch_sign_change(AST *rhs, char *op) {
  invalid_uni_op(rhs, op);
}

CastInfo ast_uniop_type_check(AST *ast) {
  AST *rhs = list_peek(&ast->children, 0);
  UniOpAST *uniop_ast = ast->value.uniop;

  ast_validate_types(rhs);

  CastInfo base_cast = cast_info_none();

  switch (*uniop_ast->op) {
    case '!':
      if (rhs->cast_info.data_type == SYM_PTR) {
        handle_mismatch_tailop_type(rhs, uniop_ast->op);
        return base_cast;
      }
      return cast_info_with_type(base_cast, rhs->cast_info.data_type < SYM_PTR
                                                ? SYM_INT
                                                : rhs->cast_info.data_type);
    case '?':
    case '%':
      if (rhs->cast_info.data_type <= SYM_PTR) {
        handle_mismatch_tailop_type(rhs, uniop_ast->op);
        return base_cast;
      }
      return cast_info_with_type(base_cast,
                                 *uniop_ast->op == '?'
                                     ? (rhs->cast_info.data_type - SYM_PTR)
                                     : rhs->cast_info.data_type);
    case '+':
    case '-':
      if (rhs->cast_info.data_type >= SYM_PTR) {
        handle_mismatch_sign_change(rhs, uniop_ast->op);
        return base_cast;
      }
  }

  return cast_info_with_type(base_cast, rhs->cast_info.data_type);
}
