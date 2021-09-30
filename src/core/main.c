#include "core/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "utils/io.h"

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

static int cipl_syntax() {
  int got_errors = yyparse(0, 0) || errors_count;

  if (got_errors) {
    CIPL_PRINTF_COLOR(BRED, "\n\n%d error%s", errors_count,
                      errors_count > 1 ? "s" : "");
    CIPL_PRINTF(" generated.\n\tIs not possible to print the AST.\n");
  }

  return !got_errors;
}

static int cipl_semantic() {
  int got_errors = ast_validate_types(root) == SYM_INVALID;

  AST_FIND_NODE(
      root, AST_USER_FUNC,
      {
        AST *declarator = list_peek(&__AST__->children, 0);
        if (!strcmp(declarator->value.symref->symbol->name, "main")) {
          __FOUND__ = 1;
        }
      },
      {
        CIPL_PRINTF(BRED "error:" RESET " undefined reference to function " BBLU
                         "'main'" RESET "\n");
        ++errors_count;
      });

  got_errors = got_errors || errors_count;

  if (got_errors) {
    CIPL_PRINTF_COLOR(BRED, "\n\n%d error%s" RESET " generated\n", errors_count,
                      errors_count > 1 ? "s" : "");
  }

  return !got_errors;
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

  root = ast_cast(AST_PROG,
                  (YYLTYPE){
                      .first_line = 1,
                      .first_column = 1,
                      .last_line = 1,
                      .last_column = 1,
                  },
                  0);
  contexts = list_node_init(context_init("top level"));
  current_context = list_peek(&contexts, 0);
  curr_line_info = line_init(1, "");

  int succeeded = cipl_syntax();
  if (succeeded) {
    // main_ast_pretty();
    // main_context_pretty();
  }
  succeeded = succeeded && cipl_semantic();

  fclose(yyin);
  yylex_destroy();
  ast_free(root);
  LIST_FREE(contexts, { context_free(__IT__->data); });
  LIST_FREE(lines, { line_free(__IT__->data); });
  line_free(curr_line_info);

  return succeeded;
}
