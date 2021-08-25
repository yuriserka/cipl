#include "data-structures/symbol-table/symbol.h"

#include <stdlib.h>
#include <string.h>

Symbol *symbol_init(char *name, int scope, cursor_position pos) {
  Symbol *sym = calloc(1, sizeof(Symbol));
  symbol_update(sym, name, scope, pos);
  return sym;
}

void symbol_update(Symbol *sym, char *name, int scope, cursor_position pos) {
  sym->name = strdup(name);
  sym->scope = scope;
  sym->value = 0;
  sym->def_pos = pos;
}

void symbol_free(Symbol *sym) {
  free(sym->name);
  free(sym);
}
