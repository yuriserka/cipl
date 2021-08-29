#include "core/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "utils/io.h"

void init_global_context(Context *global_ctx) {
  cursor_position definition = (cursor_position){.line = 0, .col = 0};
  AST *write_fnref = ast_symref_init(symbol_init(
      "write", global_ctx->current_scope, global_ctx->name, definition));
  AST *writeln_fnref = ast_symref_init(symbol_init(
      "writeln", global_ctx->current_scope, global_ctx->name, definition));
  AST *read_fnref = ast_symref_init(symbol_init(
      "read", global_ctx->current_scope, global_ctx->name, definition));

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

int cipl_main(int argc, char *argv[]) {
  root = ast_cast(AST_PROG, 0);
  contexts = list_node_init(context_init("global"));
  current_context = list_peek(&contexts, 0);
  // init_global_context(current_context);

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

  yyparse();

  if (errors_count) {
    CIPL_PRINTF_COLOR(RED, "\n%d error%s generated.\n", errors_count,
                      errors_count > 1 ? "s" : "");
  }

  fclose(yyin);
  yylex_destroy();

  print_ast();
  print_all_contexts();

  ast_free(root);
  LIST_FREE(contexts, { context_free(__IT__->data); });

  return errors_count > 0;
}
