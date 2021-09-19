#include "data-structures/ast/types/func-call.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/context.h"
#include "utils/io.h"

AST *ast_funcall_init(YYLTYPE rule_pos, AST *declarator, AST *args) {
  FunctionCallAST *ast = calloc(1, sizeof(FunctionCallAST));
  return ast_cast(AST_FUNC_CALL, rule_pos, 2, ast, declarator, args);
}

void ast_funcall_free(AST *ast) {
  FunctionCallAST *funcall_ast = ast->value.funcall;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(funcall_ast);
}

SymbolValues ast_funcall_eval(AST *ast) { return (SymbolValues){.integer = 0}; }

void ast_funcall_print(AST *ast) {
  AST *declarator = list_peek(&ast->children, 0);
  AST *args = list_peek(&ast->children, 1);
  printf("function_call: { ");
  ast_child_print_aux_label("declarator", declarator);
  ast_child_print_aux_label("args", args);
  printf("}");
}

void ast_funcall_print_pretty(AST *ast, int depth) {
  AST *declarator = list_peek(&ast->children, 0);
  AST *args = list_peek(&ast->children, 1);

  for (int i = depth; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<function-call>\n");

  ast_print_pretty(declarator, depth + 1);
  ast_print_pretty(args, depth + 1);
}

SymbolTypes ast_funcall_type_check(AST *ast) {
  AST *declarator = list_peek(&ast->children, 0);
  AST *args = list_peek(&ast->children, 1);

  AST *func_decl;
  AST_FIND_NODE(root, AST_USER_FUNC,
                {
                  AST *key = list_peek(&__AST__->children, 0);
                  if (!strcmp(key->value.symref->symbol->name,
                              declarator->value.symref->symbol->name)) {
                    func_decl = __AST__;
                    __FOUND__ = 1;
                  }
                },
                {});
  AST *func_decl_params = list_peek(&func_decl->children, 1);
  ParamsAST *args_l = args->value.params;
  ParamsAST *params_l = func_decl_params->value.params;

  if (params_l->size != args_l->size) {
    ++errors_count;
    Cursor beg = {.line = declarator->rule_pos.first_line,
                  .col = declarator->rule_pos.first_column};
    Cursor end = {.line = declarator->rule_pos.last_line,
                  .col = declarator->rule_pos.last_column};
    LineInfo *li = list_peek(&lines, beg.line - 1);
    CIPL_PERROR_CURSOR_RANGE(
        "too %s arguments to function " BBLU "'%s'" RESET "\n", li->text, beg,
        end, args_l->size > params_l->size ? "many" : "few",
        declarator->value.symref->symbol->name);
    return SYM_INVALID;
  }

  LIST_FOR_EACH(args->value.params->value, {
    AST *arg_symref = __IT__->data;
    AST *param_decl = list_peek(&func_decl_params->value.params->value, __K__);

    SymbolTypes a_t = ast_validate_types(arg_symref);
    SymbolTypes p_t = ast_validate_types(param_decl);

    SymbolTypes max_t = MAX(a_t, p_t);
    if (max_t >= SYM_PTR) {
      if (a_t <= SYM_REAL || p_t <= SYM_REAL) {
        ++errors_count;
        Cursor beg;
        beg.line = arg_symref->rule_pos.first_line;
        beg.col = arg_symref->rule_pos.first_column;
        Cursor end;
        end.line = arg_symref->rule_pos.last_line;
        end.col = arg_symref->rule_pos.last_column;
        LineInfo *li = list_peek(&lines, beg.line - 1);
        CIPL_PERROR_CURSOR_RANGE(
            "expected " BGRN "'%s'" RESET " but argument is of type " BGRN
            "'%s'" RESET "\n",
            li->text, beg, end, symbol_canonical_type_from_enum(p_t),
            symbol_canonical_type_from_enum(a_t));
        return SYM_INVALID;
      }
    }
  });

  return ast_validate_types(declarator);
}
