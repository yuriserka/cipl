#include "data-structures/ast/types/assign.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils/io.h"

AST *ast_assign_init(AST *symbol, AST *value) {
  AssignAST *ast = calloc(1, sizeof(AssignAST));
  ast->op = '=';
  return ast_cast(AST_ASSIGN_OP, 2, ast, symbol, value);
}

void ast_assign_free(AST *ast) {
  AssignAST *assign_ast = ast->value.assignop;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(assign_ast);
}

double ast_assign_eval(AST *ast) {
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);
  lhs->value.symref->symbol->value = ast_eval(rhs);
  return lhs->value.symref->symbol->value;
}

void ast_assign_print(AST *ast) {
  AssignAST *assign_ast = ast->value.assignop;
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);
  printf("assing_op: { op: %c, ", assign_ast->op);
  ast_child_print_aux_label("lhs", lhs);
  ast_child_print_aux_label("rhs", rhs);
  printf("}");
}

void ast_assign_print_pretty(AST *ast, int depth) {
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);

  for (int i = depth; i > 0; --i) printf("\t");

  printf("<assign>\n");
  ast_print_pretty(lhs, depth + 1);

  for (int i = depth + 1; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BBLU, "=\n");

  ast_print_pretty(rhs, depth + 1);
}