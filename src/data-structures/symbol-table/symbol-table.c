#include "data-structures/symbol-table/symbol-table.h"

#include <string.h>

#include "core/globals.h"
#include "data-structures/ast/types/symbol-ref.h"
#include "utils/io.h"

static unsigned symbol_table_hash(char *sym_name) {
  unsigned long hash = 0;
  int c;
  while ((c = *sym_name++)) hash = c + (hash << 6) + (hash << 16) - hash;
  return hash;
}

Symbol *symbol_table_lookup(SymbolTable symbol_table, char *sym_name) {
  Symbol *sp = &symbol_table[symbol_table_hash(sym_name) % NHASH];
  int scount = NHASH;

  while (--scount >= 0) {
    if (sp->name && !strcmp(sp->name, sym_name)) {
      return sp;
    }
    if (++sp >= symbol_table + NHASH) sp = symbol_table;
  }
  return NULL;
}

Symbol *symbol_table_get_valid_entry(SymbolTable symbol_table, char *sym_name) {
  Symbol *sp = &symbol_table[symbol_table_hash(sym_name) % NHASH];
  int scount = NHASH;

  while (--scount >= 0) {
    if (sp->name && !strcmp(sp->name, sym_name)) {
      return NULL;
    }
    if (!sp->name) {
      return sp;
    }
    if (++sp >= symbol_table + NHASH) sp = symbol_table;
  }

  CIPL_PERROR("symbol_table overflow\n");
  return NULL;
}

void symbol_table_delete(SymbolTable symbol_table, char *sym_name) {
  Symbol *sp = &symbol_table[symbol_table_hash(sym_name) % NHASH];
  int scount = NHASH;

  while (--scount >= 0) {
    if (sp->name && !strcmp(sp->name, sym_name)) {
      symbol_free(sp);
      return;
    }
  }

  CIPL_PERROR("symbol: %s not found\n", sym_name);
}

void symbol_table_free(SymbolTable symbol_table) {
  for (int i = 0; i < NHASH; ++i) {
    if (symbol_table[i].name) symbol_free(&symbol_table[i]);
  }
}

void symbol_table_print(SymbolTable symbol_table) {
  for (int i = 0; i < NHASH; ++i) {
    if (symbol_table[i].name) symbol_print(&symbol_table[i]);
  }
}
