#pragma once

#include "data-structures/ast/types/types-def.h"

typedef enum cipl_builtin_fn_types {
  BUILTIN_FN_SQRT = 1,
  BUILTIN_FN_EXP,
  BUILTIN_FN_LOG,
  BUILTIN_FN_PRINT,
} BuiltInFuncTypes;

typedef struct cipl_ast_builtin_fn {
  AstTypes type;
  BuiltInFuncTypes func_type;
} BuiltinFuncAST;

#include "data-structures/ast/ast.h"

void ast_builtinfn_free(AST *ast);
AST *ast_builtinfn_init(BuiltInFuncTypes func_type, AST *l);
double ast_builtinfn_eval(AST *ast);
void ast_builtinfn_print(AST *ast);
