#pragma once

#include <stdio.h>
#include <stdbool.h>

#include "data-structures/ast/ast.h"
#include "data-structures/context.h"
#include "data-structures/list.h"
#include "data-structures/scope.h"
#include "data-structures/symbol-table/symbol-table.h"
#include "utils/cursor-position.h"

// from lexer.l
extern int errors_count;
extern char *filename;
extern Cursor cursor;
extern ListNode *lines;
extern LineInfo *curr_line_info;
extern char curr_line_buffer[1024];

extern int yylex();
extern int yyparse();
extern void yyerror(int line, int column, const char *message, ...);
extern int yylex_destroy();
extern FILE *yyin;

// from grammar.y
extern AST *root;
extern Context *current_context;
extern ListNode *contexts;
extern bool p_ctx_name;

// utils

#define SWAP(__X__, __Y__)        \
  {                               \
    typeof(__X__) __X1__ = __X__; \
    typeof(__Y__) __Y1__ = __Y__; \
    __X__ = __Y1__;               \
    __Y__ = __X1__;               \
  }

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
