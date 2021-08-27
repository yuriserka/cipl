#include "data-structures/symbol-table/symbol-table.h"

#include <string.h>

#include "core/globals.h"
#include "utils/io.h"

SymbolTable symbol_table;

static unsigned symbol_table_hash(char *sym_name) {
  unsigned int hash = 0;
  char *pname = sym_name;
  unsigned c;
  while ((c = *pname++)) hash = hash * 9 ^ c;
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

Symbol *symbol_table_insert(SymbolTable symbol_table, AST *ast) {
  Symbol *symref = ast->value.symref->symbol;
  Symbol *sp = &symbol_table[symbol_table_hash(symref->name) % NHASH];
  int scount = NHASH;

  while (--scount >= 0) {
    if (sp->name && !strcmp(sp->name, symref->name)) {
      return NULL;
    }
    if (!sp->name) {
      symbol_update(sp, symref->name, current_scope->index, symref->def_pos);
      return sp;
    }
    if (++sp >= symbol_table + NHASH) sp = symbol_table;
  }

  CIPL_PERROR("symbol_table overflow\n");
  return NULL;
}

void symbol_table_delete(char *sym_name) {
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
