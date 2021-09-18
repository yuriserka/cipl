#include "data-structures/ast/types/uni-op.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/io.h"

AST *ast_uniop_init(YYLTYPE rule_pos, char *op, AST *l) {
  UniOpAST *ast = calloc(1, sizeof(UniOpAST));
  ast->op = strdup(op);
  return ast_cast(AST_UNI_OP, rule_pos, 1, ast, l);
}

void ast_uniop_free(AST *ast) {
  UniOpAST *uniop_ast = ast->value.uniop;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(uniop_ast->op);
  free(uniop_ast);
}

SymbolValues ast_uniop_eval(AST *ast) { return (SymbolValues){.integer = 0}; }

void ast_uniop_print(AST *ast) {
  UniOpAST *uniop_ast = ast->value.uniop;
  printf("uni_op: { op: '%s', ", uniop_ast->op);
  ast_print(ast->children->data);
  printf("}");
}

void ast_uniop_print_pretty(AST *ast, int depth) {
  AST *lhs = list_peek(&ast->children, 0);
  UniOpAST *uniop_ast = ast->value.uniop;

  for (int i = depth; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<unary-op>\n");

  for (int i = depth + 1; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BBLU, "%s\n", uniop_ast->op);

  ast_print_pretty(lhs, depth + 1);
}
