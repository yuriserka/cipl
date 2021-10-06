#include "data-structures/context.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "data-structures/scope.h"
#include "utils/io.h"

Context *context_init(char *name) {
  Context *ctx = calloc(1, sizeof(Context));
  ctx->current_scope = 0;
  ctx->scopes = list_node_init(scope_init());
  ctx->name = strdup(name);
  ctx->t9n = t9n_init();
  return ctx;
}

Symbol *context_search_symbol_scopes(Context *ctx, Symbol *sym) {
  StackNode *curr_scope_stacknode_ref;
  LIST_FOR_EACH_REVERSE(ctx->scopes, {
    if (((Scope *)__IT__->data)->index == ctx->current_scope) {
      curr_scope_stacknode_ref = __IT__;
      break;
    }
  });

  LIST_FOR_EACH_REVERSE(curr_scope_stacknode_ref, {
    Scope *scope = __IT__->data;
    while (__IT_NXT__ &&
           (scope->last_parent != ((Scope *)__IT_NXT__->data)->index)) {
      __IT_NXT__ = __IT_NXT__->parent;
    }
    Symbol *sym_entry = symbol_table_lookup(scope->symbol_table, sym->name);
    if (sym_entry) return sym_entry;
  });
  return NULL;
}

Symbol *context_has_symbol(Context *ctx, Symbol *sym) {
  Scope *scope = context_found_scope(ctx, ctx->current_scope);
  return symbol_table_lookup(scope->symbol_table, sym->name);
}

void context_free(Context *ctx) {
  LIST_FREE_REVERSE(ctx->scopes, { scope_free(__IT__->data); });
  free(ctx->name);
  t9n_free(ctx->t9n);
  free(ctx);
}

Scope *context_push_scope(Context *ctx) {
  Scope *scope = scope_add(&ctx->scopes, stack_peek(&ctx->scopes));
  scope->last_parent = ctx->current_scope;
  ctx->current_scope = scope->index;
  return scope;
}

Scope *context_pop_scope(Context *ctx) {
  Scope *nxt_curr_scope = context_found_scope(ctx, ctx->current_scope);
  ctx->current_scope = nxt_curr_scope->last_parent;
  return nxt_curr_scope;
}

Symbol *context_declare_variable(Context *ctx, Symbol *sym) {
  Scope *current_scope = context_found_scope(ctx, ctx->current_scope);
  Symbol *entry =
      symbol_table_get_valid_entry(current_scope->symbol_table, sym->name);
  if (entry) {
    symbol_update(entry, sym->name, sym->type, false, current_scope->index,
                  ctx->name, sym->temp, sym->def_pos);
    symbol_init_value(entry);
    ++current_scope->size;
  }
  return entry;
}

Symbol *context_declare_function(Context *ctx, Symbol *sym) {
  Scope *current_scope = context_found_scope(ctx, ctx->current_scope);
  Symbol *entry =
      symbol_table_get_valid_entry(current_scope->symbol_table, sym->name);
  if (entry) {
    symbol_update(entry, sym->name, sym->type, true, current_scope->index,
                  ctx->name, sym->temp, sym->def_pos);
    ++current_scope->size;
    symbol_init_value(entry);
  }
  return entry;
}

void context_print(Context *ctx) {
  printf("{ name: %s, scopes: [ ", ctx->name);
  LIST_FOR_EACH_REVERSE(ctx->scopes, { scope_print(__IT__->data); });
  printf("], }, ");
}

Scope *context_found_scope(Context *ctx, int idx) {
  LIST_FOR_EACH_REVERSE(ctx->scopes, {
    Scope *scope = __IT__->data;
    if (scope->index == idx) return scope;
  });
  return NULL;
}

void context_print_pretty(Context *ctx) {
  if (!strcmp(ctx->name, "top level")) {
    CIPL_PRINTF_COLOR(UYEL, "%s symbol table\n", ctx->name);
  } else {
    CIPL_PRINTF_COLOR(UYEL,
                      "symbol table for function:" RESET BBLU " '%s'\n" RESET,
                      ctx->name);
  }
  int wd = 0;
  LIST_FOR_EACH_REVERSE(ctx->scopes, {
    Scope *scope = __IT__->data;
    if (scope->size) {
      scope_print_pretty(scope, wd);
      ++wd;
    }
  });
  printf("\n");
}
