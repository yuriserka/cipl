#include "data-structures/ast/types/user-func.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "data-structures/context.h"
#include "utils/io.h"

AST *ast_userfunc_init(YYLTYPE rule_pos, Context *context, AST *declarator,
                       AST *params, AST *stmts) {
  UserFuncAST *ast = calloc(1, sizeof(UserFuncAST));
  ast->context = context;
  ast->arity = params->value.params->size;
  return ast_cast(AST_USER_FUNC, rule_pos, 3, ast, declarator, params, stmts);
}

void ast_userfunc_free(AST *ast) {
  UserFuncAST *userfunc_ast = ast->value.userfunc;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(userfunc_ast);
}

SymbolValues ast_userfunc_eval(AST *ast) {
  return (SymbolValues){.integer = 0};
}

void ast_userfunc_print(AST *ast) {
  AST *name = list_peek(&ast->children, 0);
  AST *params = list_peek(&ast->children, 1);
  AST *statements = list_peek(&ast->children, 2);
  printf("user_func: { ");
  ast_child_print_aux_label("name", name);
  ast_print(params);
  ast_print(statements);
  printf("}");
}

void ast_userfunc_print_pretty(AST *ast, int depth) {
  current_context = ast->value.userfunc->context;

  AST *name = list_peek(&ast->children, 0);
  AST *params = list_peek(&ast->children, 1);
  AST *statements = list_peek(&ast->children, 2);

  printf("%*.s" BMAG "<function-declaration>" RESET "\n", depth * 4, "");

  ast_print_pretty(name, depth + 1);
  ast_print_pretty(params, depth + 1);
  ast_print_pretty(statements, depth + 1);

  int qtd_ret = 0;
  AST_FIND_NODE(
      statements, AST_JMP, { ++qtd_ret; },
      {
        if (!qtd_ret) {
          printf("%*.s" BMAG "<implicit-return>" RESET "\n", (depth + 2) * 4,
                 "");
          switch (ast->cast_info.data_type) {
            case SYM_REAL:
              printf("%*.s" BYEL "0.0" RESET "\n", (depth + 3) * 4, "");
              break;
            case SYM_INT:
              printf("%*.s" BYEL "0" RESET "\n", (depth + 3) * 4, "");
              break;
            default:
              printf("%*.s" BYEL "NIL" RESET "\n", (depth + 3) * 4, "");
              break;
          }
        }
      });
}

CastInfo ast_userfunc_type_check(AST *ast) {
  p_ctx_name = true;
  current_context = ast->value.userfunc->context;

  AST *declarator = list_peek(&ast->children, 0);
  AST *params = list_peek(&ast->children, 1);
  AST *statements = list_peek(&ast->children, 2);

  ast_validate_types(declarator);
  ast_validate_types(params);
  ast_validate_types(statements);

  return cast_info_with_type(cast_info_none(), declarator->cast_info.data_type);
}

void ast_userfunc_gen_code(AST *ast, FILE *out) {
  AST *name = list_peek(&ast->children, 0);
  AST *params = list_peek(&ast->children, 1);
  AST *statements = list_peek(&ast->children, 2);
  current_context = ast->value.userfunc->context;

  fprintf(out, "jump func_%s_END\n", name->value.symref->symbol->name);
  fprintf(out, "\nfunc_%s:\n", name->value.symref->symbol->name);
  ListNode *old_params_ref = NULL;

  bool is_main = !strcmp(name->value.symref->symbol->name, "main");

  int qtd_globals = 0;
  AST_TRAVERSE_UNTIL(
      root, AST_DECLARATION,
      {
        if (__AST__->type == AST_USER_FUNC) {
          AST *key = list_peek(&__AST__->children, 0);
          if (!strcmp(key->value.symref->symbol->name, current_context->name)) {
            __FOUND__ = true;
          }
        }
      },
      { ++qtd_globals; });

  if (!is_main) {
    AST_TRAVERSE_UNTIL(
        root, AST_DECLARATION,
        {
          if (__AST__->type == AST_USER_FUNC) {
            AST *key = list_peek(&__AST__->children, 0);
            if (!strcmp(key->value.symref->symbol->name,
                        current_context->name)) {
              __FOUND__ = true;
            }
          }
        },
        { fprintf(out, "pop $%d\n", --qtd_globals); });
  }

  LIST_FOR_EACH(params->value.params->value, {
    AST *param = __IT__->data;
    Symbol *par_sym = param->value.symref->symbol;
    // int/float are passed by value so have to copy them to a temp
    if (par_sym->type < SYM_PTR) {
      int curr_tmp = current_context->t9n->temp;
      fprintf(out, "// param %s %s\n",
              symbol_canonical_type_from_enum(par_sym->type), par_sym->name);
      t9n_alloc_from_other_var(curr_tmp, par_sym->temp, par_sym->type,
                               par_sym->kind, out);

      list_push(&old_params_ref, symbol_init_copy(par_sym));

      par_sym->temp = current_context->t9n->temp++;
      par_sym->kind = VAR;
    }
  });

  ast_gen_code(statements, out);

  // recover #param number
  int i = 0;
  LIST_FOR_EACH(params->value.params->value, {
    AST *param = __IT__->data;
    Symbol *par_sym = param->value.symref->symbol;
    if (par_sym->type < SYM_PTR) {
      Symbol *old_par_sym = list_peek(&old_params_ref, i++);
      par_sym->temp = old_par_sym->temp;
      par_sym->kind = PARAM;
    }
  });

  LIST_FREE(old_params_ref, { symbol_free(__IT__->data); });

  int qtd_ret = 0;
  AST_FIND_NODE(
      statements, AST_JMP, { ++qtd_ret; },
      {
        if (!is_main) {
          if (!qtd_ret) {
            t9n_alloc_from_constant(
                current_context->t9n->temp, ast->cast_info.data_type,
                (NumberValue){.integer = 0, .real = 0.0}, out);
            fprintf(out, "return $%d\n", current_context->t9n->temp);
          }
        } else {
          fprintf(out, "jump EOF\n");
        }
      });

  fprintf(out, "\nfunc_%s_END:\n\n", name->value.symref->symbol->name);
}
