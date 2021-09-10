#include "data-structures/ast/types/iteration.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/context.h"
#include "utils/io.h"

AST *ast_iter_init(Context *context, AST *start, AST *while_cond, AST *final,
                   AST *stmts) {
  IterationAST *ast = calloc(1, sizeof(IterationAST));
  ast->context = context;
  return ast_cast(AST_ITER, 4, ast, start, while_cond, final, stmts);
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

  for (int i = depth; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<iteration-statement>\n");

  for (int i = depth + 1; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<before_all>\n");
  ast_print_pretty(b4_all, depth + 2);

  for (int i = depth + 1; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<before_each>\n");
  ast_print_pretty(b4_each, depth + 2);

  for (int i = depth + 1; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<after_each>\n");
  ast_print_pretty(after_each, depth + 2);

  for (int i = depth + 1; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<statement>\n");
  ast_print_pretty(stmts, depth + 2);
}
