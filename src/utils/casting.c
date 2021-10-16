#include "utils/casting.h"

#include "utils/io.h"

#define CAST(__K__, __D__) ((CastInfo){.kind = (__K__), .direction = (__D__)})

CastInfo cast_info_none() {
  CastInfo ci;
  ci.data_type = SYM_INVALID;
  ci.direction = NONE;
  ci.kind = NO_CAST;
  return ci;
}

CastInfo cast_info_with_type(CastInfo info, SymbolTypes type) {
  CastInfo nci = CAST(info.kind, info.direction);
  nci.data_type = type;
  return nci;
}

CastInfo cast_info_binop(SymbolTypes t1, SymbolTypes t2) {
  if (!should_cast(t1, t2)) return cast_info_none();

  if (t1 < SYM_PTR && t2 < SYM_PTR) {
    if (t1 < t2) return CAST(INT_TO_FLOAT, L_CAST);
    if (t1 > t2) return CAST(INT_TO_FLOAT, R_CAST);
  }

  if (t1 > SYM_PTR) {
    if ((t1 - SYM_PTR) > t2) return CAST(INT_TO_FLOAT, R_CAST);
    if ((t1 - SYM_PTR) < t2) return CAST(FLOAT_TO_INT, R_CAST);
  }

  if (t2 > SYM_PTR) {
    if (t1 > (t2 - SYM_PTR)) return CAST(FLOAT_TO_INT, L_CAST);
    if (t1 < (t2 - SYM_PTR)) return CAST(INT_TO_FLOAT, L_CAST);
  }

  return cast_info_none();
}

CastInfo cast_info_assign(SymbolTypes t1, SymbolTypes t2) {
  if (!should_cast(t1, t2)) return cast_info_none();

  if (t1 < SYM_PTR && t2 < SYM_PTR) {
    if (t1 < t2) return CAST(FLOAT_TO_INT, R_CAST);
    if (t1 > t2) return CAST(INT_TO_FLOAT, R_CAST);
  }

  return cast_info_none();
}

void print_cast(CastInfo info, int depth) {
  if (info.kind != NONE)
    printf("%*.s" BMAG "<%s>" RESET "\n", (depth + 1) * 4, "",
           info.kind == FLOAT_TO_INT ? "fltoint" : "inttofl");
}

void cast_gen_code(CastInfo info, int temp, FILE *out) {
  if (info.kind != NONE) {
    fprintf(out, "pop $%d\n", temp);
    fprintf(out, "param $%d\n", temp);
    fprintf(out, "param %d\n", info.kind == FLOAT_TO_INT ? 1 : 2);
    fprintf(out, "call cast, 2\n");
    fprintf(out, "pop $%d\n", temp);
    fprintf(out, "push $%d\n\n", temp);
  }
}
