#include "utils/asm/asm.h"

#include <stdlib.h>

#include "core/globals.h"
#include "utils/string/unescape.h"

T9nUnit *t9n_init() {
  T9nUnit *t9n = calloc(1, sizeof(T9nUnit));
  t9n->temp = 0;
  return t9n;
}

void t9n_free(T9nUnit *t9n) { free(t9n); }

void asm_generate_table_header(FILE *out) { fprintf(out, ".table\n"); }

void asm_insert_str_literal_header(FILE *out) {
  int i = 0;
  fprintf(out, "\nchar str_nil[] = \"nil\"\n");
  AST_FIND_NODE(root, AST_STR_LITERAL,
                {
                  char *val = __AST__->value.str->value;
                  char *entry = calloc(sizeof("str_") + 100, sizeof(char));
                  fprintf(out, "char str_%d[] = \"%s\"\n", i, val);
                  sprintf(entry, "str_%d", i++);
                  __AST__->value.str->table_entry = entry;
                },
                {});
  fprintf(out, "\n");
}

void asm_generate_code_header(FILE *out) { fprintf(out, ".code\n"); }

static void asm_read(FILE *out) {
  fprintf(out, "\nread:\n");
  fprintf(out, "println 3\n");
  fprintf(out, "return 0\n");
}

static void asm_write(FILE *out) {
  fprintf(out, "\nwrite:\n");
  fprintf(out, "brz write_STR, #1\n");
  fprintf(out, "print #0\n");
  fprintf(out, "jump write_END\n");
  fprintf(out, "write_STR:\n");
  fprintf(out, "mov $2, 0\n");
  fprintf(out, "write_STR_LOOP:\n");
  fprintf(out, "mov $1, '\\0'\n");
  fprintf(out, "mov $3, #0[$2]\n");
  fprintf(out, "seq $1, $1, $3\n");
  fprintf(out, "brnz write_END, $1 \n");
  fprintf(out, "print $3\n");
  fprintf(out, "add $2, $2, 1\n");
  fprintf(out, "jump write_STR_LOOP\n");
  fprintf(out, "write_END:\n");
  fprintf(out, "return 0\n");
}
static void asm_writeln(FILE *out) {
  fprintf(out, "\nwriteln:\n");
  fprintf(out, "param #0\n");
  fprintf(out, "param #1\n");
  fprintf(out, "call write, 2\n");
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