#pragma once

typedef struct cipl_ast_userfunc UserFuncAST;

#include "data-structures/scope.h"

struct cipl_ast_userfunc {
  Scope *scope;
};

#include "data-structures/ast/ast.h"

void ast_userfunc_free(AST *ast);
AST *ast_userfunc_init(Scope *scope, AST *declarator, AST *params);
double ast_userfunc_eval(AST *ast);
void ast_userfunc_print(AST *ast);
