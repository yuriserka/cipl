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
AST *ast_builtinfn_init(AST *name, AST *params);
double ast_builtinfn_eval(AST *ast);
void ast_builtinfn_print(AST *ast);
void ast_builtinfn_print_pretty(AST *ast, int depth);

BuiltInFuncTypes builtinfn_type_from_str(char *sym_name);
