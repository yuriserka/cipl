#include "data-structures/ast/types/builtin-fn.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/io.h"

void ast_builtinfn_free(AST *ast) {
  BuiltinFuncAST *builtinfn_ast = ast->value.builtinfn;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(builtinfn_ast);
}

AST *ast_builtinfn_init(AST *symref, AST *params) {
  BuiltinFuncAST *ast = calloc(1, sizeof(BuiltinFuncAST));
  ast->func_type = builtinfn_type_from_str(symref->value.symref->symbol->name);
  return ast_cast(AST_BUILTIN_FUNC, 2, ast, symref, params);
}

double ast_builtinfn_eval(AST *ast) { return 0; }

void ast_builtinfn_print(AST *ast) {
  AST *name = list_peek(&ast->children, 0);
  AST *args = list_peek(&ast->children, 1);
  printf("builtin_call: { ");
  ast_child_print_aux_label("name", name);
  ast_child_print_aux_label("args", args);
  printf("}");
}

void ast_builtinfn_print_pretty(AST *ast, int depth) {
  AST *declarator = list_peek(&ast->children, 0);
  AST *args = list_peek(&ast->children, 1);

  for (int i = depth; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<builtin-call>\n");

  ast_print_pretty(declarator, depth + 1);
  ast_print_pretty(args, depth + 1);
}

BuiltInFuncTypes builtinfn_type_from_str(char *sym_name) {
  if (sym_name[0] == 'r') return BUILTIN_FN_READ;
  return strstr(sym_name, "ln") ? BUILTIN_FN_WRITELN : BUILTIN_FN_WRITE;
}