#include "data-structures/symbol-table/symbol.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "data-structures/context.h"

Symbol *symbol_init(char *name, int scope, char *ctx_name,
                    cursor_position pos) {
  Symbol *sym = calloc(1, sizeof(Symbol));
  symbol_update(sym, name, scope, ctx_name, pos);
  return sym;
}

void symbol_update_type(Symbol *sym, SymbolTypes type) { sym->type = type; }

Symbol *symbol_init_copy(Symbol *other) {
  return symbol_init(other->name, other->scope, other->context_name,
                     other->def_pos);
}

Symbol *symbol_found(char *name, cursor_position pos) {
  Symbol *sym = calloc(1, sizeof(Symbol));
  sym->name = strdup(name);
  sym->def_pos = pos;
  return sym;
}

void symbol_update_context(Symbol *sym, Context *ctx) {
  sym->context_name = strdup(ctx->name);
  sym->scope = ctx->current_scope;
}

void symbol_update(Symbol *sym, char *name, int scope, char *ctx_name,
                   cursor_position pos) {
  sym->name = strdup(name);
  sym->context_name = strdup(ctx_name);
  sym->scope = scope;
  sym->value = 0;
  sym->def_pos = pos;
}

void symbol_free(Symbol *sym) {
  free(sym->name);
  free(sym->context_name);
  free(sym);
}

void symbol_print(Symbol *sym) {
  printf("{ name: '%s', declared_at: '%s:%d:%d', }, ", sym->name, filename,
         sym->def_pos.line, sym->def_pos.col);
}
