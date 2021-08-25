#pragma once

// fast-forward definition of Symbol
typedef struct cipl_symbol Symbol;

#include "data-structures/ast/ast.h"
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
  double value;
  int scope;
  cursor_position def_pos;
  // SymbolTypes type;
};

void symbol_init(Symbol *sym, char *name, int scope, cursor_position position);
void symbol_free(Symbol *sym);