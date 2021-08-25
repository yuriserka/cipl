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

Symbol *symbol_table_lookup(SymbolTable symbol_tb, char *sym_name) {
  Symbol *sp = &symbol_tb[symbol_table_hash(sym_name) % NHASH];
  int scount = NHASH;

  while (--scount >= 0) {
    if (sp->name && !strcmp(sp->name, sym_name)) {
      return sp;
    }
    if (++sp >= symbol_tb + NHASH) sp = symbol_tb;  // back to head of array
  }

  CIPL_PERROR("'%s' undeclared (first use in this function)\n", sym_name);
  return NULL;
}

Symbol *symbol_table_insert(SymbolTable symbol_tb, char *sym_name) {
  Symbol *sp = &symbol_tb[symbol_table_hash(sym_name) % NHASH];
  int scount = NHASH;

  while (--scount >= 0) {
    if (sp->name && !strcmp(sp->name, sym_name)) {
      return sp;
    }
    if (!sp->name) {
      Scope *curr_scope = stack_peek(&scopes);
      symbol_update(sp, sym_name, curr_scope->index, cursor);
      return sp;
    }
    if (++sp >= symbol_tb + NHASH) sp = symbol_tb;  // back to head of array
  }

  CIPL_PERROR("symbol_table overflow\n");
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

  CIPL_PERROR("symbol: %s not found\n", sym_name);
}

void symbol_table_free(SymbolTable symbol_tb) {
  for (int i = 0; i < NHASH; ++i) {
    if (symbol_tb[i].name) symbol_free(&symbol_tb[i]);
  }
}
