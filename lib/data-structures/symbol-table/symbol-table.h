#pragma once

#define NHASH 9997

#include "data-structures/symbol-table/symbol.h"

typedef Symbol SymbolTable[NHASH];

Symbol *symbol_table_lookup(SymbolTable symbol_table, char *sym_name);
void symbol_table_delete(SymbolTable symbol_table, char *sym_name);
void symbol_table_free(SymbolTable symbol_table);
void symbol_table_print(SymbolTable symbol_table);
Symbol *symbol_table_get_valid_entry(SymbolTable symbol_table, char *sym_name);