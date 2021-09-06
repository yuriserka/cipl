#pragma once

#include "stdbool.h"

// fast-forward definition of Symbol
typedef struct cipl_symbol Symbol;

#include "data-structures/list.h"
#include "utils/cursor-position.h"

typedef enum cipl_symbol_types {
  SYM_INVALID,
  SYM_INT,
  SYM_REAL,
  SYM_INT_LIST,
  SYM_REAL_LIST,
} SymbolTypes;

struct cipl_symbol {
  char *name;
  char *context_name;
  double value;
  int scope;
  bool is_fn;
  Cursor def_pos;
  SymbolTypes type;
};

struct cipl_context;

Symbol *symbol_init(char *name, SymbolTypes type, bool is_function, int scope,
                    char *ctx_name, Cursor pos);
Symbol *symbol_init_copy(Symbol *other);
Symbol *symbol_found(char *name, Cursor pos);
void symbol_update_type(Symbol *sym, SymbolTypes type);
void symbol_update_context(Symbol *sym, struct cipl_context *ctx);

void symbol_update(Symbol *sym, char *name, SymbolTypes type, bool is_function,
                   int scope, char *ctx_name, Cursor pos);
void symbol_free(Symbol *sym);
void symbol_print(Symbol *sym);
void symbol_print_pretty(Symbol *sym);

SymbolTypes symbol_type_from_str(char *type);
char *symbol_type_from_enum(SymbolTypes type);