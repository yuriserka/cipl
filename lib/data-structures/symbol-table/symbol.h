#pragma once

#include "stdbool.h"

// fast-forward definition of Symbol
typedef struct cipl_symbol Symbol;
typedef union cipl_symbol_values SymbolValues;

#include "data-structures/list.h"
#include "utils/cursor-position.h"

typedef enum cipl_symbol_types {
  SYM_INVALID,
  SYM_INT,
  SYM_REAL,
  SYM_PTR,
  SYM_INT_LIST,
  SYM_REAL_LIST,
} SymbolTypes;

union cipl_symbol_values {
  int integer;
  double real;
  ListNode *list;
};

struct cipl_symbol {
  char *name;
  char *context_name;
  SymbolValues value;
  int scope;
  bool is_fn;
  int temp;
  Cursor def_pos;
  SymbolTypes type;
};

struct cipl_context;

Symbol *symbol_init(char *name, SymbolTypes type, bool is_function, int scope,
                    char *ctx_name, int temp, Cursor pos);
Symbol *symbol_init_copy(Symbol *other);
Symbol *symbol_found(char *name, Cursor pos);
void symbol_update_type(Symbol *sym, SymbolTypes type);
void symbol_update_temp(Symbol *sym, int temp_num);
void symbol_update_context(Symbol *sym, struct cipl_context *ctx);

void symbol_update(Symbol *sym, char *name, SymbolTypes type, bool is_function,
                   int scope, char *ctx_name, int temp, Cursor pos);
void symbol_free(Symbol *sym);
void symbol_print(Symbol *sym);
void symbol_print_pretty(Symbol *sym);

SymbolTypes symbol_type_from_str(char *type);
char *symbol_type_from_enum(SymbolTypes type);
char *symbol_canonical_type_from_enum(SymbolTypes type);

void symbol_update_value(Symbol *sym, int mArgs, ...);
void symbol_init_value(Symbol *sym);

bool can_arith(SymbolTypes lhs, SymbolTypes rhs);
bool can_compare(SymbolTypes lhs, SymbolTypes rhs);
bool can_assign(SymbolTypes lhs, SymbolTypes rhs);
bool can_mapfil_list(SymbolTypes lhs, SymbolTypes rhs);
bool can_cons_list(SymbolTypes lhs, SymbolTypes rhs);

struct cipl_ast;
char *symbol_canonical_type_function(struct cipl_ast *func_declarator);
