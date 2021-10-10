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
  AST *name = list_peek(&ast->children, 0);
  AST *params = list_peek(&ast->children, 1);
  AST *statements = list_peek(&ast->children, 2);

  printf("%*.s" BMAG "<function-declaration>" RESET "\n", depth * 4, "");

  ast_print_pretty(name, depth + 1);
  ast_print_pretty(params, depth + 1);

  printf("%*.s" BMAG "<code-block>" RESET "\n", depth * 4, "");
  LIST_FOR_EACH(statements->value.blockitems->value, {
    AST *block_item = __IT__->data;

    if (block_item) {
      if (block_item->type != AST_JMP) {
        ast_print_pretty(block_item, depth + 1);
      } else {
        bool valid_cast = can_cast(name->value_type, block_item->value_type);
        if (valid_cast)
          printf("%*.s" BMAG "<%s>" RESET "\n", (depth + 1) * 4, "",
                 name->value_type < block_item->value_type ? "fltoint"
                                                           : "inttofl");
        ast_print_pretty(block_item, depth + 1 + valid_cast);
      }
    }
  });
}

static void handle_mismatch_return_type(AST *fname, AST *block_item) {
  AST *invalid_expr = list_peek(&block_item->children, 0);
  Cursor beg = cursor_init_yylloc_begin(invalid_expr->rule_pos);
  Cursor end = cursor_init_yylloc_end(invalid_expr->rule_pos);
  LineInfo *li = list_peek(&lines, beg.line - 1);
  CIPL_PERROR_CURSOR_RANGE(
      "incompatible types when returning type " BGRN "'%s'" RESET " but " BGRN
      "'%s'" RESET " was expected\n",
      li->text, beg, end,
      symbol_canonical_type_from_enum(block_item->value_type),
      symbol_canonical_type_from_enum(fname->value_type));
  ++errors_count;
}

static void handle_no_return(AST *func_declarator) {
  Cursor beg = cursor_init_yylloc_begin(func_declarator->rule_pos);
  Cursor end = cursor_init_yylloc_end(func_declarator->rule_pos);
  LineInfo *li = list_peek(&lines, beg.line - 1);
  CIPL_PERROR_CURSOR_RANGE("missing return at end of function\n", li->text, beg,
                           end);
  ++errors_count;
}

SymbolTypes ast_userfunc_type_check(AST *ast) {
  AST *declarator = list_peek(&ast->children, 0);
  p_ctx_name = true;
  current_context = ast->value.userfunc->context;

  ast_validate_types(declarator);
  AST *statements = list_peek(&ast->children, 2);

  int qtd_ret = 0;
  AST_FIND_NODE(
      statements, AST_JMP,
      {
        ast_validate_types(__AST__);
        if (!can_assign(declarator->value_type, __AST__->value_type)) {
          handle_mismatch_return_type(declarator, __AST__);
        }
        ++qtd_ret;
      },
      {
        if (!qtd_ret) handle_no_return(declarator);
      });

  LIST_FOR_EACH(statements->value.blockitems->value, {
    AST *block_item = __IT__->data;
    if (block_item->type != AST_JMP) ast_validate_types(block_item);
  });

  return declarator->value_type;
}

void ast_userfunc_gen_code(AST *ast, FILE *out) {
  AST *name = list_peek(&ast->children, 0);
  AST *params = list_peek(&ast->children, 1);
  AST *statements = list_peek(&ast->children, 2);
  current_context = ast->value.userfunc->context;

  Symbol *func_sym = name->value.symref->symbol;

  fprintf(out, "\n%s%s:\n", strcmp(func_sym->name, "main") ? "func_" : "",
          func_sym->name);

  ListNode *old_params_ref = NULL;

  LIST_FOR_EACH_REVERSE(params->value.params->value, {
    AST *param = __IT__->data;
    Symbol *par_sym = param->value.symref->symbol;
    // int/float are passed by value so have to copy them to a temp
    if (par_sym->type < SYM_PTR) {
      int curr_tmp = current_context->t9n->temp;
      fprintf(out, "// param %s %s\n",
              symbol_canonical_type_from_enum(par_sym->type), par_sym->name);
      fprintf(out, "mema $%d, 2\n", curr_tmp);
      fprintf(out, "mov $%d, #%d[1]\n", curr_tmp + 1, par_sym->temp);
      fprintf(out, "mov $%d[1], $%d\n", curr_tmp, curr_tmp + 1);
      fprintf(out, "mov *$%d, %d\n\n", curr_tmp, par_sym->type);

      list_push(&old_params_ref, symbol_init_copy(par_sym));

      par_sym->temp = current_context->t9n->temp++;
      par_sym->kind = VAR;
    }
  });

  ast_gen_code(statements, out);

  // recover #param number
  LIST_FOR_EACH_REVERSE(params->value.params->value, {
    AST *param = __IT__->data;
    Symbol *par_sym = param->value.symref->symbol;
    if (par_sym->type < SYM_PTR) {
      Symbol *old_par_sym = list_peek(&old_params_ref, __K__);
      par_sym->temp = old_par_sym->temp;
      par_sym->kind = PARAM;
    }
  });

  LIST_FREE(old_params_ref, { symbol_free(__IT__->data); });
}
