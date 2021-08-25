%option nounput noinput noyywrap
%option outfile="src/flex/lexer.c" header-file="lib/flex/scanner.h"

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "bison/grammar.h"
  #include "utils/cursor-position.h"
  #include "utils/io.h"
  #include "data-structures/symbol-table/symbol-table.h"

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

"+"|"-"|"*"|"/"|"="|"!"|"("|")"|","|";" {
  cursor_position_update(0, yyleng);
  return yytext[0];
}

"let" {
  cursor_position_update(0, yyleng);
  return LET;
}

"<" {
  cursor_position_update(0, yyleng);
  return LT;
}

"<=" {
  cursor_position_update(0, yyleng);
  return LE;
}

">" {
  cursor_position_update(0, yyleng);
  return GT;
}

">=" {
  cursor_position_update(0, yyleng);
  return GE;
}

"==" {
  cursor_position_update(0, yyleng);
  return EQ;
}

"!=" {
  cursor_position_update(0, yyleng);
  return NE;
}

[a-zA-Z_][a-zA-Z0-9_]* {
  yylval.sym = symbol_table_lookup(yytext);
  cursor_position_update(0, yyleng);
  return NAME;
}

\n|\r {
  cursor_position_update(1, 0);
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