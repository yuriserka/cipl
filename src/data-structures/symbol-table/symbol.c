#include "data-structures/symbol-table/symbol.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "data-structures/context.h"
#include "utils/io.h"

Symbol *symbol_init(char *name, SymbolTypes type, bool is_function, int scope,
                    char *ctx_name, Cursor pos) {
  Symbol *sym = calloc(1, sizeof(Symbol));
  symbol_update(sym, name, type, is_function, scope, ctx_name, pos);
  return sym;
}

void symbol_update_type(Symbol *sym, SymbolTypes type) { sym->type = type; }

Symbol *symbol_init_copy(Symbol *other) {
  return symbol_init(other->name, other->type, other->is_fn, other->scope,
                     other->context_name, other->def_pos);
}

Symbol *symbol_found(char *name, Cursor pos) {
  return symbol_init(name, SYM_INVALID, false, 0, NULL, pos);
}

void symbol_update_context(Symbol *sym, Context *ctx) {
  sym->context_name = ctx->name;
  sym->scope = ctx->current_scope;
}

void symbol_update(Symbol *sym, char *name, SymbolTypes type, bool is_function,
                   int scope, char *ctx_name, Cursor pos) {
  sym->name = name ? strdup(name) : NULL;
  sym->context_name = ctx_name;
  sym->scope = scope;
  sym->value = 0;
  sym->def_pos = pos;
  sym->type = type;
  sym->is_fn = is_function;
}

void symbol_free(Symbol *sym) {
  if (!sym) return;

  if (sym->name) free(sym->name);
  free(sym);
}

void symbol_print(Symbol *sym) {
  printf(
      "{ name: '%s', type: %s%s, declared_at: '%s:%d:%d', ctx: '%s', scope: "
      "%d}, ",
      sym->name, sym->is_fn ? "SYM_FUNC " : "",
      symbol_type_from_enum(sym->type), filename, sym->def_pos.line,
      sym->def_pos.col, sym->context_name, sym->scope);
}

void symbol_print_pretty(Symbol *sym) {
  const char *color = sym->is_fn ? BBLU : BCYN;
  CIPL_PRINTF_COLOR(BGRN,
                    "%s%s "
                    "%s"
                    "%s " BHWHT "@%d:%d\n",
                    sym->is_fn ? "SYM_FUNC " : "",
                    symbol_type_from_enum(sym->type), color, sym->name,
                    sym->def_pos.line, sym->def_pos.col);
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