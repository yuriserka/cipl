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

  printf("%*.s" BMAG "<code-block>" RESET "\n", depth * 4, "");

  LIST_FOR_EACH(blockitems_ast->value,
                { ast_print_pretty(__IT__->data, depth + 1); });
}

CastInfo ast_blockitems_type_check(AST *ast) {
  BlockItemListAST *blockitems_ast = ast->value.blockitems;
  LIST_FOR_EACH(blockitems_ast->value, { ast_validate_types(__IT__->data); });

  return cast_info_none();
}

void ast_blockitems_gen_code(AST *ast, FILE *out) {
  BlockItemListAST *blockitems_ast = ast->value.blockitems;

  LIST_FOR_EACH(blockitems_ast->value, {
    ast_gen_code(__IT__->data, out);
  });

  // try to free memory allocated for variables b4 return
  // STACK_FOR_EACH(current_context->scopes, {
  //   if (!__IT_PRNT__) break;
  //   Scope *scope = __IT__->data;
  //   LIST_FOR_EACH(scope->symbol_table->symbols, {
  //     Symbol *sym = __IT__->data;
  //     if (sym->kind == VAR) fprintf(out, "memf $%d\n", sym->temp);
  //   });
  // });
}
