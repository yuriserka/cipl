#pragma once

#include "data-structures/stack.h"
#include "data-structures/symbol-table/symbol.h"

typedef struct cipl_context {
    StackNode *scopes;
} Context;

Context *context_init();
Symbol *context_has_symbol(Context *ctx, char *sym_name);
void context_free(Context *context);
