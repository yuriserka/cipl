#pragma once

typedef struct cipl_ast_symbol_ref SymbolRefAST;

#include "data-structures/symbol-table/symbol.h"

struct cipl_ast_symbol_ref {
  Symbol *symbol;
  SymbolTypes type;
};

#include "data-structures/ast/ast.h"

void ast_symref_free(AST *ast);
AST *ast_symref_init(char *type, Symbol *symbol);
double ast_symref_eval(AST *ast);
void ast_symref_print(AST *ast);

SymbolTypes symbol_type_from_str(char *type);
const char *symbol_type_from_enum(SymbolTypes type);
