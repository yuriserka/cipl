#pragma once

#include <stdio.h>

#include "data-structures/symbol-table/symbol.h"

typedef enum cipl_casting_info_kind {
  NONE,
  FLOAT_TO_INT,
  INT_TO_FLOAT
} CastKind;

typedef enum cipl_casting_info_dir { NO_CAST, L_CAST, R_CAST } CastDirection;

typedef struct cipl_casting_info {
  CastKind kind;
  CastDirection direction;
  SymbolTypes data_type;
} CastInfo;

CastInfo cast_info_none();
CastInfo cast_info_binop(SymbolTypes t1, SymbolTypes t2);
CastInfo cast_info_assign(SymbolTypes t1, SymbolTypes t2);
CastInfo cast_info_mapfil(SymbolTypes t1, SymbolTypes t2);
CastInfo cast_info_with_type(CastInfo info, SymbolTypes type);

void print_cast(CastInfo info, int depth);
void cast_gen_code(CastInfo info, int temp, FILE *out);
