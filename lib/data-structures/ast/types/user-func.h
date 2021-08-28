#pragma once

typedef struct cipl_ast_userfunc UserFuncAST;

struct cipl_context;

struct cipl_ast_userfunc {
  struct cipl_context *context;
};

#include "data-structures/ast/ast.h"

void ast_userfunc_free(AST *ast);
AST *ast_userfunc_init(struct cipl_context *context, AST *declarator,
                       AST *params, AST *statements);
double ast_userfunc_eval(AST *ast);
void ast_userfunc_print(AST *ast);
