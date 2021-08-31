#pragma once

struct cipl_context;

typedef struct cipl_ast_func_call {
  struct cipl_context *context;
} FunctionCallAST;

#include "data-structures/ast/ast.h"

void ast_funcall_free(AST *ast);
AST *ast_funcall_init(AST *declarator, AST *args);
double ast_funcall_eval(AST *ast);
void ast_funcall_print(AST *ast);
void ast_funcall_print_pretty(AST *ast, int depth);
