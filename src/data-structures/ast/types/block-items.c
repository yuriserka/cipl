#include "data-structures/ast/types/block-items.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils/io.h"

AST *ast_blockitems_init(YYLTYPE rule_pos, ListNode *blockitems) {
  BlockItemListAST *ast = calloc(1, sizeof(BlockItemListAST));
  ast->value = blockitems;
  return ast_cast(AST_BLOCK_ITEM_LIST, rule_pos, 0, ast);
}

void ast_blockitems_free(AST *ast) {
  BlockItemListAST *blockitems_ast = ast->value.blockitems;
  LIST_FREE(blockitems_ast->value, { ast_free(__IT__->data); });
  free(blockitems_ast);
}

SymbolValues ast_blockitems_eval(AST *ast) {
  return (SymbolValues){.integer = 0};
}

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

SymbolTypes ast_blockitems_type_check(AST *ast) {
  BlockItemListAST *blockitems_ast = ast->value.blockitems;
  LIST_FOR_EACH(blockitems_ast->value, { ast_validate_types(__IT__->data); });

  AST *possible_return = list_peek_last(&blockitems_ast->value);
  if (possible_return->type != AST_JMP) {
    return SYM_INVALID;
  }

  return ast_validate_types(possible_return);
}