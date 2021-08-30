#include "data-structures/ast/types/iteration.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/context.h"

AST *ast_iter_init(Context *context, AST *start, AST *while_cond, AST *final,
                   AST *stmts) {
  IterationAST *ast = calloc(1, sizeof(IterationAST));
  ast->context = context;
  return ast_cast(AST_ITER, 4, ast, start, while_cond, final, stmts);
}

void ast_iter_free(AST *ast) {
  IterationAST *iter_ast = ast->value.iteration;
  list_free(ast->children, ast_child_free);
  free(iter_ast);
}

double ast_iter_eval(AST *ast) { return 0; }

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