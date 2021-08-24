#pragma once

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
} AstTypes;

#define ast_type2str(type) #type
