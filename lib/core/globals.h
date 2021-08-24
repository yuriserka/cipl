#pragma once

#include <stdio.h>

#include "data-structures/symbol-table/symbol-table.h"
#include "utils/cursor-position.h"

extern SymbolTable symbol_tb;

// from lexer.l
extern int errors_count;
extern char *filename;
extern cursor_position cursor;

extern int yylex();
extern int yyparse();
extern void yyerror(char *message);
extern int yylex_destroy();
extern FILE *yyin;
