#include "utils/asm/asm.h"

#include <stdlib.h>

T9nUnit *t9n_init() {
  T9nUnit *t9n = calloc(1, sizeof(T9nUnit));
  t9n->temp = 0;
  return t9n;
}

void t9n_free(T9nUnit *t9n) { free(t9n); }

void asm_generate_table_header(FILE *out) { fprintf(out, ".table\n"); }

void asm_generate_code_header(FILE *out) { fprintf(out, ".code\n"); }

static void asm_read(FILE *out) {
  fprintf(out, "read:\n");
  fprintf(out, "println 3\n");
  fprintf(out, "return 0\n\n");
}

static void asm_write(FILE *out) {
  fprintf(out, "write:\n");
  fprintf(out, "println 1\n");
  fprintf(out, "return 0\n\n");
}
static void asm_writeln(FILE *out) {
  fprintf(out, "writeln:\n");
  fprintf(out, "call write, 0\n");
  fprintf(out, "println\n");
  fprintf(out, "return 0\n");
}

void asm_generate_builtin_funcs(FILE *out) {
  asm_read(out);
  asm_write(out);
  asm_writeln(out);
}

void asm_generate_code_end(FILE *out) {
  fprintf(out, "\nEOF:\n");
  fprintf(out, "nop\n");
}