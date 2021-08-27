#pragma once

#include "data-structures/stack.h"
#include "data-structures/symbol-table/symbol-table.h"

typedef struct cipl_scope {
  int index;
  SymbolTable symbol_table;
} Scope;

Scope *scope_init();
Scope *scope_add(Scope *curr);
void scope_free(Scope *scope);
Symbol *scope_lookup(char *sym_name);
