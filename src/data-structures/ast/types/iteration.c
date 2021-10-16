#include "data-structures/ast/types/iteration.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/context.h"
#include "utils/io.h"

AST *ast_iter_init(YYLTYPE rule_pos, Context *context, AST *start,
                   AST *while_cond, AST *final, AST *stmts) {
  IterationAST *ast = calloc(1, sizeof(IterationAST));
  ast->context = context;
  return ast_cast(AST_ITER, rule_pos, 4, ast, start, while_cond, final, stmts);
}

void ast_iter_free(AST *ast) {
  IterationAST *iter_ast = ast->value.iteration;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(iter_ast);
}

SymbolValues ast_iter_eval(AST *ast) { return (SymbolValues){.integer = 0}; }

void ast_iter_print(AST *ast) {
  AST *b4_all = list_peek(&ast->children, 0);
  AST *b4_each = list_peek(&ast->children, 1);
  AST *after_each = list_peek(&ast->children, 2);
  AST *stmts = list_peek(&ast->children, 3);
  printf("for: { ");
  ast_child_print_aux_label("start", b4_all);
  ast_child_print_aux_label("while_cond", b4_each);
  ast_child_print_aux_label("after_each", after_each);
  ast_child_print_aux_label("block_items", stmts);
  printf("}");
}

void ast_iter_print_pretty(AST *ast, int depth) {
  AST *b4_all = list_peek(&ast->children, 0);
  AST *b4_each = list_peek(&ast->children, 1);
  AST *after_each = list_peek(&ast->children, 2);
  AST *stmts = list_peek(&ast->children, 3);

  printf("%*.s" BMAG "<iteration-statement>" RESET "\n", depth * 4, "");

  printf("%*.s" BMAG "<before-all>" RESET "\n", (depth + 1) * 4, "");
  ast_print_pretty(b4_all, depth + 2);

  printf("%*.s" BMAG "<before-each>" RESET "\n", (depth + 1) * 4, "");
  ast_print_pretty(b4_each, depth + 2);

  printf("%*.s" BMAG "<after-all>" RESET "\n", (depth + 1) * 4, "");
  ast_print_pretty(after_each, depth + 2);

  printf("%*.s" BMAG "<statements>" RESET "\n", (depth + 1) * 4, "");
  ast_print_pretty(stmts, depth + 2);
}

CastInfo ast_iter_type_check(AST *ast) {
  AST *b4_all = list_peek(&ast->children, 0);
  AST *b4_each = list_peek(&ast->children, 1);
  AST *after_each = list_peek(&ast->children, 2);
  AST *stmts = list_peek(&ast->children, 3);

  ast_validate_types(b4_all);
  ast_validate_types(b4_each);
  ast_validate_types(after_each);
  ast_validate_types(stmts);

  return cast_info_none();
}
