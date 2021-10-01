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

static void handle_mismatch_arg_type(AST *arg, SymbolTypes arg_t,
                                     SymbolTypes param_t) {
  Cursor beg = cursor_init_yylloc_begin(arg->rule_pos);
  Cursor end = cursor_init_yylloc_end(arg->rule_pos);
  LineInfo *li = list_peek(&lines, beg.line - 1);
  CIPL_PERROR_CURSOR_RANGE("expected " BGRN "'%s'" RESET
                           " but argument is of type " BGRN "'%s'" RESET "\n",
                           li->text, beg, end,
                           symbol_canonical_type_from_enum(param_t),
                           symbol_canonical_type_from_enum(arg_t));
  ++errors_count;
}

static void handle_mismatch_number_of_args(AST *fn_declarator, int args_size,
                                           int params_size) {
  Cursor beg = cursor_init_yylloc_begin(fn_declarator->rule_pos);
  Cursor end = cursor_init_yylloc_end(fn_declarator->rule_pos);
  LineInfo *li = list_peek(&lines, beg.line - 1);
  CIPL_PERROR_CURSOR_RANGE(
      "too %s arguments to function " BBLU "'%s'" RESET "\n", li->text, beg,
      end, args_size > params_size ? "many" : "few",
      fn_declarator->value.symref->symbol->name);
  ++errors_count;
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
    handle_mismatch_number_of_args(declarator, args_l->size, params_l->size);
  }

  LIST_FOR_EACH(args_l->value, {
    AST *arg = __IT__->data;
    AST *param_decl = list_peek(&params_l->value, __K__);

    SymbolTypes a_t = ast_validate_types(arg);
    SymbolTypes p_t = ast_validate_types(param_decl);

    if (!can_assign(p_t, a_t)) {
      handle_mismatch_arg_type(arg, a_t, p_t);
    }
  });

  return ast_validate_types(declarator);
}
