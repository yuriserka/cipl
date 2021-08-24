#include "core.h"

#include <stdio.h>
#include <string.h>

#include "utils/io.h"

int cipl_main(int argc, char *argv[]) {
  if (argc < 2) {
    cipl_printf_color(RED, "error: ");
    cipl_printf("usage: %s <filename>\n", argv[0]);
    return 1;
  }

  FILE *pfile = fopen(argv[1], "r");

  if (!pfile) {
    cipl_printf_color(RED, "error: ");
    cipl_printf("could not open file at: %s\n", argv[1]);
    return 1;
  }

  yyin = pfile;
  (filename = strrchr(argv[1], '/')) ? ++filename : (filename = argv[1]);

  yyparse();

  if (errors_count) {
    cipl_printf_color(RED, "\n%d error%s generated.\n", errors_count,
                      errors_count > 1 ? "s" : "");
  }

  fclose(yyin);
  yylex_destroy();

  return errors_count > 0;
}