#pragma once

typedef struct cipl_ast_declaration {
  char dummy;
} DeclarationAST;

#include "data-structures/ast/ast.h"
void ast_declaration_free(AST *ast);
AST *ast_declaration_init(AST *name);
double ast_declaration_eval(AST *ast);
void ast_declaration_print(AST *ast);
