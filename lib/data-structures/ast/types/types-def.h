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
  AST_PROG,
  AST_USER_FUNC,
  AST_PARAMS,
  AST_BLOCK_ITEM_LIST,
  AST_JMP,
  AST_DECLARATION,
  AST_ITER,
  AST_FUNC_CALL,
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
    case AST_PROG:
      return "AST_PROG";
    case AST_USER_FUNC:
      return "AST_USER_FUNC";
    case AST_PARAMS:
      return "AST_PARAMS";
    case AST_BLOCK_ITEM_LIST:
      return "AST_BLOCK_ITEM_LIST";
    case AST_DECLARATION:
      return "AST_DECLARATION";
    default:
      return NULL;
  }
}
