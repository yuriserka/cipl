#pragma once

#include "data-structures/list.h"

typedef struct cipl_ast_blockitems_list {
  ListNode *value;
} BlockItemListAST;

#include "data-structures/ast/ast.h"

void ast_blockitems_free(AST *ast);
AST *ast_blockitems_init(YYLTYPE rule_pos, ListNode *blockitems);
SymbolValues ast_blockitems_eval(AST *ast);
void ast_blockitems_print(AST *ast);
void ast_blockitems_print_pretty(AST *ast, int depth);

SymbolTypes ast_blockitems_type_check(AST *ast);
