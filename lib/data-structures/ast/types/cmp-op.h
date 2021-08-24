#pragma once

typedef enum cipl_comparison_type {
  CMP_LT,
  CMP_GT,
  CMP_LE,
  CMP_GE,
  CMP_EQ,
  CMP_NE,
} ComparisonTypes;

typedef struct cipl_ast_cmpop {
  char *op;
  ComparisonTypes type;
} ComparisonAST;

#include "data-structures/ast/ast.h"

void ast_cmpop_free(AST *ast);
AST *ast_cmpop_init(char *op, AST *l, AST *r);
double ast_cmpop_eval(AST *ast);
void ast_cmpop_print(AST *ast);
