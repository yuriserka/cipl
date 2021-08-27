#include "data-structures/scope.h"

#include <stdlib.h>

#include "core/globals.h"
#include "utils/io.h"

Scope *scope_init() {
  Scope *scope = calloc(1, sizeof(Scope));
  scope->index = 0;
  return scope;
}

void scope_free(Scope *scope) {
  for (int i = 0; i < NHASH; ++i) {
    Symbol *sym = &scope->symbol_table[i];
    if (sym && sym->name) {
      free(sym->name);
    }
  }
  free(scope);
}

Scope *scope_add(Scope *curr) {
  Scope *child = scope_init();
  child->index = curr->index + 1;
  stack_push(&scopes, child);
  return child;
}

Symbol *scope_lookup(char *sym_name) {
  LIST_FOR_EACH_REVERSE(scopes, {
    Scope *scope = __MAP_IT__->data;
    Symbol *sym_entry = symbol_table_lookup(scope->symbol_table, sym_name);
    if (sym_entry) return sym_entry;
  });
  return NULL;
}
