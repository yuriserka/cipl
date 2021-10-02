#pragma once

#include <stdio.h>

typedef struct {
  int temp;
} T9nUnit;

T9nUnit *t9n_init();
void t9n_free(T9nUnit *t9n);

void asm_generate_table_header(FILE *out);
void asm_generate_code_header(FILE *out);
void asm_generate_builtin_funcs(FILE *out);
void asm_generate_code_end(FILE *out);
void asm_insert_str_literal_header(FILE *out);
