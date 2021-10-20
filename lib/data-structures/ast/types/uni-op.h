#pragma once

typedef struct cipl_ast_uniop {
  char *op;
} UniOpAST;

#include "data-structures/ast/ast.h"

void ast_uniop_free(AST *ast);
AST *ast_uniop_init(YYLTYPE rule_pos, char *op, AST *l);
SymbolValues ast_uniop_eval(AST *ast);
void ast_uniop_print(AST *ast);
void ast_uniop_print_pretty(AST *ast, int depth);

CastInfo ast_uniop_type_check(AST *ast);
void ast_uniop_gen_code(AST *ast, FILE *out);
