#pragma once

#include "data-structures/symbol-table/symbol.h"

typedef struct cipl_ast_str {
  char *value;
} StringLiteralAST;

#include "data-structures/ast/ast.h"

void ast_str_free(AST *ast);
AST *ast_str_init(char *value);
double ast_str_eval(AST *ast);
void ast_str_print(AST *ast);
void ast_str_print_pretty(AST *ast, int depth);
