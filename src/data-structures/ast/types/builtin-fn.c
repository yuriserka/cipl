#include "data-structures/ast/types/builtin-fn.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/io.h"

void ast_builtinfn_free(AST *ast) {
  BuiltinFuncAST *builtinfn_ast = ast->value.builtinfn;
  LIST_FREE(ast->children, { ast_free(__IT__->data); });
  free(builtinfn_ast);
}

AST *ast_builtinfn_init(YYLTYPE rule_pos, char *name, AST *params) {
  BuiltinFuncAST *ast = calloc(1, sizeof(BuiltinFuncAST));
  ast->func_type = builtinfn_type_from_str(name);
  ast->arity = 1;
  return ast_cast(AST_BUILTIN_FUNC, rule_pos, 1, ast, params);
}

SymbolValues ast_builtinfn_eval(AST *ast) {
  return (SymbolValues){.integer = 0};
}

void ast_builtinfn_print(AST *ast) {
  BuiltinFuncAST *builtinfn_ast = ast->value.builtinfn;
  AST *args = list_peek(&ast->children, 0);
  printf("builtin_call: { name: %s , ",
         builtinfn_str_from_type(builtinfn_ast->func_type));
  ast_child_print_aux_label("args", args);
  printf("}");
}

void ast_builtinfn_print_pretty(AST *ast, int depth) {
  BuiltinFuncAST *builtinfn_ast = ast->value.builtinfn;
  AST *args = list_peek(&ast->children, 0);

  for (int i = depth; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BMAG, "<builtin-call>\n");

  for (int i = depth + 1; i > 0; --i) printf("\t");
  CIPL_PRINTF_COLOR(BBLU, "%s\n",
                    builtinfn_str_from_type(builtinfn_ast->func_type));

  ast_print_pretty(args, depth + 1);
}

BuiltInFuncTypes builtinfn_type_from_str(char *sym_name) {
  if (sym_name[0] == 'r') return BUILTIN_FN_READ;
  return strstr(sym_name, "ln") ? BUILTIN_FN_WRITELN : BUILTIN_FN_WRITE;
}

const char *builtinfn_str_from_type(BuiltInFuncTypes type) {
  switch (type) {
    case BUILTIN_FN_READ:
      return "read";
    case BUILTIN_FN_WRITELN:
      return "writeln";
    default:
      return "write";
  }
}

static void handle_list_as_arg(AST *arg, SymbolTypes type) {
  Cursor beg = cursor_init_yylloc_begin(arg->rule_pos);
  Cursor end = cursor_init_yylloc_end(arg->rule_pos);
  LineInfo *li = list_peek(&lines, beg.line - 1);
  CIPL_PERROR_CURSOR_RANGE(
      "expected " BGRN "'%s'" RESET " or " BGRN "'%s'" RESET
      " but argument is of type " BGRN "'%s'" RESET "\n",
      li->text, beg, end, symbol_canonical_type_from_enum(SYM_INT),
      symbol_canonical_type_from_enum(SYM_REAL),
      symbol_canonical_type_from_enum(type));
  ++errors_count;
}

SymbolTypes ast_builtinfn_type_check(AST *ast) {
  AST *args = list_peek(&ast->children, 0);
  SymbolTypes args_t = ast_validate_types(args);

  if (args_t > SYM_PTR) {
    handle_list_as_arg(args, args_t);
  }

  return SYM_INT;
}

void ast_builtinfn_gen_code(AST *ast, FILE *out) {
  BuiltinFuncAST *builtinfn_ast = ast->value.builtinfn;
  AST *args = list_peek(&ast->children, 0);

  ast_gen_code(args, out);
  fprintf(out, "pop $%d\n", current_context->t9n->temp);

  switch (builtinfn_ast->func_type) {
    case BUILTIN_FN_READ:
      fprintf(out, "param $%d\n", current_context->t9n->temp);
      fprintf(out, "call %s, 1\n\n",
              builtinfn_str_from_type(builtinfn_ast->func_type));
      break;
    default: {
      fprintf(out, "param $%d\n", current_context->t9n->temp);
      fprintf(out, "call %s, 1\n\n",
              builtinfn_str_from_type(builtinfn_ast->func_type));
    }
  }
}
