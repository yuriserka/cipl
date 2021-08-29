#include "data-structures/ast/types/jmp.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/context.h"

AST *ast_jmp_init(AST *stmt) {
  JumpAST *ast = calloc(1, sizeof(JumpAST));
  return ast_cast(AST_JMP, 1, ast, stmt);
}

void ast_jmp_free(AST *ast) {
  JumpAST *flow_ast = ast->value.jmp;
  list_free(ast->children, ast_child_free);
  free(flow_ast);
}

double ast_jmp_eval(AST *ast) { return 0; }

void ast_jmp_print(AST *ast) {
  AST *stmt = list_peek(&ast->children, 0);
  printf("return: { ");
  ast_child_print_aux_label("statement", stmt);
  printf("}");
}