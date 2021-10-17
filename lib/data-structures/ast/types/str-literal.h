#pragma once

#include "data-structures/symbol-table/symbol.h"

typedef struct cipl_ast_str {
  char *value;
  int table_entry;
} StringLiteralAST;

#include "data-structures/ast/ast.h"

void ast_str_free(AST *ast);
AST *ast_str_init(YYLTYPE rule_pos, char *value);
SymbolValues ast_str_eval(AST *ast);
void ast_str_print(AST *ast);
void ast_str_print_pretty(AST *ast, int depth);

CastInfo ast_str_type_check(AST *ast);
void ast_str_gen_code(AST *ast, FILE *out);
