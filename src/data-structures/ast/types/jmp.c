#include "data-structures/ast/types/jmp.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/context.h"
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

  AST *curr_func = get_curr_func_value_type();

  bool valid_cast = curr_func && stmt && curr_func->value_type < SYM_PTR &&
                    stmt->value_type < SYM_PTR &&
                    should_cast(curr_func->value_type, stmt->value_type);

  if (valid_cast)
    printf("%*.s" BMAG "<%s>" RESET "\n", (depth + 1) * 4, "",
           curr_func->value_type < stmt->value_type ? "fltoint" : "inttofl");

  ast_print_pretty(stmt, depth + 1 + valid_cast);
}

static void handle_mismatch_return_type(AST *fname, AST *invalid_expr) {
  Cursor beg = cursor_init_yylloc_begin(invalid_expr->rule_pos);
  Cursor end = cursor_init_yylloc_end(invalid_expr->rule_pos);
  LineInfo *li = list_peek(&lines, beg.line - 1);
  CIPL_PERROR_CURSOR_RANGE(
      "incompatible types when returning type " BGRN "'%s'" RESET " but " BGRN
      "'%s'" RESET " was expected\n",
      li->text, beg, end,
      symbol_canonical_type_from_enum(invalid_expr->value_type),
      symbol_canonical_type_from_enum(fname->value_type));
  ++errors_count;
}

SymbolTypes ast_jmp_type_check(AST *ast) {
  AST *stmt = list_peek(&ast->children, 0);
  AST *curr_func = get_curr_func_value_type();

  ast_validate_types(stmt);

  if (!can_assign(curr_func->value_type, stmt->value_type)) {
    handle_mismatch_return_type(curr_func, stmt);
  }

  return stmt->value_type;
}

void ast_jmp_gen_code(AST *ast, FILE *out) {
  AST *stmt = list_peek(&ast->children, 0);
  ast_gen_code(stmt, out);
  fprintf(out, "return $%d\n", current_context->t9n->temp - 1);
}