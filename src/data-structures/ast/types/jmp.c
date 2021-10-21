#include "data-structures/ast/types/jmp.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/context.h"
#include "utils/casting.h"
#include "utils/io.h"

AST *ast_jmp_init(YYLTYPE rule_pos, AST *stmt) {
  JumpAST *ast = calloc(1, sizeof(JumpAST));
  return ast_cast(AST_JMP, rule_pos, 1, ast, stmt);
}

void ast_jmp_free(AST *ast) {
  JumpAST *flow_ast = ast->value.jmp;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(flow_ast);
}

SymbolValues ast_jmp_eval(AST *ast) { return (SymbolValues){.integer = 0}; }

void ast_jmp_print(AST *ast) {
  AST *stmt = list_peek(&ast->children, 0);
  printf("return: { ");
  ast_child_print_aux_label("statement", stmt);
  printf("}");
}

static AST *get_curr_func_value_type() {
  AST *func_decl;
  AST_FIND_NODE(
      root, AST_USER_FUNC,
      {
        if (__AST__) {
          AST *key = list_peek(&__AST__->children, 0);
          if (current_context->name && key &&
              !strcmp(key->value.symref->symbol->name, current_context->name)) {
            func_decl = __AST__;
            __FOUND__ = 1;
          }
        }
      },
      { return NULL; });
  return list_peek(&func_decl->children, 0);
}

void ast_jmp_print_pretty(AST *ast, int depth) {
  AST *stmt = list_peek(&ast->children, 0);
  printf("%*.s" BMAG "<return-statement>" RESET "\n", depth * 4, "");

  print_cast(ast->cast_info, depth);

  ast_print_pretty(stmt, depth + 1 + (ast->cast_info.direction == R_CAST));
}

static void handle_mismatch_return_type(AST *fname, AST *invalid_expr) {
  Cursor beg = cursor_init_yylloc_begin(invalid_expr->rule_pos);
  Cursor end = cursor_init_yylloc_end(invalid_expr->rule_pos);
  LineInfo *li = list_peek(&lines, beg.line - 1);
  CIPL_PERROR_CURSOR_RANGE(
      "incompatible types when returning type " BGRN "'%s'" RESET " but " BGRN
      "'%s'" RESET " was expected\n",
      li->text, beg, end,
      symbol_canonical_type_from_enum(invalid_expr->cast_info.data_type),
      symbol_canonical_type_from_enum(fname->cast_info.data_type));
  ++errors_count;
}

CastInfo ast_jmp_type_check(AST *ast) {
  AST *stmt = list_peek(&ast->children, 0);
  AST *curr_func = get_curr_func_value_type();

  ast_validate_types(stmt);

  if (!can_assign(curr_func->cast_info.data_type, stmt->cast_info.data_type)) {
    handle_mismatch_return_type(curr_func, stmt);
  }

  return cast_info_with_type(cast_info_assign(curr_func->cast_info.data_type,
                                              stmt->cast_info.data_type),
                             stmt->cast_info.data_type);
}

void ast_jmp_gen_code(AST *ast, FILE *out) {
  AST *stmt = list_peek(&ast->children, 0);

  ast_gen_code(stmt, out);

  cast_gen_code(ast->cast_info, current_context->t9n->temp, out);

  if (!strcmp(current_context->name, "main")) {
    fprintf(out, "jump EOF\n");
  } else {
    fprintf(out, "pop $%d\n", current_context->t9n->temp);
    fprintf(out, "return $%d\n", current_context->t9n->temp);
  }
}