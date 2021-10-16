#include "data-structures/ast/types/params.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils/io.h"

AST *ast_params_init(YYLTYPE rule_pos, ListNode *params) {
  ParamsAST *ast = calloc(1, sizeof(ParamsAST));
  ast->value = params;
  ast->size = list_size(params);
  return ast_cast(AST_PARAM_LIST, rule_pos, 0, ast);
}

void ast_params_free(AST *ast) {
  ParamsAST *params_ast = ast->value.params;
  LIST_FREE(params_ast->value, { ast_free(__IT__->data); });
  free(params_ast);
}

SymbolValues ast_params_eval(AST *ast) { return (SymbolValues){.integer = 0}; }

void ast_params_print(AST *ast) {
  ParamsAST *params_ast = ast->value.params;
  printf("params: { ");
  LIST_FOR_EACH(params_ast->value, { ast_print(__IT__->data); });
  printf("}");
}

void ast_params_print_pretty(AST *ast, int depth) {
  ParamsAST *params_ast = ast->value.params;

  printf("%*.s" BMAG "<params>" RESET "\n", depth * 4, "");

  LIST_FOR_EACH(params_ast->value,
                { ast_print_pretty(__IT__->data, depth + 1); });
}

CastInfo ast_params_type_check(AST *ast) {
  LIST_FOR_EACH(ast->value.params->value,
                { ast_validate_types(__IT__->data); });
  return cast_info_none();
}
