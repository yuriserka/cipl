#include "utils/asm/asm.h"

#include <stdlib.h>

#include "core/globals.h"
#include "utils/string/unescape.h"

T9nUnit *t9n_init() {
  T9nUnit *t9n = calloc(1, sizeof(T9nUnit));
  t9n->temp = 0;
  t9n->param = 0;
  return t9n;
}

void t9n_free(T9nUnit *t9n) { free(t9n); }

char t9n_prefix(SymbolKinds kind) { return kind == PARAM ? '#' : '$'; }

void t9n_alloc_from_other(int to, SymbolTypes type, int from, SymbolKinds kind,
                          FILE *out) {
  switch (type) {
    case SYM_INT:
    case SYM_REAL:
      fprintf(out, "mema $%d, 2\n", to);
      fprintf(out, "mov $%d[0], %d\n", to, type);
      fprintf(out, "mov $%d, %c%d[1]\n", to + 1, t9n_prefix(kind), from);
      fprintf(out, "mov $%d[1], $%d\n", to, to + 1);
      break;
    default:
      fprintf(out, "mema $%d, 3\n", to);
      fprintf(out, "mov $%d[0], %d\n", to, type);
      fprintf(out, "mov $%d, %c%d[1]\n", to + 1, t9n_prefix(kind), from);
      fprintf(out, "mov $%d[1], $%d\n", to, to + 1);
      fprintf(out, "mov $%d, %c%d[2]\n", to + 2, t9n_prefix(kind), from);
      fprintf(out, "mov $%d[2], $%d\n", to, to + 2);
      // fprintf(out, "mov $%d[2], %c%d\n", to, t9n_prefix(kind), from);
  }
}

void t9n_alloc_from_literal(int to, char *tb_ref, FILE *out) {
  fprintf(out, "mema $%d, 2\n", to);
  fprintf(out, "mov $%d[0], %d\n", to, SYM_PTR);
  fprintf(out, "mov $%d[1], &%s\n", to, tb_ref);
}

void t9n_alloc_from_constant(int to, SymbolTypes type, NumberValue value,
                             FILE *out) {
  switch (type) {
    case SYM_INT:
      // $temp[0] = type
      // $temp[1] = &$var
      fprintf(out, "mema $%d, 2\n", to);
      fprintf(out, "mov $%d[0], %d\n", to, type);
      fprintf(out, "mov $%d[1], %ld\n", to, value.integer);
      break;
    case SYM_REAL:
      // $temp[0] = type
      // $temp[1] = &$var
      fprintf(out, "mema $%d, 2\n", to);
      fprintf(out, "mov $%d[0], %d\n", to, type);
      fprintf(out, "mov $%d[1], %lf\n", to, value.real);
      break;
    default:
      // $temp[0] = type
      // $temp[1] = size
      // $temp[1] = &list per say
      fprintf(out, "mema $%d, 3\n", to);
      fprintf(out, "mov $%d[0], %d\n", to, type);
      fprintf(out, "mov $%d[1], $%d\n", to, 0);
      // fprintf(out, "mov $%d[2], \n", to, from);
  }
}

void t9n_alloc_decl(int to, SymbolTypes type, FILE *out) {
  switch (type) {
    case SYM_INT:
      t9n_alloc_from_constant(to, type, (NumberValue){.integer = 0}, out);
      break;
    case SYM_REAL:
      t9n_alloc_from_constant(to, type, (NumberValue){.real = 0}, out);
      break;
    default:
      t9n_alloc_from_constant(to, type, (NumberValue){.integer = 0}, out);
  }
}

static void asm_insert_str_literal_header(FILE *out) {
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

void asm_generate_table_header(FILE *out) {
  fprintf(out, ".table\n");
  asm_insert_str_literal_header(out);
}

static void asm_set_var_val(FILE *out) {
  fprintf(out, "set_var_val:\n");
  fprintf(out, "seq $0, #2, 0\n");
  fprintf(out, "brz set_var_val_FROM_VAR, $0\n");
  fprintf(out, "mov $0, *#0\n");
  fprintf(out, "mov $3, #1\n");
  fprintf(out, "jump set_var_val_END\n");
  fprintf(out, "set_var_val_FROM_VAR:\n");
  fprintf(out, "mov $0, *#0\n");
  fprintf(out, "mov $1, *#1\n");
  fprintf(out, "mov $2, #1[1]\n");
  fprintf(out, "set_var_val_START:\n");
  fprintf(out, "seq $3, $0, $1\n");
  fprintf(out, "brnz set_var_val_EQUAL, $3\n");
  fprintf(out, "slt $3, $0, $1\n");
  fprintf(out, "brnz set_var_val_F2I, $3\n");
  fprintf(out, "mov $3, $2\n");
  fprintf(out, "inttofl $3, $3\n");
  fprintf(out, "jump set_var_val_END\n");
  fprintf(out, "set_var_val_F2I:\n");
  fprintf(out, "mov $3, $2\n");
  fprintf(out, "fltoint $3, $3\n");
  fprintf(out, "jump set_var_val_END\n");
  fprintf(out, "set_var_val_EQUAL:\n");
  fprintf(out, "mov $3, $2\n");
  fprintf(out, "set_var_val_END:\n");
  fprintf(out, "mov #0[1], $3\n");
  fprintf(out, "return 0\n\n");
}

static void asm_get_var_val(FILE *out) {
  fprintf(out, "get_var_val:\n");
  fprintf(out, "mov $0, *#0\n");
  fprintf(out, "seq $0, $0, 2\n");
  fprintf(out, "brz get_var_val_INT, $0\n");
  fprintf(out, "mov $0, #0[1]\n");
  fprintf(out, "jump get_var_val_END\n");
  fprintf(out, "get_var_val_INT:\n");
  fprintf(out, "mov $0, #0[1]\n");
  fprintf(out, "get_var_val_END:\n");
  fprintf(out, "return $0\n\n");
}

static void asm_generate_utils(FILE *out) {
  asm_set_var_val(out);
  asm_get_var_val(out);
}

static void asm_read(FILE *out) {
  fprintf(out, "read:\n");
  fprintf(out, "mov $0, *#0\n");
  fprintf(out, "seq $0, $0, 2\n");
  fprintf(out, "brz read_INT, $0\n");
  fprintf(out, "scanf $1\n");
  fprintf(out, "jump read_END\n");
  fprintf(out, "read_INT:\n");
  fprintf(out, "scani $1\n");
  fprintf(out, "read_END:\n");
  fprintf(out, "mov #0[1], $1\n");
  fprintf(out, "return 0\n\n");
}

// receive 1 param of of t9n_alloc
static void asm_write(FILE *out) {
  fprintf(out, "write:\n");
  fprintf(out, "mov $0, #0[0]\n");
  fprintf(out, "seq $0, $0, 3\n");
  fprintf(out, "brnz write_STR, $0\n");
  fprintf(out, "param #0\n");
  fprintf(out, "call get_var_val, 1\n");
  fprintf(out, "pop $0\n");
  fprintf(out, "print $0\n");
  fprintf(out, "jump write_END\n");
  fprintf(out, "write_STR:\n");
  fprintf(out, "mov $0, #0[1]\n");
  fprintf(out, "mov $2, 0\n");
  fprintf(out, "write_STR_LOOP:\n");
  fprintf(out, "mov $1, '\\0'\n");
  fprintf(out, "mov $3, $0[$2]\n");
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

static void asm_generate_builtin_funcs(FILE *out) {
  asm_read(out);
  asm_write(out);
  asm_writeln(out);
}

void asm_generate_code_header(FILE *out) {
  fprintf(out, ".code\n");
  asm_generate_utils(out);
  asm_generate_builtin_funcs(out);
}

void asm_generate_code_end(FILE *out) {
  fprintf(out, "\nEOF:\n");
  fprintf(out, "nop\n");
}