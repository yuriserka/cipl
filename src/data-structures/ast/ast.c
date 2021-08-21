#include "data-structures/ast/ast.h"

#include <stdio.h>
#include <stdlib.h>

AST *ast_cast(AST *ast, AstTypes type, int n, ...) {
  ast->type = type;
  va_list ptr;
  va_start(ptr, n);
  for (int i = 0; i < n; ++i) {
    list_push(&ast->children, va_arg(ptr, AST *));
  }
  va_end(ptr);
  return ast;
}

double ast_eval(AST *ast) {
  switch (ast->type) {
    case AST_NUMBER_INT:
    case AST_NUMBER_REAL:
      return ast_number_eval(ast);
    case AST_BIN_OP:
      return ast_binop_eval(ast);
    case AST_UNI_OP:
      return ast_uniop_eval(ast);
    default:
      printf("internal error: bad node %d\n", ast->type);
  }
  return 0;
}

void ast_print(AST *ast) {
  switch (ast->type) {
    case AST_NUMBER_INT:
    case AST_NUMBER_REAL:
      ast_number_print(ast);
      break;
    case AST_BIN_OP:
      ast_binop_print(ast);
      break;
    case AST_UNI_OP:
      ast_uniop_print(ast);
      break;
  }
  printf(", ");
}
