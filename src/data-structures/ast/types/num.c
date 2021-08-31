#include "data-structures/ast/types/num.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils/io.h"

AST *ast_number_init(NumberType number_type, NumberValue value) {
  NumberAST *ast = calloc(1, sizeof(NumberAST));
  ast->num_type = number_type;
  ast->value = value;
  ast->sym_type = INTEGER ? SYM_INT : SYM_REAL;
  return ast_cast(INTEGER ? AST_NUMBER_INT : AST_NUMBER_REAL, 0, ast);
}

void ast_number_free(AST *ast) { free(ast->value.number); }

double ast_number_eval(AST *ast) {
  NumberAST *num_ast = ast->value.number;
  return num_ast->num_type == REAL ? num_ast->value.real
                                   : (double)(num_ast->value.integer);
}

void ast_number_print(AST *ast) { printf("number: %lf", ast_number_eval(ast)); }

void ast_number_print_pretty(AST *ast, int depth) {
  NumberAST *num_ast = ast->value.number;

  for (int i = depth; i > 0; --i) printf("\t");

  if (num_ast->num_type == REAL) {
    CIPL_PRINTF_COLOR(BYEL, "%lf\n", num_ast->value.real);
  } else {
    CIPL_PRINTF_COLOR(BYEL, "%d\n", num_ast->value.integer);
  }
}
