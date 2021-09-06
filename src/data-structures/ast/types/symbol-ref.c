#include "data-structures/ast/types/symbol-ref.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/io.h"

AST *ast_symref_init(Symbol *symbol) {
  SymbolRefAST *ast = calloc(1, sizeof(SymbolRefAST));
  ast->symbol = symbol;
  return ast_cast(AST_SYM_REF, 0, ast);
}

void ast_symref_free(AST *ast) {
  SymbolRefAST *symref_ast = ast->value.symref;
  symbol_free(symref_ast->symbol);
  free(symref_ast);
}

double ast_symref_eval(AST *ast) { return ast->value.symref->symbol->value; }

void ast_symref_print(AST *ast) {
  SymbolRefAST *symref = ast->value.symref;
  Cursor pos = symref->symbol->def_pos;
  printf(
      "symbol_ref: { name: %s, type: %s, defined_at: { context: %s, scope: %d, "
      "line: %d, "
      "col: %d, }, }",
      symref->symbol->name, symbol_type_from_enum(symref->symbol->type),
      symref->symbol->context_name, symref->symbol->scope, pos.line, pos.col);
}

void ast_symref_print_pretty(AST *ast, int depth) {
  SymbolRefAST *symref = ast->value.symref;

  for (int i = depth; i > 0; --i) printf("\t");
  symbol_print_pretty(symref->symbol);
}
