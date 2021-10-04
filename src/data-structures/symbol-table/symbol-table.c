#include "data-structures/symbol-table/symbol-table.h"

#include <string.h>

#include "core/globals.h"
#include "data-structures/ast/types/symbol-ref.h"
#include "utils/io.h"

SymbolTable *symbol_table_init() {
  SymbolTable *tb = calloc(1, sizeof(SymbolTable));
  tb->symbols = NULL;
  return tb;
}

Symbol *symbol_table_lookup(SymbolTable *tb, char *sym_name) {
  LIST_FOR_EACH(tb->symbols, {
    Symbol *sym = __IT__->data;
    if (!strcmp(sym->name, sym_name)) return sym;
  });
  return NULL;
}

Symbol *symbol_table_get_valid_entry(SymbolTable *tb, char *sym_name) {
  LIST_FOR_EACH(tb->symbols, {
    Symbol *sym = __IT__->data;
    if (!strcmp(sym->name, sym_name)) return NULL;
  });

  Symbol *sym = calloc(1, sizeof(Symbol));
  list_push(&tb->symbols, sym);

  return sym;
}

void symbol_table_free(SymbolTable *tb) {
  LIST_FREE(tb->symbols, {
    Symbol *sym = __IT__->data;
    symbol_free(sym);
  });
  free(tb);
}

void symbol_table_print(SymbolTable *tb) {
  LIST_FOR_EACH(tb->symbols, {
    Symbol *sym = __IT__->data;
    symbol_print_pretty(sym);
  });
}
