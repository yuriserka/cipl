#include "data-structures/ast/types/num.h"

#include <stdio.h>
#include <stdlib.h>

AST *ast_number_init(NumberType number_type, NumberValue value) {
  NumberAST *ast = calloc(1, sizeof(NumberAST));
  ast->num_type = number_type;
  ast->type = number_type == INTEGER ? AST_NUMBER_INT : AST_NUMBER_REAL;
  ast->value = value;
  return ast_cast(ast->type, 0, ast);
}

void ast_number_free(AST *ast) { free(ast->value.number); }

double ast_number_eval(AST *ast) {
  NumberAST *num_ast = ast->value.number;
  return num_ast->num_type == REAL ? num_ast->value.real
                                   : (double)(num_ast->value.integer);
}

void ast_number_print(AST *ast) { printf("number: %lf", ast_number_eval(ast)); }
