#pragma once

struct cipl_context;

typedef struct cipl_ast_flow {
  struct cipl_context *context;
} FlowAST;

#include "data-structures/ast/ast.h"

void ast_flow_free(AST *ast);
AST *ast_flow_init(YYLTYPE rule_pos, struct cipl_context *context, AST *cond,
                   AST *then_branch, AST *else_branch);
SymbolValues ast_flow_eval(AST *ast);
void ast_flow_print(AST *ast);
void ast_flow_print_pretty(AST *ast, int depth);

CastInfo ast_flow_type_check(AST *ast);
