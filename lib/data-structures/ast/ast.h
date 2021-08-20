#pragma once

#include "data-structures/ast/bin-op.h"
#include "data-structures/ast/uni-op.h"
#include "data-structures/ast/num.h"
#include "data-structures/list.h"

typedef enum cipl_ast_types {
  AST_NUMBER_INT,
  AST_NUMBER_REAL,
  AST_BIN_OP,
  AST_UNI_OP,
} AstTypes;

// melhor tentar isso ou cast?
typedef union cipl_ast_node_value {
  NumberAST *number;
  BinOpAST *binop;
  UniOpAST *uniop;
} AstNodeValue;

typedef struct cipl_ast {
  AstTypes type;
  struct cipl_ast *l;
  struct cipl_ast *r;
} AST;

AST *ast_cast(AST *ast, AstTypes type, AST *l, AST *r);
AST *ast_number_init(NumberType type, NumberValue value);
AST *ast_binop_init(char op, AST *l, AST *r);
AST *ast_uniop_init(char op, AST *l);

double ast_number_eval(AST *ast);
double ast_binop_eval(AST *ast);
double ast_uniop_eval(AST *ast);
double ast_eval(AST *ast);
