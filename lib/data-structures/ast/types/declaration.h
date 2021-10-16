#pragma once

typedef struct cipl_ast_declaration {
  char dummy;
} DeclarationAST;

#include "data-structures/ast/ast.h"
void ast_declaration_free(AST *ast);
AST *ast_declaration_init(YYLTYPE rule_pos, AST *name);
SymbolValues ast_declaration_eval(AST *ast);
void ast_declaration_print(AST *ast);
void ast_declaration_print_pretty(AST *ast, int depth);

CastInfo ast_declaration_type_check(AST *ast);

void ast_declaration_gen_code(AST *ast, FILE *out);
