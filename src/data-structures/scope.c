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
  scope->symbol_table = symbol_table_init();
  return scope;
}

Scope *scope_init_copy(Scope *other) {
  Scope *scope = calloc(1, sizeof(Scope));
  scope->index = other->index;
  scope->last_parent = other->last_parent;
  LIST_FOR_EACH(other->symbol_table->symbols, {
    Symbol *others_sym = __IT__->data;
    list_push(&scope->symbol_table->symbols, symbol_init_copy(others_sym));
    ++scope->size;
  });
  return scope;
}

void scope_fill(Scope *dest, Scope *src) {
  LIST_FOR_EACH(src->symbol_table->symbols, {
    Symbol *others_sym = __IT__->data;
    list_push(&dest->symbol_table->symbols, symbol_init_copy(others_sym));
    ++dest->size;
  });
}

void scope_free(Scope *scope) {
  symbol_table_free(scope->symbol_table);
  scope->size = 0;
  free(scope);
}

Scope *scope_add(StackNode **scopes, Scope *curr) {
  Scope *child = scope_init();
  child->index = curr->index + 1;
  stack_push(scopes, child);
  return child;
}

Symbol *scope_lookup(StackNode *scopes, char *sym_name) {
  STACK_FOR_EACH(scopes, {
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

void scope_print_pretty(Scope *scope, int width) {
  printf("%*.s", width * 4, "");

  CIPL_PRINTF_COLOR(UMAG, "scope %d has %d entr%s" RESET "\n", scope->index,
                    scope->size, scope->size > 1 ? "ies" : "y");

  LIST_FOR_EACH(scope->symbol_table->symbols, {
    Symbol *sym = __IT__->data;
    printf("%*.s", (width + 1) * 4, "");
    symbol_print_pretty(sym);
  });
  printf("\n");
}
