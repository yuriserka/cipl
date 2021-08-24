#pragma once

#include <stdarg.h>

// fast-forward definition of AST structure to use in each node type header
typedef struct cipl_ast AST;

#include "data-structures/ast/bin-op.h"
#include "data-structures/ast/num.h"
#include "data-structures/ast/uni-op.h"
#include "data-structures/list.h"

typedef enum cipl_ast_types {
  AST_NUMBER_INT,
  AST_NUMBER_REAL,
  AST_BIN_OP,
  AST_UNI_OP,
} AstTypes;

typedef union cipl_ast_node_value {
  NumberAST *number;
  BinOpAST *binop;
  UniOpAST *uniop;
} AstNodeValue;

struct cipl_ast {
  AstTypes type;
  ListNode *children;
  AstNodeValue value;
};

void ast_child_free(ListNode *node);
void ast_free(AST *ast);
/*
 * 1st variadic arg = the actual value (some of AstNodeValue) that node should have 
 * 2nd+ variadic arg = children nodes
 */
AST *ast_cast(AstTypes type, int n_children, ...);
double ast_eval(AST *ast);
void ast_print(AST *ast);
