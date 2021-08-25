#include "data-structures/ast/types/user-func.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "core/globals.h"

static void update_scope(AST *params, Scope *scope) {
  ListNode *it = params->value.params->value;
  while (it) {
    ListNode *tmp = it->next;
    AST *symref = it->data;
    symref->value.symref->symbol->scope = scope->index;
    it = tmp;
  }
}

AST *ast_userfunc_init(Scope *scope, AST *declarator, AST *params) {
  UserFuncAST *ast = calloc(1, sizeof(UserFuncAST));
  ast->scope = scope;
  update_scope(params, ast->scope);
  return ast_cast(AST_USER_FUNC, 2, ast, declarator, params);
}

void ast_userfunc_free(AST *ast) {
  UserFuncAST *userfunc_ast = ast->value.userfunc;
  list_free(ast->children, ast_child_free);
  scope_free(userfunc_ast->scope);
  free(userfunc_ast);
}

double ast_userfunc_eval(AST *ast) { return 0; }

void ast_userfunc_print(AST *ast) {
  printf("user_func: { ");
  ast_print(ast->children->data);
  ast_print(ast->children->next->data);
  printf("}");
}
