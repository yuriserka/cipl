#include "data-structures/scope.h"

#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "utils/io.h"

Scope *scope_init() {
  Scope *scope = calloc(1, sizeof(Scope));
  scope->index = 0;
  scope->size = 0;
  scope->last_parent = 0;
  return scope;
}

Scope *scope_init_copy(Scope *other) {
  Scope *scope = calloc(1, sizeof(Scope));
  scope->index = other->index;
  scope->last_parent = other->last_parent;
  for (int i = 0; i < NHASH; ++i) {
    Symbol *others_sym = &other->symbol_table[i];
    if (others_sym->name) {
      symbol_update(&scope->symbol_table[i], others_sym->name, others_sym->type,
                    others_sym->is_fn, others_sym->scope,
                    others_sym->context_name, others_sym->def_pos);
      ++scope->size;
    }
  }
  return scope;
}

void scope_fill(Scope *dest, Scope *src) {
  for (int i = 0; i < NHASH; ++i) {
    Symbol *others_sym = &src->symbol_table[i];
    if (others_sym->name) {
      symbol_update(&dest->symbol_table[i], others_sym->name, others_sym->type,
                    others_sym->is_fn, others_sym->scope,
                    others_sym->context_name, others_sym->def_pos);
      ++dest->size;
    }
  }
}

void scope_free(Scope *scope) {
  for (int i = 0; i < NHASH; ++i) {
    Symbol *sym = &scope->symbol_table[i];
    if (sym && sym->name) {
      free(sym->name);
      --scope->size;
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

void scope_print(Scope *scope) {
  printf("{ index: %d, symbol_table_entries: [ ", scope->index);
  symbol_table_print(scope->symbol_table);
  printf("], }, ");
}
