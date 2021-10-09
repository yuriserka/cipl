#pragma once

#include <stdio.h>

#include "data-structures/symbol-table/symbol.h"

typedef struct {
  int temp;
  int param;
} T9nUnit;

T9nUnit *t9n_init();
void t9n_free(T9nUnit *t9n);
char t9n_prefix(Symbol *symbol);

void asm_generate_table_header(FILE *out);
void asm_generate_code_header(FILE *out);
void asm_generate_code_end(FILE *out);
