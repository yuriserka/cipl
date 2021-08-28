#include "data-structures/scope.h"

#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "utils/io.h"

Scope *scope_init() {
  Scope *scope = calloc(1, sizeof(Scope));
  scope->index = 0;
  return scope;
}

Scope *scope_init_copy(Scope *other) {
  Scope *scope = calloc(1, sizeof(Scope));
  scope->index = other->index;
  for (int i = 0; i < NHASH; ++i) {
    Symbol *others_sym = &other->symbol_table[i];
    if (others_sym->name) {
      scope->symbol_table[i] = (Symbol){
          .name = strdup(others_sym->name),
          .context_name = strdup(others_sym->context_name),
          .scope = others_sym->scope,
          .value = others_sym->value,
          .def_pos = others_sym->def_pos,
      };
    }
  }
  return scope;
}

void scope_free(Scope *scope) {
  for (int i = 0; i < NHASH; ++i) {
    Symbol *sym = &scope->symbol_table[i];
    if (sym && sym->name) {
      free(sym->name);
      free(sym->context_name);
    }
  }
  free(scope);
}

Scope *scope_add(StackNode **scopes, Scope *curr) {
  Scope *child = scope_init();
  child->index = curr->index + 1;
  stack_push(scopes, child);
  return child;
}

Symbol *scope_lookup(StackNode *scopes, char *sym_name) {
  LIST_FOR_EACH_REVERSE(scopes, {
    Scope *scope = __IT__->data;
    Symbol *sym_entry = symbol_table_lookup(scope->symbol_table, sym_name);
    if (sym_entry) return sym_entry;
  });
  return NULL;
}
