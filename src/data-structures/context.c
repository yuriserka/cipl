#include "data-structures/context.h"

#include <stdlib.h>

#include "data-structures/scope.h"

Context *context_init() {
  Context *ctx = calloc(1, sizeof(Context));
  ctx->scopes = NULL;
  return ctx;
}

Symbol *context_has_symbol(Context *ctx, char *sym_name) {
  LIST_FOR_EACH_REVERSE(ctx->scopes, {
    Scope *scope = __MAP_IT__->data;
    Symbol *sym_entry = symbol_table_lookup(scope->symbol_table, sym_name);
    if (sym_entry) return sym_entry;
  });
  return NULL;
}

void context_free(Context *ctx) {
  LIST_FREE_REVERSE(ctx->scopes, { scope_free(__MAP_IT__->data); });
}
