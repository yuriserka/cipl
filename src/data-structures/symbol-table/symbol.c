#include "data-structures/symbol-table/symbol.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/globals.h"

Symbol *symbol_init(char *name, int scope, char *ctx_name,
                    cursor_position pos) {
  Symbol *sym = calloc(1, sizeof(Symbol));
  symbol_update(sym, name, scope, ctx_name, pos);
  return sym;
}

Symbol *symbol_init_copy(Symbol *other) {
  return symbol_init(other->name, other->scope, other->context_name,
                     other->def_pos);
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
