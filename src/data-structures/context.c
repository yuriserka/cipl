#include "data-structures/context.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "data-structures/scope.h"

Context *context_init(char *name) {
  Context *ctx = calloc(1, sizeof(Context));
  Context *global_ctx_defined = list_peek(&contexts, 0);
  ctx->current_scope = 0;

  if (global_ctx_defined) {
    ctx->scopes =
        list_node_init(scope_init_copy(global_ctx_defined->scopes->data));
    context_push_scope(ctx);
  } else {
    ctx->scopes = list_node_init(scope_init());
  }
  ctx->name = strdup(name);
  return ctx;
}

Symbol *context_has_symbol(Context *ctx, Symbol *sym) {
  LIST_FOR_EACH_REVERSE(ctx->scopes, {
    Scope *scope = __IT__->data;
    Symbol *sym_entry = symbol_table_lookup(scope->symbol_table, sym->name);
    if (sym_entry) return sym_entry;
  });
  return NULL;
}

void context_free(Context *ctx) {
  LIST_FREE_REVERSE(ctx->scopes, { scope_free(__IT__->data); });
  free(ctx->name);
  free(ctx);
}

Scope *context_push_scope(Context *ctx) {
  Scope *scope =
      scope_add(&ctx->scopes, stack_peek(&ctx->scopes));
  ctx->current_scope = scope->index;
  return scope;
}

Symbol *context_declare_variable(Context *ctx, SymbolRefAST *symref) {
  Scope *current_scope = stack_peek(&ctx->scopes);
  Symbol *entry =
      symbol_table_get_valid_entry(current_scope->symbol_table, symref);
  symbol_update(entry, symref->symbol->name, current_scope->index, ctx->name,
                symref->symbol->def_pos);
  return entry;
}

Symbol *context_declare_function(Context *ctx, SymbolRefAST *symref) {
  Scope *current_scope = stack_peek(&ctx->scopes);
  Symbol *entry =
      symbol_table_get_valid_entry(current_scope->symbol_table, symref);
  symbol_update(entry, symref->symbol->name, current_scope->index, ctx->name,
                symref->symbol->def_pos);
  return entry;
}

void context_print(Context *ctx) {
  printf("{ name: %s, scopes: [ ", ctx->name);
  LIST_FOR_EACH_REVERSE(ctx->scopes, {
    Scope *s = __IT__->data;
    printf("{ index: %d, symbol_table_entries: [ ", s->index);
    symbol_table_print(s->symbol_table);
    printf("], }, ");
  });
  printf("], }, ");
}