#pragma once

typedef struct cipl_ast_binop {
  char *op;
} BinOpAST;

#include "data-structures/ast/ast.h"

void ast_binop_free(AST *ast);
AST *ast_binop_init(YYLTYPE rule_pos, char *op, AST *l, AST *r);
SymbolValues ast_binop_eval(AST *ast);
void ast_binop_print(AST *ast);
void ast_binop_print_pretty(AST *ast, int depth);

CastInfo ast_binop_type_check(AST *ast);
void ast_binop_gen_code(AST *ast, FILE *out);
