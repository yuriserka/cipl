#include "utils/casting.h"

#include "utils/io.h"

#define CAST(__K__, __D__) ((CastInfo){__K__, __D__})

CastInfo cast_info_none() { return CAST(NONE, NO_CAST); }

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