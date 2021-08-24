#pragma once

#include "data-structures/ast/ast.h"
#include "data-structures/symbol-table/symbol.h"

#define NHASH 9997

typedef Symbol SymbolTable[NHASH];

Symbol *symbol_table_lookup(char *sym_name);
void symbol_table_delete(char *sym_name);
