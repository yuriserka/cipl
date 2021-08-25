#pragma once

#include "data-structures/list.h"

typedef struct cipl_ast_params {
  ListNode *value;
} ParamsAST;

#include "data-structures/ast/ast.h"

void ast_params_free(AST *ast);
AST *ast_params_init(ListNode *params);
double ast_params_eval(AST *ast);
void ast_params_print(AST *ast);
