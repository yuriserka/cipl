#pragma once

#include <stdio.h>

#include "data-structures/ast/types/num.h"

typedef struct {
  int temp;
  int param;
  int label;
} T9nUnit;

T9nUnit *t9n_init();
void t9n_free(T9nUnit *t9n);
char *t9n_prefix(SymbolKinds kind);

void t9n_alloc_from_other_value(int to, int from, SymbolTypes type,
                                SymbolKinds kind, FILE *out);
void t9n_alloc_from_other_var(int to, int from, SymbolTypes type,
                              SymbolKinds kind, FILE *out);
void t9n_alloc_from_constant(int to, SymbolTypes type, NumberValue value,
                             FILE *out);
void t9n_alloc_from_literal(int to, int tb_ref, FILE *out);
void t9n_alloc_decl(int to, SymbolTypes type, FILE *out);

void asm_generate_table_header(FILE *out);
void asm_generate_code_header(FILE *out);
void asm_generate_code_end(FILE *out);

/***
 * the value of current list element is in $(temp + 4)
 * the value to be pushed must be in $(temp + 4)
 * */
#define LIST_MAPFIL_TEMPLATE_GEN_CODE(__CTX__, __SET_TYPE_CODE__, __FE_CODE__) \
  {                                                                            \
    int __TEMP__ = __CTX__->t9n->temp;                                         \
    fprintf(out, "pop $%d\n", __TEMP__);                                       \
    fprintf(out, "mema $%d, 3\n", __TEMP__ + 2);                               \
    __SET_TYPE_CODE__;                                                         \
    fprintf(out, "mov $%d, $%d[1]\n", __TEMP__ + 3, __TEMP__);                 \
    fprintf(out, "mema $%d, $%d\n", __TEMP__ + 1, __TEMP__ + 3);               \
    fprintf(out, "func_%s_list_for_each_L%d_FOR:\n", __CTX__->name,            \
            __CTX__->t9n->label);                                              \
    fprintf(out, "mov $%d, 0\n", __TEMP__ + 3);                                \
    fprintf(out, "mov $%d, 0\n", __TEMP__ + 5);                                \
    fprintf(out, "func_%s_list_for_each_L%d_LOOP:\n", __CTX__->name,           \
            __CTX__->t9n->label);                                              \
    fprintf(out, "mov $%d, $%d[1]\n", __TEMP__ + 4, __TEMP__);                 \
    fprintf(out, "slt $%d, $%d, $%d\n", __TEMP__ + 4, __TEMP__ + 3,            \
            __TEMP__ + 4);                                                     \
    fprintf(out, "brz func_%s_list_for_each_L%d_END, $%d\n", __CTX__->name,    \
            __CTX__->t9n->label, __TEMP__ + 4);                                \
    fprintf(out, "param $%d\n", __TEMP__);                                     \
    fprintf(out, "param $%d\n", __TEMP__ + 3);                                 \
    fprintf(out, "call list_peek, 2\n");                                       \
    fprintf(out, "pop $%d\n", __TEMP__ + 4);                                   \
    __FE_CODE__;                                                               \
    fprintf(out, "func_%s_list_for_each_L%d_ADD:\n", __CTX__->name,            \
            __CTX__->t9n->label);                                              \
    fprintf(out, "pop $%d\n", __TEMP__ + 4);                                   \
    fprintf(out, "mov $%d[$%d], $%d\n", __TEMP__ + 1, __TEMP__ + 5,            \
            __TEMP__ + 4);                                                     \
    fprintf(out, "add $%d, $%d, 1\n", __TEMP__ + 5, __TEMP__ + 5);             \
    fprintf(out, "func_%s_list_for_each_L%d_CONTINUE:\n", __CTX__->name,       \
            __CTX__->t9n->label);                                              \
    fprintf(out, "add $%d, $%d, 1\n", __TEMP__ + 3, __TEMP__ + 3);             \
    fprintf(out, "jump func_%s_list_for_each_L%d_LOOP\n", __CTX__->name,       \
            __CTX__->t9n->label);                                              \
    fprintf(out, "func_%s_list_for_each_L%d_END:\n", __CTX__->name,            \
            __CTX__->t9n->label++);                                            \
    fprintf(out, "mov $%d[1], $%d\n", __TEMP__ + 2, __TEMP__ + 5);             \
    fprintf(out, "mov $%d[2], $%d\n", __TEMP__ + 2, __TEMP__ + 1);             \
  }
