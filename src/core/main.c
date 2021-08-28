#include "core/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "utils/io.h"

void contexts_print() {
  printf("{ contexts: [ ");
  LIST_FOR_EACH(contexts, { context_print(__IT__->data); });
  printf("], }\n");
}

int cipl_main(int argc, char *argv[]) {
  root = ast_cast(AST_PROG, 0);
  contexts = list_node_init(context_init("global"));
  current_context = list_peek(&contexts, 0);

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

  printf("{ ast: { ");
  ast_print(root);
  printf("}, }\n");

  contexts_print();

  ast_free(root);
  LIST_FREE(contexts, { context_free(__IT__->data); });

  return errors_count > 0;
}