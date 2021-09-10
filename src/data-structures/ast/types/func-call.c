#include "data-structures/ast/types/func-call.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/context.h"
#include "utils/io.h"

AST *ast_funcall_init(AST *declarator, AST *args) {
  FunctionCallAST *ast = calloc(1, sizeof(FunctionCallAST));
  return ast_cast(AST_FUNC_CALL, 2, ast, declarator, args);
}

void ast_funcall_free(AST *ast) {
  FunctionCallAST *funcall_ast = ast->value.funcall;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(funcall_ast);
}

SymbolValues ast_funcall_eval(AST *ast) { return (SymbolValues){.integer = 0}; }

void ast_funcall_print(AST *ast) {
  AST *declarator = list_peek(&ast->children, 0);
  AST *args = list_peek(&ast->children, 1);
  printf("function_call: { ");
  ast_child_print_aux_label("declarator", declarator);
  ast_child_print_aux_label("args", args);
  printf("}");
}

void ast_funcall_print_pretty(AST *ast, int depth) {
  AST *declarator = list_peek(&ast->children, 0);
  AST *args = list_peek(&ast->children, 1);

  for (int i = depth; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<function-call>\n");

  ast_print_pretty(declarator, depth + 1);
  ast_print_pretty(args, depth + 1);
}
