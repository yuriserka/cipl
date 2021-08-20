%option nounput noinput noyywrap
%option outfile="src/flex/lexer.c" header-file="lib/flex/scanner.h"

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "bison/grammar.h"
  #include "utils/cursor-position.h"
  #include "utils/io.h"

  int errors_count = 0;
  char *filename;
  cursor_position cursor = {.line=1, .col=1};
%}

%%

[0-9]+ {
  cursor_position_update(0, yyleng);
  yylval.integer = atoi(yytext);
  return NUMBER_INT;
}

([0-9]*[.])?[0-9]+([eE][+-]?[0-9]+)? {
  cursor_position_update(0, yyleng);
  yylval.real = atof(yytext);
  return NUMBER_REAL;
}

"+"|"-"|"*"|"/"|"!"|"("|")" {
  cursor_position_update(0, yyleng);
  return yytext[0];
}

\n|\r {
  cursor_position_update(1, 0);
  return EOL;
}

[ \t]|"//".* {
  cursor_position_update(0, yyleng);
  // nao retornar nada significa que ta retornando o epsilon
}

. {
  cipl_perror("unexpected character: %s\n", yytext);
  ++errors_count;
  cursor_position_update(0, yyleng);
}

%%