#include "utils/asm/asm.h"

#include <stdlib.h>

#include "core/globals.h"

static void asm_insert_str_literal_header(FILE *out) {
  int i = 0;
  fprintf(out, "\nchar str_nil[] = \"nil\"\n");
  AST_FIND_NODE(root, AST_STR_LITERAL,
                {
                  StringLiteralAST *str_ast = __AST__->value.str;
                  fprintf(out, "char str_%d[] = \"%s\"\n", i, str_ast->value);
                  str_ast->table_entry = i++;
                },
                {});
  if (i) fprintf(out, "\n");
}

void asm_generate_table_header(FILE *out) {
  fprintf(out, ".table\n");
  asm_insert_str_literal_header(out);
}

static void asm_cast(FILE *out) {
  fprintf(out, "cast:\n");
  fprintf(out, "seq $0, #1, 1\n");
  fprintf(out, "brnz cast_F2I, $0\n");
  fprintf(out, "cast_I2F:\n");
  fprintf(out, "mov $1, 2\n");
  fprintf(out, "mov $2, #0[1]\n");
  fprintf(out, "inttofl $2, $2\n");
  fprintf(out, "jump cast_END\n");
  fprintf(out, "cast_F2I:\n");
  fprintf(out, "mov $1, 1\n");
  fprintf(out, "mov $2, #0[1]\n");
  fprintf(out, "fltoint $2, $2\n");
  fprintf(out, "cast_END:\n");
  fprintf(out, "mema $3, 2\n");
  fprintf(out, "mov $3[0], $1\n");
  fprintf(out, "mov $3[1], $2\n");
  fprintf(out, "return $3\n\n");
}

static void asm_set_var_val(FILE *out) {
  fprintf(out, "set_var_val:\n");
  fprintf(out, "mov $0, #1[0]\n");
  fprintf(out, "slt $0, $0, 3\n");
  fprintf(out, "brz set_var_val_LIST, $0\n");
  fprintf(out, "set_var_val_NUMBER:\n");
  fprintf(out, "mov $0, #1[1]\n");
  fprintf(out, "mov #0[1], $0\n");
  fprintf(out, "jump set_var_val_END\n");
  fprintf(out, "set_var_val_LIST:\n");
  fprintf(out, "mov $0, #1[1]\n");
  fprintf(out, "mov #0[1], $0\n");
  fprintf(out, "mov $0, #1[2]\n");
  fprintf(out, "mov #0[2], $0\n");
  fprintf(out, "set_var_val_END:\n");
  fprintf(out, "return\n\n");
}

static void asm_get_var_val(FILE *out) {
  fprintf(out, "get_var_val:\n");
  fprintf(out, "mov $0, #0[0]\n");
  fprintf(out, "slt $0, $0, 3\n");
  fprintf(out, "brz get_var_val_LIST, $0\n");
  fprintf(out, "mov $0, #0[1]\n");
  fprintf(out, "jump get_var_val_END\n");
  fprintf(out, "get_var_val_LIST:\n");
  fprintf(out, "mov $0, #0[2]\n");
  fprintf(out, "get_var_val_END:\n");
  fprintf(out, "return $0\n\n");
}

static void asm_sign_flip(FILE *out) {
  fprintf(out, "sign_change:\n");
  fprintf(out, "mov $0, #0[1]\n");
  fprintf(out, "mov $1, #0[0]\n");
  fprintf(out, "seq $1, $1, 1\n");
  fprintf(out, "brnz sign_change_INT, $1\n");
  fprintf(out, "sign_change_FLOAT:\n");
  fprintf(out, "seq $1, #1, '-'\n");
  fprintf(out, "brnz sign_change_FLOAT_FLIP, $1\n");
  fprintf(out, "jump sign_change_END\n");
  fprintf(out, "sign_change_FLOAT_FLIP:\n");
  fprintf(out, "mul $0, $0, -1.0\n");
  fprintf(out, "jump sign_change_END\n");
  fprintf(out, "sign_change_INT:\n");
  fprintf(out, "seq $1, #1, '-'\n");
  fprintf(out, "brnz sign_change_INT_FLIP, $1\n");
  fprintf(out, "jump sign_change_END\n");
  fprintf(out, "sign_change_INT_FLIP:\n");
  fprintf(out, "mul $0, $0, -1\n");
  fprintf(out, "jump sign_change_END\n");
  fprintf(out, "sign_change_END:\n");
  fprintf(out, "mov #0[1], $0\n");
  fprintf(out, "return\n\n");
}

static void asm_set_bool(FILE *out) {
  fprintf(out, "set_bool:\n");
  fprintf(out, "brnz set_bool_TRUE, #0\n");
  fprintf(out, "mov $0, 0\n");
  fprintf(out, "jump set_bool_END\n");
  fprintf(out, "set_bool_TRUE:\n");
  fprintf(out, "mov $0, 1\n");
  fprintf(out, "set_bool_END:\n");
  fprintf(out, "return $0\n\n");
}

static void asm_generate_utils(FILE *out) {
  asm_cast(out);
  asm_set_var_val(out);
  asm_get_var_val(out);
  asm_sign_flip(out);
  asm_set_bool(out);
}

static void asm_read(FILE *out) {
  fprintf(out, "read:\n");
  fprintf(out, "mov $0, #0[0]\n");
  fprintf(out, "seq $0, $0, 2\n");
  fprintf(out, "brz read_INT, $0\n");
  fprintf(out, "scanf $1\n");
  fprintf(out, "jump read_END\n");
  fprintf(out, "read_INT:\n");
  fprintf(out, "scani $1\n");
  fprintf(out, "read_END:\n");
  fprintf(out, "mov #0[1], $1\n");
  fprintf(out, "return\n\n");
}

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
  fprintf(out, "return\n\n");
}

static void asm_writeln(FILE *out) {
  fprintf(out, "writeln:\n");
  fprintf(out, "param #0\n");
  fprintf(out, "param #1\n");
  fprintf(out, "call write, 2\n");
  fprintf(out, "println\n");
  fprintf(out, "return\n\n");
}

static void asm_generate_builtin_funcs(FILE *out) {
  asm_read(out);
  asm_write(out);
  asm_writeln(out);
}

static void asm_list_peek(FILE *out) {
  fprintf(out, "list_peek:\n");
  fprintf(out, "mov $0, #0[2]\n");
  fprintf(out, "mov $0, $0[#1]\n");
  fprintf(out, "return $0\n\n");
}

static void asm_list_insert(FILE *out) {
  fprintf(out, "list_insert:\n");
  fprintf(out, "mema $0, 3\n");
  fprintf(out, "mov $1, #0[0]\n");
  fprintf(out, "mov $0[0], $1\n");
  fprintf(out, "mov $1, #0[1]\n");
  fprintf(out, "add $1, $1, 1\n");
  fprintf(out, "mov $0[1], $1\n");
  fprintf(out, "mov $2, $1\n");
  fprintf(out, "mema $1, $2\n");
  fprintf(out, "mema $2, 2\n");
  fprintf(out, "mov $3, #1[0]\n");
  fprintf(out, "mov $2[0], $3\n");
  fprintf(out, "mov $3, #1[1]\n");
  fprintf(out, "mov $2[1], $3\n");
  fprintf(out, "mov $1[0], $2\n");
  fprintf(out, "list_insert_FOR:\n");
  fprintf(out, "mov $2, 0\n");
  fprintf(out, "list_insert_LOOP:\n");
  fprintf(out, "mov $3, #0[1]\n");
  fprintf(out, "slt $3, $2, $3\n");
  fprintf(out, "brz list_insert_END, $3 \n");
  fprintf(out, "param #0\n");
  fprintf(out, "param $2\n");
  fprintf(out, "call list_peek, 2\n");
  fprintf(out, "pop $3\n");
  fprintf(out, "add $4, $2, 1\n");
  fprintf(out, "mov $1[$4], $3\n");
  fprintf(out, "add $2, $2, 1\n");
  fprintf(out, "jump list_insert_LOOP\n");
  fprintf(out, "list_insert_END:\n");
  fprintf(out, "mov $0[2], $1\n");
  fprintf(out, "return $0\n\n");
}

static void asm_list_head(FILE *out) {
  fprintf(out, "list_head:\n");
  fprintf(out, "param #0\n");
  fprintf(out, "param 0\n");
  fprintf(out, "call list_peek, 2\n");
  fprintf(out, "pop $0\n");
  fprintf(out, "return $0\n\n");
}

static void asm_list_tail(FILE *out) {
  fprintf(out, "list_tail:\n");
  fprintf(out, "mema $0, 3\n");
  fprintf(out, "mov $1, #0[0]\n");
  fprintf(out, "mov $0[0], $1\n");
  fprintf(out, "mov $1, #0[1]\n");
  fprintf(out, "sub $1, $1, 1\n");
  fprintf(out, "mov $0[1], $1\n");
  fprintf(out, "mov $2, $1\n");
  fprintf(out, "mema $1, $2\n");
  fprintf(out, "list_tail_FOR:\n");
  fprintf(out, "mov $2, 1\n");
  fprintf(out, "list_tail_LOOP:\n");
  fprintf(out, "mov $3, #0[1]\n");
  fprintf(out, "slt $3, $2, $3\n");
  fprintf(out, "brz list_tail_END, $3 \n");
  fprintf(out, "param #0\n");
  fprintf(out, "param $2\n");
  fprintf(out, "call list_peek, 2\n");
  fprintf(out, "pop $3\n");
  fprintf(out, "sub $4, $2, 1\n");
  fprintf(out, "mov $1[$4], $3\n");
  fprintf(out, "add $2, $2, 1\n");
  fprintf(out, "jump list_tail_LOOP\n");
  fprintf(out, "list_tail_END:\n");
  fprintf(out, "mov $0[2], $1\n");
  fprintf(out, "return $0\n\n");
}

static void asm_list_pop_tail(FILE *out) {
  fprintf(out, "list_pop_tail:\n");
  fprintf(out, "param #0\n");
  fprintf(out, "call list_tail, 1\n");
  fprintf(out, "pop $0\n");
  fprintf(out, "mov $1, $0[1]\n");
  fprintf(out, "mov #0[1], $1\n");
  fprintf(out, "mov $1, $0[2]\n");
  fprintf(out, "mov #0[2], $1\n");
  fprintf(out, "return #0\n\n");
}

static void asm_generate_list_utils(FILE *out) {
  asm_list_peek(out);
  asm_list_insert(out);
  asm_list_head(out);
  asm_list_tail(out);
  asm_list_pop_tail(out);
}

void asm_generate_code_header(FILE *out) {
  fprintf(out, ".code\n");
  asm_generate_utils(out);
  asm_generate_builtin_funcs(out);
  asm_generate_list_utils(out);
  fprintf(out, "main:\n\n");
}

void asm_generate_code_end(FILE *out) {
  fprintf(out, "jump func_main\n");
  fprintf(out, "\nEOF:\n");
  fprintf(out, "nop\n");
}