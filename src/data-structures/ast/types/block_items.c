#include "data-structures/ast/types/block_items.h"

#include <stdio.h>
#include <stdlib.h>

AST *ast_blockitems_init(ListNode *blockitems) {
  BlockItemListAST *ast = calloc(1, sizeof(BlockItemListAST));
  ast->value = blockitems;
  return ast_cast(AST_BLOCK_ITEM_LIST, 0, ast);
}

void ast_blockitems_free(AST *ast) {
  BlockItemListAST *blockitems_ast = ast->value.blockitems;
  list_free(blockitems_ast->value, ast_child_free);
  free(blockitems_ast);
}

double ast_blockitems_eval(AST *ast) { return 0; }

void ast_blockitems_print(AST *ast) {
  BlockItemListAST *blockitems_ast = ast->value.blockitems;
  printf("block_items: { ");
  list_for_each(blockitems_ast->value, ast_child_print);
  printf("}");
}