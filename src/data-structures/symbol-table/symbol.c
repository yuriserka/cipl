#include "data-structures/symbol-table/symbol.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "data-structures/context.h"

Symbol *symbol_init(char *name, SymbolTypes type, int scope, char *ctx_name,
                    cursor_position pos) {
  Symbol *sym = calloc(1, sizeof(Symbol));
  symbol_update(sym, name, type, scope, ctx_name, pos);
  return sym;
}

void symbol_update_type(Symbol *sym, SymbolTypes type) { sym->type = type; }

Symbol *symbol_init_copy(Symbol *other) {
  return symbol_init(other->name, other->type, other->scope,
                     other->context_name, other->def_pos);
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

void symbol_update(Symbol *sym, char *name, SymbolTypes type, int scope, char *ctx_name,
                   cursor_position pos) {
  sym->name = strdup(name);
  sym->context_name = strdup(ctx_name);
  sym->scope = scope;
  sym->value = 0;
  sym->def_pos = pos;
  sym->type = type;
}

void symbol_free(Symbol *sym) {
  free(sym->name);
  free(sym->context_name);
  free(sym);
}

void symbol_print(Symbol *sym) {
  printf("{ name: '%s', type: %s, declared_at: '%s:%d:%d', }, ", sym->name,
         symbol_type_from_enum(sym->type), filename, sym->def_pos.line,
         sym->def_pos.col);
}

SymbolTypes symbol_type_from_str(char *type) {
  if (!type) return SYM_INVALID;

  if (!strcmp(type, "int")) return SYM_INT;
  if (!strcmp(type, "float")) return SYM_REAL;
  if (!strcmp(type, "int list")) return SYM_INT_LIST;
  if (!strcmp(type, "float list")) return SYM_REAL_LIST;

  return SYM_INVALID;
}

char *symbol_type_from_enum(SymbolTypes type) {
  switch (type) {
    case SYM_INT:
      return "SYM_INT";
    case SYM_INT_LIST:
      return "SYM_INT_LIST";
    case SYM_REAL:
      return "SYM_REAL";
    case SYM_REAL_LIST:
      return "SYM_REAL_LIST";
    default:
      return "SYM_INVALID";
  }
}