#include "data-structures/ast/types/symbol-ref.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/asm/asm.h"
#include "utils/io.h"

AST *ast_symref_init(YYLTYPE rule_pos, Symbol *symbol) {
  SymbolRefAST *ast = calloc(1, sizeof(SymbolRefAST));
  ast->symbol = symbol;
  return ast_cast(AST_SYM_REF, rule_pos, 0, ast);
}

void ast_symref_free(AST *ast) {
  SymbolRefAST *symref_ast = ast->value.symref;
  free(symref_ast);
}

SymbolValues ast_symref_eval(AST *ast) {
  return ast->value.symref->symbol->value;
}

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

  printf("%*.s", depth * 4, "");
  symbol_print_pretty(symref->symbol);
}

CastInfo ast_symref_type_check(AST *ast) {
  SymbolRefAST *symref = ast->value.symref;
  return cast_info_with_type(cast_info_none(), symref->symbol->type);
}

void ast_symref_gen_code(AST *ast, FILE *out) {
  Symbol *sym = ast->value.symref->symbol;
  if (sym->kind != FUNC)
    fprintf(out, "push %s%d\n\n", t9n_prefix(sym->kind), sym->temp);
}
