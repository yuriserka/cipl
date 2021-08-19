%option nounput noinput noyywrap
%option outfile="src/flex/lexer.c" header-file="lib/flex/scanner.h"

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "bison/grammar.h"
  #include "utils/cursor-position.h"

  int errors_count = 0;
  char *filename;
  cursor_position cursor = {.line=1, .col=1};
%}

%%

[0-9]+ { yylval.value = atoi(yytext); return NUMBER; }
"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"!" { return ABS; }
\n { return EOL; }
"(" { return OP; }
")" { return CP; }

[ \t]|"//".*

. { printf("Mystery character %c\n", *yytext); }

%%