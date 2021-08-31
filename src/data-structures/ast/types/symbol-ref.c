#include "data-structures/ast/types/symbol-ref.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AST *ast_symref_init(char *type, Symbol *symbol) {
  SymbolRefAST *ast = calloc(1, sizeof(SymbolRefAST));
  ast->symbol = symbol;
  ast->type = symbol_type_from_str(type);
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
  cursor_position pos = symref->symbol->def_pos;
  printf(
      "symbol_ref: { name: %s, type: %s, defined_at: { context: %s, line: %d, "
      "col: %d, }, }",
      symref->symbol->name, symbol_type_from_enum(symref->type),
      symref->symbol->context_name, pos.line, pos.col);
}

SymbolTypes symbol_type_from_str(char *type) {
  if (!type) return SYM_INVALID;

  if (!strcmp(type, "int")) return SYM_INT;
  if (!strcmp(type, "float")) return SYM_REAL;
  if (!strcmp(type, "int list")) return SYM_INT_LIST;
  if (!strcmp(type, "float list")) return SYM_REAL_LIST;

  return SYM_INVALID;
}

const char *symbol_type_from_enum(SymbolTypes type) {
  switch (type) {
    case SYM_INT:
      return "SYM_INT";
    case SYM_INT_LIST:
      return "SYM_INT_LIST";
    case SYM_REAL:
      return "SYM_REAL";
    case SYM_REAL_LIST:
      return "SYM_REAL_LIST";
    default:
      return "SYM_INVALID";
  }
}