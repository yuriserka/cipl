#pragma once

#include <stdarg.h>
#include <stdio.h>

#include "bison/grammar.h"

// fast-forward definition of AST structure to use in each ast node type header
typedef struct cipl_ast AST;

#include <data-structures/symbol-table/symbol.h>

#include "data-structures/ast/types/assign.h"
#include "data-structures/ast/types/bin-op.h"
#include "data-structures/ast/types/block-items.h"
#include "data-structures/ast/types/builtin-fn.h"
#include "data-structures/ast/types/declaration.h"
#include "data-structures/ast/types/flow.h"
#include "data-structures/ast/types/func-call.h"
#include "data-structures/ast/types/iteration.h"
#include "data-structures/ast/types/jmp.h"
#include "data-structures/ast/types/num.h"
#include "data-structures/ast/types/params.h"
#include "data-structures/ast/types/str-literal.h"
#include "data-structures/ast/types/symbol-ref.h"
#include "data-structures/ast/types/types-def.h"
#include "data-structures/ast/types/uni-op.h"
#include "data-structures/ast/types/user-func.h"
#include "data-structures/list.h"

typedef union cipl_ast_node_value {
  AssignAST *assignop;
  SymbolRefAST *symref;
  NumberAST *number;
  BinOpAST *binop;
  UniOpAST *uniop;
  DeclarationAST *declaration;
  BuiltinFuncAST *builtinfn;
  FlowAST *flow;
  UserFuncAST *userfunc;
  ParamsAST *params;
  BlockItemListAST *blockitems;
  JumpAST *jmp;
  IterationAST *iteration;
  FunctionCallAST *funcall;
  StringLiteralAST *str;
} AstNodeValue;

struct cipl_ast {
  YYLTYPE rule_pos;
  AstTypes type;
  ListNode *children;
  AstNodeValue value;
};

void ast_child_print_aux_label(const char *label, AST *ast);

/*
 * 1st variadic arg = the actual value (some of AstNodeValue)
 * 2nd+ variadic arg = children nodes
 */
AST *ast_cast(AstTypes type, YYLTYPE rule_pos, int n_children, ...);
void ast_free(AST *ast);
SymbolValues ast_eval(AST *ast);
void ast_print(AST *ast);
void ast_print_pretty(AST *ast, int depth);

SymbolTypes ast_validate_types(AST *ast);

void ast_gen_code_init(FILE *out);
void ast_gen_code_end(FILE *out);
void ast_gen_code(AST *ast, FILE *out);

AST *ast_find_node(AST *root, AstTypes type);

/**
 * used just to iterate over tree
 * called but the AST value which is inside node is not freed
 */
void ast_fake_stack_pop(ListNode *node);

/**
 * should set __FOUND__ to true to stop iteration
 * both __NOT_FOUND_ACTION__ & __FOUND_ACTION__ have access to variables
 * __DFS_L__ which is a list of AST* nodes and __AST__ the current AST *node
 * being processed
 */
#define AST_FIND_NODE(__ROOT__, __TYPE__, __FOUND_ACTION__, \
                      __NOT_FOUND_ACTION__)                 \
  {                                                         \
    bool __FOUND__ = 0;                                     \
    ListNode *__DFS_L__ = list_node_init(__ROOT__);         \
    AST *__AST__ = NULL;                                    \
    while ((__AST__ = list_peek(&__DFS_L__, 0))) {          \
      list_pop_front(&__DFS_L__, ast_fake_stack_pop);       \
      if (__AST__->type == __TYPE__) {                      \
        __FOUND_ACTION__;                                   \
      }                                                     \
      if (__FOUND__) break;                                 \
      switch (__AST__->type) {                              \
        case AST_BLOCK_ITEM_LIST:                           \
          LIST_FOR_EACH(__AST__->value.blockitems->value, { \
            AST *child = __IT__->data;                      \
            if (child) list_push(&__DFS_L__, child);        \
          });                                               \
          break;                                            \
        case AST_PARAM_LIST:                                \
          LIST_FOR_EACH(__AST__->value.params->value, {     \
            AST *child = __IT__->data;                      \
            if (child) list_push(&__DFS_L__, child);        \
          });                                               \
          break;                                            \
        default:                                            \
          LIST_FOR_EACH(__AST__->children, {                \
            AST *child = __IT__->data;                      \
            if (child) list_push(&__DFS_L__, child);        \
          });                                               \
      }                                                     \
    }                                                       \
    list_free(__DFS_L__, ast_fake_stack_pop);               \
    if (!__FOUND__) {                                       \
      __NOT_FOUND_ACTION__;                                 \
    }                                                       \
  }
