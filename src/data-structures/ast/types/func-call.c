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

static AST *get_func_called(AST *fn_declarator) {
  AST *func_decl;
  AST_FIND_NODE(root, AST_USER_FUNC,
                {
                  AST *key = list_peek(&__AST__->children, 0);
                  if (!strcmp(key->value.symref->symbol->name,
                              fn_declarator->value.symref->symbol->name)) {
                    func_decl = __AST__;
                    __FOUND__ = 1;
                  }
                },
                {});
  return func_decl;
}

void ast_funcall_print_pretty(AST *ast, int depth) {
  AST *declarator = list_peek(&ast->children, 0);
  AST *args = list_peek(&ast->children, 1);

  printf("%*.s" BMAG "<function-call>" RESET "\n", depth * 4, "");

  ast_print_pretty(declarator, depth + 1);

  AST *func_decl = get_func_called(declarator);
  AST *func_decl_params = list_peek(&func_decl->children, 1);

  printf("%*.s" BMAG "<params>" RESET "\n", (depth + 1) * 4, "");
  LIST_FOR_EACH(args->value.params->value, {
    AST *arg = __IT__->data;
    AST *param_decl = list_peek(&func_decl_params->value.params->value, __K__);

    bool valid_cast = arg && param_decl &&
                      should_cast(arg->value_type, param_decl->value_type);

    if (valid_cast) {
      printf("%*.s" BMAG "<%s>" RESET "\n", (depth + 2) * 4, "",
             param_decl->value_type < arg->value_type ? "fltoint" : "inttofl");
    }

    ast_print_pretty(__IT__->data, depth + 2 + valid_cast);
  });
}

static void handle_mismatch_arg_type(AST *arg, AST *param) {
  Cursor beg = cursor_init_yylloc_begin(arg->rule_pos);
  Cursor end = cursor_init_yylloc_end(arg->rule_pos);
  LineInfo *li = list_peek(&lines, beg.line - 1);
  CIPL_PERROR_CURSOR_RANGE("expected " BGRN "'%s'" RESET
                           " but argument is of type " BGRN "'%s'" RESET "\n",
                           li->text, beg, end,
                           symbol_canonical_type_from_enum(param->value_type),
                           symbol_canonical_type_from_enum(arg->value_type));
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
  AST *func_decl = get_func_called(declarator);
  AST *func_decl_params = list_peek(&func_decl->children, 1);
  ParamsAST *args_l = args->value.params;
  ParamsAST *params_l = func_decl_params->value.params;

  if (params_l->size != args_l->size) {
    handle_mismatch_number_of_args(declarator, args_l->size, params_l->size);
  } else {
    LIST_FOR_EACH(args_l->value, {
      AST *arg = __IT__->data;
      AST *param_decl = list_peek(&params_l->value, __K__);

      ast_validate_types(arg);
      ast_validate_types(param_decl);

      if (!can_assign(param_decl->value_type, arg->value_type)) {
        handle_mismatch_arg_type(arg, param_decl);
      }
    });
  }

  ast_validate_types(declarator);
  return declarator->value_type;
}

void ast_funcall_gen_code(AST *ast, FILE *out) {
  AST *declarator = list_peek(&ast->children, 0);
  AST *args = list_peek(&ast->children, 1);

  Symbol *fn_name = declarator->value.symref->symbol;
  LIST_FOR_EACH(args->value.params->value, {
    AST *arg = __IT__->data;
    ast_gen_code(arg, out);
    fprintf(out, "pop $%d\n", current_context->t9n->temp + __K__ + 1);
    fprintf(out, "param $%d\n", current_context->t9n->temp + __K__ + 1);
  })
  fprintf(out, "call func_%s, %d\n", fn_name->name, args->value.params->size);
}
