#include "data-structures/ast/types/symbol-ref.h"

#include <stdio.h>
#include <stdlib.h>

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
  Symbol *sym = ast->value.symref->symbol;
  cursor_position pos = sym->def_pos;
  printf(
      "symbol_ref: { name: %s, defined_at: { context: %s, scope: %d, line: %d, "
      "col: %d, }, }",
      sym->name, sym->context_name, sym->scope, pos.line, pos.col);
}
