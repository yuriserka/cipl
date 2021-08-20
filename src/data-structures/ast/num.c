#include "data-structures/ast/num.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/ast/ast.h"

AST *ast_number_init(NumberType number_type, NumberValue value) {
  NumberAST *ast = calloc(1, sizeof(NumberAST));
  ast->num_type = number_type;
  ast->type = number_type == INTEGER ? AST_NUMBER_INT : AST_NUMBER_REAL;
  ast->value = value;
  return ast_cast((AST *)ast, ast->type, 0);
}

double ast_number_eval(AST *ast) {
  NumberAST *num_ast = (NumberAST *)ast;
  return num_ast->num_type == REAL ? num_ast->value.real
                                   : (double)(num_ast->value.integer);
}
