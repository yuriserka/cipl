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
