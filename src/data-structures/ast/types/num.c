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

SymbolValues ast_number_eval(AST *ast) {
  NumberAST *num_ast = ast->value.number;
  switch (num_ast->num_type) {
    case K_REAL:
      return (SymbolValues){.real = num_ast->value.real};
    case K_INTEGER:
      return (SymbolValues){.integer = num_ast->value.integer};
    default:
      return (SymbolValues){.integer = 0};
  }
}

void ast_number_print(AST *ast) {
  NumberAST *num_ast = ast->value.number;

  switch (num_ast->num_type) {
    case K_REAL:
      printf("number: %lf", (double)num_ast->value.integer);
      break;
    case K_INTEGER:
      printf("number: %lf", num_ast->value.real);
      break;
    default:
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
    default:
      CIPL_PRINTF_COLOR(BYEL, "NIL\n");
      break;
  }
}
