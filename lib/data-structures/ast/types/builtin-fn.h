#pragma once

typedef enum cipl_builtin_fn_types {
  BUILTIN_FN_WRITE = 1,
  BUILTIN_FN_WRITELN,
  BUILTIN_FN_READ,
} BuiltInFuncTypes;

typedef struct cipl_ast_builtin_fn {
  BuiltInFuncTypes func_type;
} BuiltinFuncAST;

#include "data-structures/ast/ast.h"

void ast_builtinfn_free(AST *ast);
AST *ast_builtinfn_init(BuiltInFuncTypes func_type, AST *l);
double ast_builtinfn_eval(AST *ast);
void ast_builtinfn_print(AST *ast);
