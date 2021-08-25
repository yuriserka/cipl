#pragma once

typedef struct cipl_ast_flow {
  char dummy;
} FlowAST;

#include "data-structures/ast/ast.h"

void ast_flow_free(AST *ast);
AST *ast_flow_init(AST *cond, AST *then_branch, AST *else_branch);
double ast_flow_eval(AST *ast);
void ast_flow_print(AST *ast);