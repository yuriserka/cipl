#include "data-structures/ast/ast.h"

#include <stdio.h>
#include <stdlib.h>

AST *ast_cast(AstTypes type, int n_children, ...) {
  AST *ast = calloc(1, sizeof(AST));
  ast->type = type;

  ++n_children;

  va_list ptr;
  va_start(ptr, n_children);

  switch (type) {
    case AST_NUMBER_INT:
    case AST_NUMBER_REAL:
      ast->value = (AstNodeValue){.number = va_arg(ptr, NumberAST *)};
      break;
    case AST_BIN_OP:
      ast->value = (AstNodeValue){.binop = va_arg(ptr, BinOpAST *)};
      break;
    case AST_UNI_OP:
      ast->value = (AstNodeValue){.uniop = va_arg(ptr, UniOpAST *)};
      break;
  }

  --n_children;

  for (int i = 0; i < n_children; ++i) {
    list_push(&ast->children, va_arg(ptr, AST *));
  }

  va_end(ptr);

  return ast;
}

void ast_child_free(ListNode *node) { ast_free(node->data); }

void ast_free(AST *ast) {
  switch (ast->type) {
    case AST_NUMBER_INT:
    case AST_NUMBER_REAL:
      ast_number_free(ast);
      break;
    case AST_BIN_OP:
      ast_binop_free(ast);
      break;
    case AST_UNI_OP:
      ast_uniop_free(ast);
      break;
  }
  free(ast);
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
