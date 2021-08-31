#include "data-structures/ast/types/num.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils/io.h"

AST *ast_number_init(NumberType number_type, NumberValue value) {
  NumberAST *ast = calloc(1, sizeof(NumberAST));
  ast->num_type = number_type;
  ast->value = value;
  ast->sym_type = K_INTEGER || K_NIL ? SYM_INT : SYM_REAL;
  return ast_cast(AST_NUMBER, 0, ast);
}

void ast_number_free(AST *ast) { free(ast->value.number); }

double ast_number_eval(AST *ast) {
  NumberAST *num_ast = ast->value.number;
  return num_ast->num_type == K_REAL
             ? num_ast->value.real
             : (K_INTEGER ? (double)(num_ast->value.integer) : 0);
}

void ast_number_print(AST *ast) {
  NumberAST *num_ast = ast->value.number;

  switch (num_ast->num_type) {
    case K_REAL:
    case K_INTEGER:
      printf("number: %lf", ast_number_eval(ast));
      break;
    case K_NIL:
      printf("constant: NIL");
      break;
  }
}

void ast_number_print_pretty(AST *ast, int depth) {
  NumberAST *num_ast = ast->value.number;

  for (int i = depth; i > 0; --i) printf("\t");

  switch (num_ast->num_type) {
    case K_REAL:
      CIPL_PRINTF_COLOR(BYEL, "%lf\n", num_ast->value.real);
      break;
    case K_INTEGER:
      CIPL_PRINTF_COLOR(BYEL, "%d\n", num_ast->value.integer);
      break;
    case K_NIL:
      CIPL_PRINTF_COLOR(BYEL, "NIL\n");
      break;
  }
}
