#include "data-structures/ast/types/cmp-op.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int str_eq(const char *s1, const char *s2) { return !strcmp(s1, s2); }

AST *ast_cmpop_init(char *op, AST *l, AST *r) {
  ComparisonAST *ast = calloc(1, sizeof(ComparisonAST));
  ast->op = strdup(op);
  if (str_eq(op, "<"))
    ast->type = CMP_LT;
  else if (str_eq(op, ">"))
    ast->type = CMP_GT;
  else if (str_eq(op, ">="))
    ast->type = CMP_GE;
  else if (str_eq(op, "<="))
    ast->type = CMP_LE;
  else if (str_eq(op, "=="))
    ast->type = CMP_EQ;
  else if (str_eq(op, "!="))
    ast->type = CMP_NE;

  return ast_cast(AST_CMP_OP, 2, ast, l, r);
}

void ast_cmpop_free(AST *ast) {
  ComparisonAST *cmp_ast = ast->value.cmpop;
  list_free(ast->children, ast_child_free);
  free(cmp_ast->op);
  free(cmp_ast);
}

double ast_cmpop_eval(AST *ast) {
  ComparisonAST *cmp_ast = ast->value.cmpop;
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);

  switch (cmp_ast->type) {
    case CMP_LT:
      return (ast_eval(lhs) < ast_eval(rhs)) ? 1 : 0;
    case CMP_GT:
      return (ast_eval(lhs) > ast_eval(rhs)) ? 1 : 0;
    case CMP_LE:
      return (ast_eval(lhs) <= ast_eval(rhs)) ? 1 : 0;
    case CMP_GE:
      return (ast_eval(lhs) >= ast_eval(rhs)) ? 1 : 0;
    case CMP_EQ:
      return (ast_eval(lhs) == ast_eval(rhs)) ? 1 : 0;
    case CMP_NE:
      return (ast_eval(lhs) != ast_eval(rhs)) ? 1 : 0;
  }

  return 0;
}

static void ast_cmp_print_aux(const char *label, AST *ast) {
  printf("%s: { ", label);
  if (ast) ast_print(ast);
  printf("}, ");
}

void ast_cmpop_print(AST *ast) {
  ComparisonAST *cmp_ast = ast->value.cmpop;
  AST *lhs = list_peek(&ast->children, 0);
  AST *rhs = list_peek(&ast->children, 1);
  printf("compare_op: { op: %s, ", cmp_ast->op);
  ast_cmp_print_aux("lhs", lhs);
  ast_cmp_print_aux("rhs", rhs);
  printf("}");
}
