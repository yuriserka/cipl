#pragma once

#include <stdio.h>

#include "data-structures/ast/ast.h"
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
extern ListNode *scopes;

#define UPDATE_SCOPE(__CHILD_IT, __SCOPE_IDX)              \
  {                                                        \
    ListNode *__IT = __CHILD_IT;                           \
    while (__IT) {                                         \
      ListNode *__TMP = __IT->next;                        \
      AST *__SYMREF = __IT->data;                          \
      __SYMREF->value.symref->symbol->scope = __SCOPE_IDX; \
      __IT = __TMP;                                        \
    }                                                      \
  }
