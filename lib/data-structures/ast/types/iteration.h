#pragma once

struct cipl_context;

typedef struct cipl_ast_iteration {
  struct cipl_context *context;
} IterationAST;

#include "data-structures/ast/ast.h"

void ast_iter_free(AST *ast);
AST *ast_iter_init(YYLTYPE rule_pos, struct cipl_context *context, AST *b4_all,
                   AST *b4_each, AST *aftr_each, AST *stmts);
SymbolValues ast_iter_eval(AST *ast);
void ast_iter_print(AST *ast);
void ast_iter_print_pretty(AST *ast, int depth);

SymbolTypes ast_iter_type_check(AST *ast);
