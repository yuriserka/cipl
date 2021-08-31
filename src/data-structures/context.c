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
  ctx->scopes =
      global_ctx_defined
          ? list_node_init(scope_init_copy(global_ctx_defined->scopes->data))
          : list_node_init(scope_init());
  ctx->name = strdup(name);
  return ctx;
}

Symbol *context_search_symbol_scopes(Context *ctx, Symbol *sym) {
  LIST_FOR_EACH_REVERSE(ctx->scopes, {
    Scope *scope = __IT__->data;
    Symbol *sym_entry = symbol_table_lookup(scope->symbol_table, sym->name);
    if (sym_entry) return sym_entry;
  });
  return NULL;
}

Symbol *context_has_symbol(Context *ctx, Symbol *sym) {
  Scope *scope = stack_peek(&ctx->scopes);
  return symbol_table_lookup(scope->symbol_table, sym->name);
}

void context_free(Context *ctx) {
  LIST_FREE_REVERSE(ctx->scopes, { scope_free(__IT__->data); });
  free(ctx->name);
  free(ctx);
}

Scope *context_push_scope(Context *ctx) {
  Scope *scope = scope_add(&ctx->scopes, stack_peek(&ctx->scopes));
  ctx->current_scope = scope->index;
  return scope;
}

Scope *context_pop_scope(Context *ctx) {
  --ctx->current_scope;
  return list_peek_reverse(&ctx->scopes, ctx->current_scope);
}

Symbol *context_declare_variable(Context *ctx, SymbolRefAST *symref) {
  Scope *current_scope = context_found_scope(ctx);
  Symbol *entry =
      symbol_table_get_valid_entry(current_scope->symbol_table, symref);
  symbol_update(entry, symref->symbol->name, current_scope->index, ctx->name,
                symref->symbol->def_pos);
  return entry;
}

Symbol *context_declare_function(Context *ctx, SymbolRefAST *symref) {
  Scope *current_scope = context_found_scope(ctx);
  Symbol *entry =
      symbol_table_get_valid_entry(current_scope->symbol_table, symref);
  symbol_update(entry, symref->symbol->name, current_scope->index, ctx->name,
                symref->symbol->def_pos);
  return entry;
}

void context_print(Context *ctx) {
  printf("{ name: %s, symbol_table_entries: [ ", ctx->name);
  LIST_FOR_EACH_REVERSE(ctx->scopes, {
    Scope *scope = __IT__->data;
    symbol_table_print(scope->symbol_table);
  });
  printf("], }, ");
}

Scope *context_found_scope(Context *ctx) {
  LIST_FOR_EACH_REVERSE(ctx->scopes, {
    Scope *scope = __IT__->data;
    if (scope->index == ctx->current_scope) return scope;
  });
  return NULL;
}