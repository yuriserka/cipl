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
  Scope * child = scope_init();
  child->index = curr->index + 1;
  stack_push(&scopes, child);
  return child;
}

Symbol *scope_lookup(Scope *scope, char *sym_name) {
  StackNode *it = scopes;
  while (it) {
    StackNode *tmp = it->next;
    Symbol *sym_entry = symbol_table_lookup(scope->symbol_table, sym_name);
    if (!sym_entry->name)
      symbol_update(sym_entry, sym_name, scope->index, cursor);
    return sym_entry;
    it = tmp;
  }

  CIPL_PERROR("'%s' undeclared (first use in this function)\n", sym_name);

  return NULL;
}
