#pragma once

#include "data-structures/ast/types/types-def.h"

typedef struct cipl_ast_symbol_ref SymbolRefAST;

#include "data-structures/symbol-table/symbol.h"

struct cipl_ast_symbol_ref {
  AstTypes type;
  Symbol *symbol;
};

#include "data-structures/ast/ast.h"

void ast_symref_free(AST *ast);
AST *ast_symref_init(Symbol *symbol);
double ast_symref_eval(AST *ast);
void ast_symref_print(AST *ast);
