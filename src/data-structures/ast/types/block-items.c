#include "data-structures/ast/types/block-items.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils/io.h"

AST *ast_blockitems_init(ListNode *blockitems) {
  BlockItemListAST *ast = calloc(1, sizeof(BlockItemListAST));
  ast->value = blockitems;
  return ast_cast(AST_BLOCK_ITEM_LIST, 0, ast);
}

void ast_blockitems_free(AST *ast) {
  BlockItemListAST *blockitems_ast = ast->value.blockitems;
  LIST_FREE(blockitems_ast->value, { ast_free(__IT__->data); });
  free(blockitems_ast);
}

double ast_blockitems_eval(AST *ast) { return 0; }

void ast_blockitems_print(AST *ast) {
  BlockItemListAST *blockitems_ast = ast->value.blockitems;
  printf("block_items: { ");
  LIST_FOR_EACH(blockitems_ast->value, { ast_print(__IT__->data); });
  printf("}");
}

void ast_blockitems_print_pretty(AST *ast, int depth) {
  BlockItemListAST *blockitems_ast = ast->value.blockitems;

  for (int i = depth; i > 0; --i) printf("\t");

  CIPL_PRINTF_COLOR(BMAG, "<code-block>\n");
  LIST_FOR_EACH(blockitems_ast->value,
                { ast_print_pretty(__IT__->data, depth + 1); });
}
