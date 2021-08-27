#include "data-structures/ast/ast.h"

#include <stdio.h>
#include <stdlib.h>

#define AST_ASSIGN(MEM, TGT) \
  (AstNodeValue) { .MEM = va_arg(ptr, TGT *) }

AST *ast_cast(AstTypes type, int n_children, ...) {
  AST *ast = calloc(1, sizeof(AST));
  ast->type = type;

  ++n_children;

  va_list ptr;
  va_start(ptr, n_children);

  switch (type) {
    case AST_NUMBER_INT:
    case AST_NUMBER_REAL:
      ast->value = AST_ASSIGN(number, NumberAST);
      break;
    case AST_BIN_OP:
      ast->value = AST_ASSIGN(binop, BinOpAST);
      break;
    case AST_UNI_OP:
      ast->value = AST_ASSIGN(uniop, UniOpAST);
      break;
    case AST_ASSIGN_OP:
      ast->value = AST_ASSIGN(assignop, AssignAST);
      break;
    case AST_BUILTIN_FUNC:
      ast->value = AST_ASSIGN(builtinfn, BuiltinFuncAST);
      break;
    case AST_FLOW:
      ast->value = AST_ASSIGN(flow, FlowAST);
      break;
    case AST_SYM_REF:
      ast->value = AST_ASSIGN(symref, SymbolRefAST);
      break;
    case AST_CMP_OP:
      ast->value = AST_ASSIGN(cmpop, ComparisonAST);
      break;
    case AST_USER_FUNC:
      ast->value = AST_ASSIGN(userfunc, UserFuncAST);
      break;
    case AST_PARAMS:
      ast->value = AST_ASSIGN(params, ParamsAST);
      break;
    case AST_BLOCK_ITEM_LIST:
      ast->value = AST_ASSIGN(blockitems, BlockItemListAST);
      break;
    case AST_DECLARATION:
      ast->value = AST_ASSIGN(declaration, DeclarationAST);
      break;
    case AST_PROG:
      break;
  }

  --n_children;

  for (int i = 0; i < n_children; ++i) {
    list_push(&ast->children, va_arg(ptr, AST *));
  }

  va_end(ptr);

  return ast;
}

void ast_child_free(ListNode *node) { ast_free(node->data); }

void ast_free(AST *ast) {
  switch (ast->type) {
    case AST_NUMBER_INT:
    case AST_NUMBER_REAL:
      ast_number_free(ast);
      break;
    case AST_BIN_OP:
      ast_binop_free(ast);
      break;
    case AST_UNI_OP:
      ast_uniop_free(ast);
      break;
    case AST_ASSIGN_OP:
      ast_assign_free(ast);
      break;
    case AST_SYM_REF:
      ast_symref_free(ast);
      break;
    case AST_CMP_OP:
      ast_cmpop_free(ast);
      break;
    case AST_USER_FUNC:
      ast_userfunc_free(ast);
      break;
    case AST_PARAMS:
      ast_params_free(ast);
      break;
    case AST_BLOCK_ITEM_LIST:
      ast_blockitems_free(ast);
      break;
    case AST_DECLARATION:
      ast_declaration_free(ast);
      break;
    case AST_PROG:
      list_free(ast->children, ast_child_free);
      break;
    default:
      printf("AST type: %d free not implemented yet", ast->type);
      break;
  }
  free(ast);
}

double ast_eval(AST *ast) {
  switch (ast->type) {
    case AST_NUMBER_INT:
    case AST_NUMBER_REAL:
      return ast_number_eval(ast);
    case AST_BIN_OP:
      return ast_binop_eval(ast);
    case AST_UNI_OP:
      return ast_uniop_eval(ast);
    case AST_ASSIGN_OP:
      return ast_assign_eval(ast);
    case AST_SYM_REF:
      return ast_symref_eval(ast);
    case AST_CMP_OP:
      return ast_cmpop_eval(ast);
    case AST_USER_FUNC:
      return ast_userfunc_eval(ast);
    case AST_PARAMS:
      return ast_params_eval(ast);
    case AST_BLOCK_ITEM_LIST:
      return ast_blockitems_eval(ast);
    case AST_DECLARATION:
      return ast_declaration_eval(ast);
    case AST_PROG:
      return ast_eval(ast->children->data);
    default:
      printf("AST type: %d eval not implemented yet", ast->type);
      break;
  }
  return 0;
}

void ast_child_print(ListNode *node) { ast_print(node->data); }

void ast_print(AST *ast) {
  switch (ast->type) {
    case AST_NUMBER_INT:
    case AST_NUMBER_REAL:
      ast_number_print(ast);
      break;
    case AST_BIN_OP:
      ast_binop_print(ast);
      break;
    case AST_UNI_OP:
      ast_uniop_print(ast);
      break;
    case AST_ASSIGN_OP:
      ast_assign_print(ast);
      break;
    case AST_SYM_REF:
      ast_symref_print(ast);
      break;
    case AST_CMP_OP:
      ast_cmpop_print(ast);
      break;
    case AST_USER_FUNC:
      ast_userfunc_print(ast);
      break;
    case AST_PARAMS:
      ast_params_print(ast);
      break;
    case AST_BLOCK_ITEM_LIST:
      ast_blockitems_print(ast);
      break;
    case AST_DECLARATION:
      ast_declaration_print(ast);
      break;
    case AST_PROG:
      LIST_FOR_EACH(ast->children, { ast_child_print(__MAP_IT__); });
      return;
    default:
      printf("AST type: %d print not implemented yet", ast->type);
      break;
  }
  printf(", ");
}
