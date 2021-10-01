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

  for (int i = depth; i > 0; --i) printf("\t");

  CIPL_PRINTF_COLOR(BMAG, "<function-declaration>\n");
  ast_print_pretty(name, depth + 1);
  ast_print_pretty(params, depth + 1);
  ast_print_pretty(statements, depth + 1);
}

static void handle_mismatch_return_type(AST *block_item, SymbolTypes func_t) {
  SymbolTypes bi_t = ast_validate_types(block_item);
  if (!can_assign(func_t, bi_t)) {
    ++errors_count;
    AST *invalid_expr = list_peek(&block_item->children, 0);
    Cursor beg = cursor_init_yylloc_begin(invalid_expr->rule_pos);
    Cursor end = cursor_init_yylloc_end(invalid_expr->rule_pos);
    LineInfo *li = list_peek(&lines, beg.line - 1);
    CIPL_PERROR_CURSOR_RANGE(
        "incompatible types when returning type " BGRN "'%s'" RESET " but " BGRN
        "'%s'" RESET " was expected\n",
        li->text, beg, end, symbol_canonical_type_from_enum(bi_t),
        symbol_canonical_type_from_enum(func_t));
  }
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

  SymbolTypes name_t = ast_validate_types(declarator);
  AST *statements = list_peek(&ast->children, 2);

  int qtd_ret = 0;
  AST_FIND_NODE(
      statements, AST_JMP,
      {
        handle_mismatch_return_type(__AST__, name_t);
        ++qtd_ret;
      },
      {
        if (!qtd_ret) handle_no_return(declarator);
      });

  LIST_FOR_EACH(statements->value.blockitems->value, {
    AST *block_item = __IT__->data;
    if (block_item->type != AST_JMP) ast_validate_types(block_item);
  });

  return name_t;
}

void ast_userfunc_gen_code(AST *ast, FILE *out) {
  AST *name = list_peek(&ast->children, 0);
  AST *statements = list_peek(&ast->children, 2);
  current_context = ast->value.userfunc->context;
  current_context->translation = t9n_init();

  fprintf(out, "\n%s:\n", name->value.symref->symbol->name);
  ast_gen_code(statements, out);
}
