#include "data-structures/symbol-table/symbol-table.h"

#include <string.h>

#include "core/globals.h"
#include "utils/io.h"

SymbolTable symbol_tb;

static unsigned symbol_table_hash(char *sym_name) {
  unsigned int hash = 0;
  unsigned c;
  while ((c = *sym_name++)) hash = hash * 9 ^ c;
  return hash;
}

Symbol *symbol_table_lookup(char *sym_name) {
  Symbol *sp = &symbol_tb[symbol_table_hash(sym_name) % NHASH];
  int scount = NHASH;

  while (--scount >= 0) {
    if (sp->name && !strcmp(sp->name, sym_name)) {
      return sp;
    }
    if (!sp->name) {
      symbol_init(sp, sym_name, 0, cursor);
      return sp;
    }
    if (++sp >= symbol_tb + NHASH) sp = symbol_tb;  // back to head of array
  }

  cipl_perror("symbol_table overflow\n");
  ++errors_count;
  return NULL;
}

void symbol_table_delete(char *sym_name) {
  Symbol *sp = &symbol_tb[symbol_table_hash(sym_name) % NHASH];
  int scount = NHASH;

  while (--scount >= 0) {
    if (sp->name && !strcmp(sp->name, sym_name)) {
      symbol_free(sp);
      return;
    }
  }

  cipl_perror("symbol: %s not found\n", sym_name);
  ++errors_count;
}
