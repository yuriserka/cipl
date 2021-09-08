#include "data-structures/context.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "data-structures/scope.h"
#include "utils/io.h"

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
  Scope *scope = context_found_scope(ctx);
  return symbol_table_lookup(scope->symbol_table, sym->name);
}

void context_free(Context *ctx) {
  LIST_FREE_REVERSE(ctx->scopes, { scope_free(__IT__->data); });
  free(ctx->name);
  free(ctx);
}

Scope *context_push_scope(Context *ctx) {
  Scope *scope = scope_add(&ctx->scopes, stack_peek(&ctx->scopes));
  scope->last_parent = ctx->current_scope;
  ctx->current_scope = scope->index;
  return scope;
}

Scope *context_pop_scope(Context *ctx) {
  Scope *nxt_curr_scope = context_found_scope(ctx);
  ctx->current_scope = nxt_curr_scope->last_parent;
  return nxt_curr_scope;
}

Symbol *context_declare_variable(Context *ctx, Symbol *sym) {
  Scope *current_scope = context_found_scope(ctx);
  Symbol *entry =
      symbol_table_get_valid_entry(current_scope->symbol_table, sym->name);
  if (entry) {
    symbol_update(entry, sym->name, sym->type, false, current_scope->index,
                  ctx->name, sym->def_pos);
    ++current_scope->size;
  }
  return entry;
}

Symbol *context_declare_function(Context *ctx, Symbol *sym) {
  Scope *current_scope = context_found_scope(ctx);
  Symbol *entry =
      symbol_table_get_valid_entry(current_scope->symbol_table, sym->name);
  if (entry) {
    symbol_update(entry, sym->name, sym->type, true, current_scope->index,
                  ctx->name, sym->def_pos);
    ++current_scope->size;
  }
  return entry;
}

void context_print(Context *ctx) {
  printf("{ name: %s, scopes: [ ", ctx->name);
  LIST_FOR_EACH_REVERSE(ctx->scopes, { scope_print(__IT__->data); });
  printf("], }, ");
}

Scope *context_found_scope(Context *ctx) {
  LIST_FOR_EACH_REVERSE(ctx->scopes, {
    Scope *scope = __IT__->data;
    if (scope->index == ctx->current_scope) return scope;
  });
  return NULL;
}

void context_print_pretty(Context *ctx) {
  int wd = 0;
  CIPL_PRINTF_COLOR(UYEL, "Symbol Table for Context: %s\n", ctx->name);
  LIST_FOR_EACH_REVERSE(ctx->scopes, {
    Scope *scope = __IT__->data;

    if (scope->size) {
      for (int i = 0; i < wd; ++i) printf("\t");
      CIPL_PRINTF_COLOR(UMAG, "Scope %d has %d entr%s\n", scope->index,
                        scope->size, scope->size > 1 ? "ies" : "y");

      for (int i = 0; i < NHASH; ++i) {
        if (scope->symbol_table[i].name) {
          Symbol *sym = &scope->symbol_table[i];
          for (int i = 0; i < wd; ++i) printf("\t");
          symbol_print_pretty(sym);
        }
      }
      ++wd;
      printf("\n");
    }
  });
  printf("\n");
}
