#pragma once

typedef struct cipl_ast_binop {
  int type;
  char op;
} BinOpAST;

#include "data-structures/ast/ast.h"

void ast_binop_free(AST *ast);
AST *ast_binop_init(char op, AST *l, AST *r);
double ast_binop_eval(AST *ast);
void ast_binop_print(AST *ast);
