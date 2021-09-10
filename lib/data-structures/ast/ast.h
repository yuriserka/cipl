#pragma once

#include <stdarg.h>

// fast-forward definition of AST structure to use in each ast node type header
typedef struct cipl_ast AST;

#include "data-structures/symbol-table/symbol.h"

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
  AstTypes type;
  ListNode *children;
  AstNodeValue value;
};

void ast_child_print_aux_label(const char *label, AST *ast);

/*
 * 1st variadic arg = the actual value (some of AstNodeValue)
 * 2nd+ variadic arg = children nodes
 */
AST *ast_cast(AstTypes type, int n_children, ...);
void ast_free(AST *ast);
SymbolValues ast_eval(AST *ast);
void ast_print(AST *ast);
void ast_print_pretty(AST *ast, int depth);
