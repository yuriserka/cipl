#pragma once

#include <stdio.h>

// from lexer.l
extern int errors_count;
extern char *filename;

extern int yylex();
extern int yyparse();
extern void yyerror(char *message);
extern int yylex_destroy();
extern FILE *yyin;

int cipl_main(int argc, char *argv[]);
