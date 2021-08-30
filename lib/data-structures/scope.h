#pragma once

#include "data-structures/stack.h"
#include "data-structures/symbol-table/symbol-table.h"

typedef struct cipl_scope {
  int index;
  SymbolTable symbol_table;
} Scope;

Scope *scope_init();
Scope *scope_init_copy(Scope *other);
void scope_free(Scope *scope);

Scope *scope_add(StackNode **scopes, Scope *curr);
Symbol *scope_lookup(StackNode *scopes, char *sym_name);
void scope_print(Scope *scope);
