#include "data-structures/ast/types/assign.h"

#include <stdio.h>
#include <stdlib.h>

AST *ast_assign_init(AST *symbol, AST *value) {
  AssignAST *ast = calloc(1, sizeof(AssignAST));
  ast->op = '=';
  return ast_cast(AST_ASSIGN_OP, 2, ast, symbol, value);
}

void ast_assign_free(AST *ast) {
  AssignAST *assign_ast = ast->value.assignop;
  list_free(ast->children, ast_child_free);
  free(assign_ast);
}

double ast_assign_eval(AST *ast) {
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);
  lhs->value.symref->symbol->value = ast_eval(rhs);
  return lhs->value.symref->symbol->value;
}

static void ast_assign_print_aux(const char *label, AST *ast) {
  printf("%s: { ", label);
  ast_print(ast);
  printf("}, ");
}

void ast_assign_print(AST *ast) {
  AssignAST *assign_ast = ast->value.assignop;
  AST *lhs = ast->children->data;
  AST *rhs = ast->children->next->data;
  printf("assing_op: { op: %c, ", assign_ast->op);
  ast_assign_print_aux("lhs", lhs);
  ast_assign_print_aux("rhs", rhs);
  printf("}");
}
