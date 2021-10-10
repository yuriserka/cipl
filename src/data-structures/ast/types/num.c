#include "data-structures/ast/types/num.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils/io.h"

AST *ast_number_init(YYLTYPE rule_pos, NumberType number_type,
                     NumberValue value) {
  NumberAST *ast = calloc(1, sizeof(NumberAST));
  ast->num_type = number_type;
  ast->value = value;
  ast->sym_type = number_type == K_INTEGER
                      ? SYM_INT
                      : ((number_type == K_NIL) ? SYM_PTR : SYM_REAL);
  return ast_cast(AST_NUMBER, rule_pos, 0, ast);
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
      printf("number: %ld", num_ast->value.integer);
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
      CIPL_PRINTF_COLOR(BYEL, "%ld\n", num_ast->value.integer);
      break;
    default:
      CIPL_PRINTF_COLOR(BYEL, "NIL\n");
      break;
  }
}

SymbolTypes ast_number_type_check(AST *ast) {
  NumberAST *num_ast = ast->value.number;
  return num_ast->sym_type;
}

void ast_number_gen_code(AST *ast, FILE *out) {
  t9n_alloc_from_constant(current_context->t9n->temp,
                          ast->value.number->sym_type, ast->value.number->value,
                          out);
  fprintf(out, "push $%d\n\n", current_context->t9n->temp);
}

void ast_number_tofloat(AST *ast) {
  NumberAST *num_ast = ast->value.number;
  num_ast->num_type = K_REAL;
  num_ast->value = (NumberValue){.real = (double)num_ast->value.integer};
}

void ast_number_tointeger(AST *ast) {
  NumberAST *num_ast = ast->value.number;
  num_ast->num_type = K_INTEGER;
  num_ast->value = (NumberValue){.integer = (long int)num_ast->value.real};
}
