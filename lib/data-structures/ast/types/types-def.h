#pragma once

#include <stdlib.h>

typedef enum cipl_ast_types {
  AST_ASSIGN_OP,
  AST_BUILTIN_FUNC,
  AST_FLOW,
  AST_NUMBER_INT,
  AST_NUMBER_REAL,
  AST_SYM_REF,
  AST_BIN_OP,
  AST_UNI_OP,
  AST_CMP_OP,
  AST_PROG,
} AstTypes;

static inline const char *ast_type2str(AstTypes type) {
  switch (type) {
    case AST_ASSIGN_OP:
      return "AST_ASSIGN_OP";
    case AST_BUILTIN_FUNC:
      return "AST_BUILTIN_FUNC";
    case AST_FLOW:
      return "AST_FLOW";
    case AST_NUMBER_INT:
      return "AST_NUMBER_INT";
    case AST_NUMBER_REAL:
      return "AST_NUMBER_REAL";
    case AST_SYM_REF:
      return "AST_SYM_REF";
    case AST_BIN_OP:
      return "AST_BIN_OP";
    case AST_UNI_OP:
      return "AST_UNI_OP";
    case AST_CMP_OP:
      return "AST_CMP_OP";
    case AST_PROG:
      return "AST_PROG";
    default:
      return NULL;
  }
}
