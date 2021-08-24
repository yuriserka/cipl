#include "data-structures/ast/types/types-def.h"

#include "utils/io.h"

const char *ast_type2str(AstTypes type) {
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
    default:
      cipl_perror("undefined AstType: %d\n", type);
  }
  return NULL;
}