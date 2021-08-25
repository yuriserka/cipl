#include "data-structures/scope.h"

#include <stdlib.h>

#include "core/globals.h"

Scope *scope_init() {
  Scope *scope = calloc(1, sizeof(Scope));
  scope->index = 0;
  return scope;
}

void scope_free(Scope *scope) {
  for (int i = 0; i < NHASH; ++i) {
    if (scope->symbol_table[i].name) {
      free(scope->symbol_table[i].name);
    }
  }
}

void scope_add_child(Scope *curr, Scope *child) {
  child->index = curr->index + 1;
}

Symbol *scope_lookup(Scope *scope, char *sym_name) {
  Symbol *sym_entry = symbol_table_lookup(scope->symbol_table, sym_name);
  if (!sym_entry->name) symbol_init(sym_entry, sym_name, scope->index, cursor);
  return sym_entry;
}