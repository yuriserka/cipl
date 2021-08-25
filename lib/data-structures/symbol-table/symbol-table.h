#pragma once

#define NHASH 9997

#include "data-structures/symbol-table/symbol.h"

typedef Symbol SymbolTable[NHASH];

Symbol *symbol_table_lookup(SymbolTable symbol_tb, char *sym_name);
Symbol *symbol_table_insert(SymbolTable symbol_tb, char *sym_name);
void symbol_table_delete(char *sym_name);
void symbol_table_free(SymbolTable symbol_tb);
