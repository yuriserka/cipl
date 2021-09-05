#include "core/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "utils/io.h"

void init_global_context(Context *global_ctx) {
  cursor_position definition = (cursor_position){.line = 0, .col = 0};
  SymbolTypes type = symbol_type_from_str("int");
  AST *write_fnref = ast_symref_init(symbol_init("write", type, true,
                                                 global_ctx->current_scope,
                                                 global_ctx->name, definition));

  AST *writeln_fnref = ast_symref_init(
      symbol_init("writeln", type, true, global_ctx->current_scope,
                  global_ctx->name, definition));

  AST *read_fnref =
      ast_symref_init(symbol_init("read", type, true, global_ctx->current_scope,
                                  global_ctx->name, definition));

  context_declare_function(global_ctx, write_fnref->value.symref);
  context_declare_function(global_ctx, writeln_fnref->value.symref);
  context_declare_function(global_ctx, read_fnref->value.symref);

  ast_free(write_fnref);
  ast_free(writeln_fnref);
  ast_free(read_fnref);
}

void print_all_contexts() {
  printf("{ contexts: [ ");
  LIST_FOR_EACH(contexts, { context_print(__IT__->data); });
  printf("], }\n");
}

void print_ast() {
  printf("{ ast: { ");
  ast_print(root);
  printf("}, }\n");
}

void main_ast_pretty() {
  printf("\n##################################################\n");
  printf("               Abstract Syntax Tree               \n");
  printf("##################################################\n\n");
  ast_print_pretty(root, 0);
}

void main_context_pretty() {
  printf("\n\n##################################################\n");
  printf("                   Symbol Table                   \n");
  printf("##################################################\n\n");
  LIST_FOR_EACH(contexts, { context_print_pretty(__IT__->data); });
}

int cipl_main(int argc, char *argv[]) {
  if (argc < 2) {
    CIPL_PRINTF_COLOR(RED, "error: ");
    CIPL_PRINTF("usage: %s <filename>\n", argv[0]);
    return 1;
  }

  FILE *pfile = fopen(argv[1], "r");

  if (!pfile) {
    CIPL_PRINTF_COLOR(RED, "error: ");
    CIPL_PRINTF("could not open file at: %s\n", argv[1]);
    return 1;
  }

  yyin = pfile;
  (filename = strrchr(argv[1], '/')) ? ++filename : (filename = argv[1]);

  root = ast_cast(AST_PROG, 0);
  contexts = list_node_init(context_init("global"));
  current_context = list_peek(&contexts, 0);
  init_global_context(current_context);

  int got_erros = yyparse() || errors_count;

  if (got_erros) {
    CIPL_PRINTF_COLOR(BRED, "\n\n%d error%s", errors_count,
                      errors_count > 1 ? "s" : "");
    CIPL_PRINTF(
        " generated.\n\tIs not possible to print the AST or the Symbol Table.\n");
  }

  fclose(yyin);
  yylex_destroy();

  if (!got_erros) {
    main_ast_pretty();
    main_context_pretty();
  }

  ast_free(root);
  LIST_FREE(contexts, { context_free(__IT__->data); });

  return errors_count > 0;
}
