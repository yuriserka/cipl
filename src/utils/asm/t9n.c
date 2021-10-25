#include "utils/asm/t9n.h"

#include "core/globals.h"

T9nUnit *t9n_init() {
  T9nUnit *t9n = calloc(1, sizeof(T9nUnit));
  t9n->temp = current_context ? current_context->t9n->temp : 0;
  t9n->param = 0;
  t9n->label = 0;
  return t9n;
}

void t9n_free(T9nUnit *t9n) { free(t9n); }

char *t9n_prefix(SymbolKinds kind) { return kind == PARAM ? "#" : "$"; }

void t9n_alloc_from_other_value(int to, int from, SymbolTypes type,
                                SymbolKinds kind, FILE *out) {
  switch (type) {
    case SYM_INT:
    case SYM_REAL:
      fprintf(out, "mema $%d, 2\n", to);
      fprintf(out, "mov $%d[0], %d\n", to, type);
      fprintf(out, "mov $%d[1], $%d\n", to, from);
      break;
    default:
      fprintf(out, "mema $%d, 3\n", to);
      fprintf(out, "mov $%d[0], %d\n", to, type);
      fprintf(out, "mov $%d, $%d[1]\n", current_context->t9n->temp, from);
      fprintf(out, "mov $%d[1], $%d\n", to, current_context->t9n->temp);
      fprintf(out, "mov $%d, $%d[2]\n", current_context->t9n->temp, from);
      fprintf(out, "mov $%d[2], $%d\n", to, current_context->t9n->temp);
  }
}

void t9n_alloc_from_other_var(int to, int from, SymbolTypes type,
                              SymbolKinds kind, FILE *out) {
  switch (type) {
    case SYM_INT:
    case SYM_REAL:
      fprintf(out, "mema $%d, 2\n", to);
      fprintf(out, "mov $%d[0], %d\n", to, type);
      fprintf(out, "mov $%d, %s%d[1]\n", to + 1, t9n_prefix(kind), from);
      fprintf(out, "mov $%d[1], $%d\n\n", to, to + 1);
      break;
    default:
      fprintf(out, "mema $%d, 3\n", to);
      fprintf(out, "mov $%d[0], %d\n", to, type);
      fprintf(out, "mov $%d, %s%d[1]\n", to + 1, t9n_prefix(kind), from);
      fprintf(out, "mov $%d[1], $%d\n", to, to + 1);
      fprintf(out, "mov $%d, %s%d[2]\n", to + 2, t9n_prefix(kind), from);
      fprintf(out, "mov $%d[2], $%d\n\n", to, to + 2);
  }
}

void t9n_alloc_from_literal(int to, int str_tb_ref, FILE *out) {
  fprintf(out, "mema $%d, 2\n", to);
  fprintf(out, "mov $%d[0], %d\n", to, SYM_PTR);
  fprintf(out, "mov $%d[1], &str_%d\n", to, str_tb_ref);
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
      fprintf(out, "mov $%d[1], 0\n", to);
      fprintf(out, "mema $%d, 0\n", current_context->t9n->temp + 1);
      fprintf(out, "mov $%d[2], $%d\n", to, current_context->t9n->temp + 1);
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
  fprintf(out, "\n");
}
