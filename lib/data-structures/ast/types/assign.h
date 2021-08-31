#pragma once

#include "data-structures/ast/types/types-def.h"

typedef struct cipl_ast_assign {
  char op;
} AssignAST;

#include "data-structures/ast/ast.h"

void ast_assign_free(AST *ast);
AST *ast_assign_init(AST *l, AST *r);
double ast_assign_eval(AST *ast);
void ast_assign_print(AST *ast);
void ast_assign_print_pretty(AST *ast, int depth);
