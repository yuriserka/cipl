#pragma once

#define NHASH 9997

#include "data-structures/symbol-table/symbol.h"

typedef Symbol SymbolTable[NHASH];

Symbol *symbol_table_lookup(SymbolTable symbol_table, char *sym_name);
void symbol_table_delete(char *sym_name);
void symbol_table_free(SymbolTable symbol_table);
void symbol_table_print(SymbolTable symbol_table);

struct cipl_ast;

Symbol *symbol_table_insert(SymbolTable symbol_table, struct cipl_ast *symref);