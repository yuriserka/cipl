#pragma once

typedef struct cipl_ast_jmp {
  char dummy;
} JumpAST;

#include "data-structures/ast/ast.h"

void ast_jmp_free(AST *ast);
AST *ast_jmp_init(YYLTYPE rule_pos, AST *stmt);
SymbolValues ast_jmp_eval(AST *ast);
void ast_jmp_print(AST *ast);
void ast_jmp_print_pretty(AST *ast, int depth);
void ast_jmp_gen_code(AST *ast, FILE *out);

CastInfo ast_jmp_type_check(AST *ast);
