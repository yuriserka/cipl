#pragma once

#include <stdarg.h>

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

typedef struct cipl_ast {
  AstTypes type;
  ListNode *children;
  AstNodeValue value;
} AST;

void ast_child_free(ListNode *node);
void ast_free(AST *ast);
void ast_uniop_free(AST *ast);
void ast_binop_free(AST *ast);
void ast_number_free(AST *ast);

/*
 * 1st variadic arg = the actual value (some of AstNodeValue) that node should have 
 * 2nd+ variadic arg = children nodes
 */
AST *ast_cast(AstTypes type, int n_children, ...);
AST *ast_number_init(NumberType type, NumberValue value);
AST *ast_binop_init(char op, AST *l, AST *r);
AST *ast_uniop_init(char op, AST *l);

double ast_number_eval(AST *ast);
double ast_binop_eval(AST *ast);
double ast_uniop_eval(AST *ast);
double ast_eval(AST *ast);

void ast_number_print(AST *ast);
void ast_binop_print(AST *ast);
void ast_uniop_print(AST *ast);
void ast_print(AST *ast);
