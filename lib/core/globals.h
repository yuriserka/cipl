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
extern void yyerror(char *message, ...);
extern int yylex_destroy();
extern FILE *yyin;

// from grammar.y
extern AST *root;
extern Scope *current_scope;
extern Context *current_context;
extern ListNode *scopes;
extern ListNode *contexts;
