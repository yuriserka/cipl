#pragma once

#include "data-structures/symbol-table/symbol-table.h"

typedef struct cipl_scope {
  int index;
  SymbolTable symbol_table;
} Scope;

Scope *scope_init();
void scope_add_child(Scope *curr, Scope *child);
void scope_free(Scope *scope);
Symbol *scope_lookup(Scope *scope, char *sym_name);
