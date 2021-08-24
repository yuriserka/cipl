#pragma once

typedef enum cipl_ast_number_type {
  INTEGER,
  REAL,
} NumberType;

typedef union cipl_ast_number_value {
  int integer;
  double real;
} NumberValue;

typedef struct cipl_ast_number {
  int type;
  NumberType num_type;
  NumberValue value;
} NumberAST;

#include "data-structures/ast/ast.h"

void ast_number_free(AST *ast);
AST *ast_number_init(NumberType type, NumberValue value);
double ast_number_eval(AST *ast);
void ast_number_print(AST *ast);
