#pragma once

struct cipl_context;

typedef struct cipl_ast_userfunc {
  struct cipl_context *context;
  int arity;
} UserFuncAST;

#include "data-structures/ast/ast.h"

void ast_userfunc_free(AST *ast);
AST *ast_userfunc_init(YYLTYPE rule_pos, struct cipl_context *context,
                       AST *declarator, AST *params, AST *statements);
SymbolValues ast_userfunc_eval(AST *ast);
void ast_userfunc_print(AST *ast);
void ast_userfunc_print_pretty(AST *ast, int depth);
void ast_userfunc_gen_code(AST *ast, FILE *out);

SymbolTypes ast_userfunc_type_check(AST *ast);
