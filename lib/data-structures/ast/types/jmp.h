#pragma once

typedef struct cipl_ast_jmp {
  char dummy;
} JumpAST;

#include "data-structures/ast/ast.h"

void ast_jmp_free(AST *ast);
AST *ast_jmp_init(AST *stmt);
double ast_jmp_eval(AST *ast);
void ast_jmp_print(AST *ast);
void ast_jmp_print_pretty(AST *ast, int depth);
