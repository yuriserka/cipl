#include "data-structures/ast/types/func-call.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/context.h"

AST *ast_funcall_init(AST *declarator, AST *args) {
  FunctionCallAST *ast = calloc(1, sizeof(FunctionCallAST));
  return ast_cast(AST_FUNC_CALL, 2, ast, declarator, args);
}

void ast_funcall_free(AST *ast) {
  FunctionCallAST *funcall_ast = ast->value.funcall;
  list_free(ast->children, ast_child_free);
  free(funcall_ast);
}

double ast_funcall_eval(AST *ast) { return 0; }

void ast_funcall_print(AST *ast) {
  AST *declarator = list_peek(&ast->children, 0);
  AST *args = list_peek(&ast->children, 1);
  printf("function_call: { ");
  ast_child_print_aux_label("declarator", declarator);
  ast_child_print_aux_label("args", args);
  printf("}");
}