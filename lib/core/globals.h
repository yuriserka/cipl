#pragma once

#include <stdio.h>

#include "utils/cursor-position.h"

// from lexer.l
extern int errors_count;
extern char *filename;
extern cursor_position cursor;

extern int yylex();
extern int yyparse();
extern void yyerror(char *message);
extern int yylex_destroy();
extern FILE *yyin;
