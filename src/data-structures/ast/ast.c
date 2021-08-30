#include "data-structures/ast/ast.h"

#include <stdio.h>
#include <stdlib.h>

#define AST_INIT_UNION(MEM, TGT) \
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
      ast->value = AST_INIT_UNION(number, NumberAST);
      break;
    case AST_BIN_OP:
      ast->value = AST_INIT_UNION(binop, BinOpAST);
      break;
    case AST_UNI_OP:
      ast->value = AST_INIT_UNION(uniop, UniOpAST);
      break;
    case AST_ASSIGN_OP:
      ast->value = AST_INIT_UNION(assignop, AssignAST);
      break;
    case AST_BUILTIN_FUNC:
      ast->value = AST_INIT_UNION(builtinfn, BuiltinFuncAST);
      break;
    case AST_FLOW:
      ast->value = AST_INIT_UNION(flow, FlowAST);
      break;
    case AST_SYM_REF:
      ast->value = AST_INIT_UNION(symref, SymbolRefAST);
      break;
    case AST_USER_FUNC:
      ast->value = AST_INIT_UNION(userfunc, UserFuncAST);
      break;
    case AST_PARAMS:
      ast->value = AST_INIT_UNION(params, ParamsAST);
      break;
    case AST_BLOCK_ITEM_LIST:
      ast->value = AST_INIT_UNION(blockitems, BlockItemListAST);
      break;
    case AST_DECLARATION:
      ast->value = AST_INIT_UNION(declaration, DeclarationAST);
      break;
    case AST_JMP:
      ast->value = AST_INIT_UNION(jmp, JumpAST);
      break;
    case AST_ITER:
      ast->value = AST_INIT_UNION(iteration, IterationAST);
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
  if (!ast) return;

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
    case AST_FLOW:
      ast_flow_free(ast);
      break;
    case AST_JMP:
      ast_jmp_free(ast);
      break;
    case AST_ITER:
      ast_iter_free(ast);
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
  if (!ast) return 0;

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
    case AST_USER_FUNC:
      return ast_userfunc_eval(ast);
    case AST_PARAMS:
      return ast_params_eval(ast);
    case AST_BLOCK_ITEM_LIST:
      return ast_blockitems_eval(ast);
    case AST_DECLARATION:
      return ast_declaration_eval(ast);
    case AST_FLOW:
      return ast_flow_eval(ast);
    case AST_JMP:
      return ast_jmp_eval(ast);
    case AST_ITER:
      return ast_iter_eval(ast);
    case AST_PROG:
      return ast_eval(ast->children->data);
    default:
      printf("AST type: %d eval not implemented yet", ast->type);
      break;
  }
  return 0;
}

void ast_child_print(ListNode *node) { ast_print(node->data); }

void ast_child_print_aux_label(const char *label, AST *ast) {
  printf("%s: { ", label);
  if (ast) ast_print(ast);
  printf("}, ");
}

void ast_print(AST *ast) {
  if (!ast) return;

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
    case AST_FLOW:
      ast_flow_print(ast);
      break;
    case AST_JMP:
      ast_jmp_print(ast);
      break;
    case AST_ITER:
      ast_iter_print(ast);
      break;
    case AST_PROG:
      LIST_FOR_EACH(ast->children, { ast_child_print(__IT__); });
      return;
    default:
      printf("AST type: %d print not implemented yet", ast->type);
      break;
  }
  printf(", ");
}
