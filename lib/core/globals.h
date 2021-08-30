#pragma once

#include <stdio.h>

#include "data-structures/ast/ast.h"
#include "data-structures/context.h"
#include "data-structures/list.h"
#include "data-structures/scope.h"
#include "data-structures/symbol-table/symbol-table.h"
#include "utils/cursor-position.h"

// from lexer.l
extern int errors_count;
extern char *filename;
extern cursor_position cursor;

extern int yylex();
extern int yyparse();
extern void yyerror(const char *message, ...);
extern int yylex_destroy();
extern FILE *yyin;

// from grammar.y
extern AST *root;
extern Context *current_context;
extern ListNode *contexts;

#define SWAP(__X__, __Y__)        \
  {                               \
    typeof(__X__) __X1__ = __X__; \
    typeof(__Y__) __Y1__ = __Y__; \
    __X__ = __Y1__;               \
    __Y__ = __X1__;               \
  }
