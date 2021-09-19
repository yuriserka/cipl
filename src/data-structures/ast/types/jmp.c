#include "data-structures/ast/types/jmp.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/context.h"
#include "utils/io.h"

AST *ast_jmp_init(YYLTYPE rule_pos, AST *stmt) {
  JumpAST *ast = calloc(1, sizeof(JumpAST));
  return ast_cast(AST_JMP, rule_pos, 1, ast, stmt);
}

void ast_jmp_free(AST *ast) {
  JumpAST *flow_ast = ast->value.jmp;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(flow_ast);
}

SymbolValues ast_jmp_eval(AST *ast) { return (SymbolValues){.integer = 0}; }

void ast_jmp_print(AST *ast) {
  AST *stmt = list_peek(&ast->children, 0);
  printf("return: { ");
  ast_child_print_aux_label("statement", stmt);
  printf("}");
}

void ast_jmp_print_pretty(AST *ast, int depth) {
  AST *stmt = list_peek(&ast->children, 0);

  for (int i = depth; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<return-statement>\n");

  ast_print_pretty(stmt, depth + 1);
}

SymbolTypes ast_jmp_type_check(AST *ast) {
  AST *stmt = list_peek(&ast->children, 0);
  SymbolTypes ret_t = ast_validate_types(stmt);
  // printf("JMP_T: { EXPR_T: %s }\n", symbol_type_from_enum(ret_t));
  return ret_t;
}
