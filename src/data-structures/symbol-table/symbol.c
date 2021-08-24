#include "data-structures/symbol-table/symbol.h"

#include <stdlib.h>
#include <string.h>

void symbol_init(Symbol *sym, char *name, int scope, cursor_position pos) {
  sym->name = strdup(name);
  sym->scope = 0;
  sym->value = 0;
  sym->def_pos = pos;
}

void symbol_free(Symbol *sym) {
  free(sym->name);
  // Symbols are stored statically in the symbol_tb array
  // free(sym);
}
