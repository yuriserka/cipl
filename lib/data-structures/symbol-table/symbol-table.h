#pragma once

#define NHASH 9997

#include "data-structures/list.h"
#include "data-structures/symbol-table/symbol.h"

typedef struct {
  ListNode *symbols;
} SymbolTable;

SymbolTable *symbol_table_init();
Symbol *symbol_table_lookup(SymbolTable *symbol_table, char *sym_name);
void symbol_table_free(SymbolTable *symbol_table);
void symbol_table_print(SymbolTable *symbol_table);
Symbol *symbol_table_get_valid_entry(SymbolTable *symbol_table, char *sym_name);