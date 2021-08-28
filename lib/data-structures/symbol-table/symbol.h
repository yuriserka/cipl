#pragma once

// fast-forward definition of Symbol
typedef struct cipl_symbol Symbol;

#include "data-structures/list.h"
#include "utils/cursor-position.h"

// typedef enum cipl_symbol_types {
//   SYM_INT,
//   SYM_REAL,
//   SYM_INT_LIST,
//   SYM_REAL_LIST,
//   SYM_FUNC,
// } SymbolTypes;

struct cipl_symbol {
  char *name;
  char *context_name;
  double value;
  int scope;
  cursor_position def_pos;
  // SymbolTypes type;
};

Symbol *symbol_init(char *name, int scope, char *ctx_name, cursor_position pos);
Symbol *symbol_init_copy(Symbol *other);
void symbol_update(Symbol *sym, char *name, int scope, char *ctx_name,
                   cursor_position pos);
void symbol_free(Symbol *sym);
void symbol_print(Symbol *sym);