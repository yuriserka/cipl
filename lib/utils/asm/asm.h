#pragma once

#include <stdio.h>

#include "data-structures/ast/types/num.h"

typedef struct {
  int temp;
  int param;
} T9nUnit;

T9nUnit *t9n_init();
void t9n_free(T9nUnit *t9n);
char t9n_prefix(Symbol *symbol);
void t9n_alloc_from_other(int to, SymbolTypes type, int from, FILE *out);
void t9n_alloc_from_constant(int to, SymbolTypes type, NumberValue value,
                             FILE *out);
void t9n_alloc_from_literal(int to, char *tb_ref, FILE *out);

void asm_generate_table_header(FILE *out);
void asm_generate_code_header(FILE *out);
void asm_generate_code_end(FILE *out);
