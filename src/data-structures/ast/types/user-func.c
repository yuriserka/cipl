#include "data-structures/ast/types/user-func.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "data-structures/context.h"
#include "utils/io.h"

AST *ast_userfunc_init(Context *context, AST *declarator, AST *params,
                       AST *stmts) {
  UserFuncAST *ast = calloc(1, sizeof(UserFuncAST));
  ast->context = context;
  ast->arity = params->value.params->size;
  return ast_cast(AST_USER_FUNC, 3, ast, declarator, params, stmts);
}

void ast_userfunc_free(AST *ast) {
  UserFuncAST *userfunc_ast = ast->value.userfunc;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(userfunc_ast);
}

double ast_userfunc_eval(AST *ast) { return 0; }

void ast_userfunc_print(AST *ast) {
  AST *name = list_peek(&ast->children, 0);
  AST *params = list_peek(&ast->children, 1);
  AST *statements = list_peek(&ast->children, 2);
  printf("user_func: { ");
  ast_child_print_aux_label("name", name);
  ast_print(params);
  ast_print(statements);
  printf("}");
}

void ast_userfunc_print_pretty(AST *ast, int depth) {
  AST *name = list_peek(&ast->children, 0);
  AST *params = list_peek(&ast->children, 1);
  AST *statements = list_peek(&ast->children, 2);

  for (int i = depth; i > 0; --i) printf("\t");

  CIPL_PRINTF_COLOR(BMAG, "<function-declaration>\n");
  ast_print_pretty(name, depth + 1);
  ast_print_pretty(params, depth + 1);
  ast_print_pretty(statements, depth + 1);
}
