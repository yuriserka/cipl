#pragma once

typedef enum cipl_ast_number_type {
  K_INTEGER,
  K_REAL,
  K_NIL,
} NumberType;

typedef union cipl_ast_number_value {
  int integer;
  double real;
} NumberValue;

#include "data-structures/symbol-table/symbol.h"

typedef struct cipl_ast_number {
  NumberType num_type;
  NumberValue value;
  SymbolTypes sym_type;
} NumberAST;

#include "data-structures/ast/ast.h"

void ast_number_free(AST *ast);
AST *ast_number_init(NumberType type, NumberValue value);
double ast_number_eval(AST *ast);
void ast_number_print(AST *ast);
void ast_number_print_pretty(AST *ast, int depth);
