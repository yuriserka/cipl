#pragma once

#include <stdlib.h>

typedef enum cipl_ast_types {
  AST_ASSIGN_OP,
  AST_BUILTIN_FUNC,
  AST_FLOW,
  AST_NUMBER,
  AST_SYM_REF,
  AST_BIN_OP,
  AST_UNI_OP,
  AST_PROG,
  AST_USER_FUNC,
  AST_PARAM_LIST,
  AST_BLOCK_ITEM_LIST,
  AST_JMP,
  AST_DECLARATION,
  AST_ITER,
  AST_FUNC_CALL,
  AST_STR_LITERAL,
} AstTypes;

static inline const char *ast_type2str(AstTypes type) {
  switch (type) {
    case AST_ASSIGN_OP:
      return "AST_ASSIGN_OP";
    case AST_BUILTIN_FUNC:
      return "AST_BUILTIN_FUNC";
    case AST_FLOW:
      return "AST_FLOW";
    case AST_NUMBER:
      return "AST_NUMBER";
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
    case AST_PARAM_LIST:
      return "AST_PARAM_LIST";
    case AST_BLOCK_ITEM_LIST:
      return "AST_BLOCK_ITEM_LIST";
    case AST_DECLARATION:
      return "AST_DECLARATION";
    case AST_STR_LITERAL:
      return "AST_STR_LITERAL";
    default:
      return NULL;
  }
}
