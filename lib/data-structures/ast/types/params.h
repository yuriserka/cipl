#pragma once

#include "data-structures/list.h"

typedef struct cipl_ast_params {
  ListNode *value;
  unsigned int size;
} ParamsAST;

#include "data-structures/ast/ast.h"

void ast_params_free(AST *ast);
AST *ast_params_init(ListNode *params);
SymbolValues ast_params_eval(AST *ast);
void ast_params_print(AST *ast);
void ast_params_print_pretty(AST *ast, int depth);
