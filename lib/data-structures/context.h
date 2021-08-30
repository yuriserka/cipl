#pragma once

#include "data-structures/ast/types/symbol-ref.h"
#include "data-structures/scope.h"
#include "data-structures/stack.h"
#include "data-structures/symbol-table/symbol.h"

typedef struct cipl_context {
  StackNode *scopes;
  int current_scope;
  char *name;
} Context;

Context *context_init(char *name);
void context_free(Context *context);
void context_print(Context *ctx);

Scope *context_push_scope(Context *ctx);
Scope *context_pop_scope(Context *ctx);
Symbol *context_has_symbol(Context *ctx, Symbol *sym);
Symbol *context_search_symbol_scopes(Context *ctx, Symbol *sym);
Symbol *context_declare_variable(Context *ctx, SymbolRefAST *symref);
Symbol *context_declare_function(Context *ctx, SymbolRefAST *sym);