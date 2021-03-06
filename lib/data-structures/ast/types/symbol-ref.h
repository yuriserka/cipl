#pragma once

typedef struct cipl_ast_symbol_ref SymbolRefAST;

#include "data-structures/symbol-table/symbol.h"

struct cipl_ast_symbol_ref {
  Symbol *symbol;
};

#include "data-structures/ast/ast.h"

void ast_symref_free(AST *ast);
AST *ast_symref_init(YYLTYPE rule_pos, Symbol *symbol);
SymbolValues ast_symref_eval(AST *ast);
void ast_symref_print(AST *ast);
void ast_symref_print_pretty(AST *ast, int depth);

CastInfo ast_symref_type_check(AST *ast);
void ast_symref_gen_code(AST *ast, FILE *out);
