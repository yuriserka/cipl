#include "data-structures/ast/types/user-func.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "data-structures/context.h"

AST *ast_userfunc_init(Context *context, AST *declarator, AST *params,
                       AST *stmts) {
  UserFuncAST *ast = calloc(1, sizeof(UserFuncAST));
  ast->context = context;
  LIST_FOR_EACH(params->value.params->value, {
    Symbol *sym = ((AST *)__IT__->data)->value.symref->symbol;
    free(sym->context_name);
    sym->context_name = strdup(context->name);
    sym->scope = context->current_scope;
  });

  return ast_cast(AST_USER_FUNC, 3, ast, declarator, params, stmts);
}

void ast_userfunc_free(AST *ast) {
  UserFuncAST *userfunc_ast = ast->value.userfunc;
  list_free(ast->children, ast_child_free);
  free(userfunc_ast);
}

double ast_userfunc_eval(AST *ast) { return 0; }

void ast_userfunc_print(AST *ast) {
  AST *name = list_peek(&ast->children, 0);
  AST *params = list_peek(&ast->children, 1);
  AST *statements = list_peek(&ast->children, 2);
  printf("user_func: { ");
  ast_print(name);
  ast_print(params);
  ast_print(statements);
  printf("}");
}
