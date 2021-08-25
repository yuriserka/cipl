#pragma once

#include "data-structures/list.h"

typedef struct cipl_ast_blockitems_list {
  ListNode *value;
} BlockItemListAST;

#include "data-structures/ast/ast.h"

void ast_blockitems_free(AST *ast);
AST *ast_blockitems_init(ListNode *blockitems);
double ast_blockitems_eval(AST *ast);
void ast_blockitems_print(AST *ast);
