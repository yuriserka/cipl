#include "data-structures/ast/ast.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils/asm/asm.h"
#include "utils/io.h"

#define AST_INIT_UNION(MEM, TGT) \
  (AstNodeValue) { .MEM = va_arg(ptr, TGT *) }

AST *ast_cast(AstTypes type, YYLTYPE rule_pos, int n_children, ...) {
  AST *ast = calloc(1, sizeof(AST));
  ast->type = type;
  ast->rule_pos = rule_pos;

  ++n_children;

  va_list ptr;
  va_start(ptr, n_children);

  switch (type) {
    case AST_NUMBER:
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
    case AST_PARAM_LIST:
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
    case AST_FUNC_CALL:
      ast->value = AST_INIT_UNION(funcall, FunctionCallAST);
      break;
    case AST_STR_LITERAL:
      ast->value = AST_INIT_UNION(str, StringLiteralAST);
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

void ast_free(AST *ast) {
  if (!ast) return;

  switch (ast->type) {
    case AST_NUMBER:
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
    case AST_PARAM_LIST:
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
    case AST_FUNC_CALL:
      ast_funcall_free(ast);
      break;
    case AST_STR_LITERAL:
      ast_str_free(ast);
      break;
    case AST_BUILTIN_FUNC:
      ast_builtinfn_free(ast);
      break;
    case AST_PROG:
      LIST_FREE(ast->children, { ast_free(__IT__->data); });
      break;
    default:
      printf("AST type: %d free not implemented yet\n", ast->type);
      break;
  }
  free(ast);
}

SymbolValues ast_eval(AST *ast) {
  if (!ast) return (SymbolValues){.integer = 0};

  switch (ast->type) {
    case AST_NUMBER:
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
    case AST_PARAM_LIST:
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
    case AST_FUNC_CALL:
      return ast_funcall_eval(ast);
    case AST_STR_LITERAL:
      return ast_str_eval(ast);
    case AST_BUILTIN_FUNC:
      return ast_builtinfn_eval(ast);
    case AST_PROG:
      return ast_eval(ast->children->data);
    default:
      printf("AST type: %d eval not implemented yet\n", ast->type);
      break;
  }

  return (SymbolValues){.integer = 0};
}

void ast_child_print_aux_label(const char *label, AST *ast) {
  printf("%s: { ", label);
  if (ast) ast_print(ast);
  printf("}, ");
}

void ast_print(AST *ast) {
  if (!ast) return;

  switch (ast->type) {
    case AST_NUMBER:
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
    case AST_PARAM_LIST:
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
    case AST_FUNC_CALL:
      ast_funcall_print(ast);
      break;
    case AST_STR_LITERAL:
      ast_str_print(ast);
      break;
    case AST_BUILTIN_FUNC:
      ast_builtinfn_print(ast);
      break;
    case AST_PROG:
      LIST_FOR_EACH(ast->children, { ast_print(__IT__->data); });
      return;
    default:
      printf("AST type: %d print not implemented yet\n", ast->type);
      break;
  }
  printf(", ");
}

void ast_print_pretty(AST *ast, int depth) {
  if (!ast) return;

  switch (ast->type) {
    case AST_NUMBER:
      ast_number_print_pretty(ast, depth);
      break;
    case AST_BUILTIN_FUNC:
      ast_builtinfn_print_pretty(ast, depth);
      break;
    case AST_BIN_OP:
      ast_binop_print_pretty(ast, depth);
      break;
    case AST_UNI_OP:
      ast_uniop_print_pretty(ast, depth);
      break;
    case AST_ASSIGN_OP:
      ast_assign_print_pretty(ast, depth);
      break;
    case AST_SYM_REF:
      ast_symref_print_pretty(ast, depth);
      break;
    case AST_USER_FUNC:
      ast_userfunc_print_pretty(ast, depth);
      break;
    case AST_PARAM_LIST:
      ast_params_print_pretty(ast, depth);
      break;
    case AST_BLOCK_ITEM_LIST:
      ast_blockitems_print_pretty(ast, depth);
      break;
    case AST_DECLARATION:
      ast_declaration_print_pretty(ast, depth);
      break;
    case AST_FLOW:
      ast_flow_print_pretty(ast, depth);
      break;
    case AST_JMP:
      ast_jmp_print_pretty(ast, depth);
      break;
    case AST_ITER:
      ast_iter_print_pretty(ast, depth);
      break;
    case AST_FUNC_CALL:
      ast_funcall_print_pretty(ast, depth);
      break;
    case AST_STR_LITERAL:
      ast_str_print_pretty(ast, depth);
      break;
    case AST_PROG:
      CIPL_PRINTF_COLOR(BMAG, "<root>\n");
      LIST_FOR_EACH(ast->children,
                    { ast_print_pretty(__IT__->data, depth + 1); });
      break;
    default:
      printf("AST type: %d print not implemented yet\n", ast->type);
      break;
  }
}

SymbolTypes ast_validate_types(AST *ast) {
  if (!ast) return SYM_INVALID;

  switch (ast->type) {
    case AST_NUMBER:
      return ast_number_type_check(ast);
    case AST_BIN_OP:
      return ast_binop_type_check(ast);
    case AST_UNI_OP:
      return ast_uniop_type_check(ast);
    case AST_SYM_REF:
      return ast_symref_type_check(ast);
    case AST_ASSIGN_OP:
      return ast_assign_type_check(ast);
    case AST_USER_FUNC:
      return ast_userfunc_type_check(ast);
    case AST_JMP:
      return ast_jmp_type_check(ast);
    case AST_BLOCK_ITEM_LIST:
      return ast_blockitems_type_check(ast);
    case AST_DECLARATION:
      return ast_declaration_type_check(ast);
    case AST_FUNC_CALL:
      return ast_funcall_type_check(ast);
    case AST_BUILTIN_FUNC:
      return ast_builtinfn_type_check(ast);
    case AST_STR_LITERAL:
      return ast_str_type_check(ast);
    case AST_FLOW:
      return ast_flow_type_check(ast);
    case AST_ITER:
      return ast_iter_type_check(ast);
    case AST_PROG: {
      SymbolTypes ret = SYM_PTR;
      LIST_FOR_EACH(ast->children,
                    { ret = ret && ast_validate_types(__IT__->data); });
      return ret;
    }
    default:
      printf("AST type: %d type_check not implemented yet\n", ast->type);
      break;
  }

  return SYM_INVALID;
}

void ast_gen_code_init(FILE *out) {
  asm_generate_table_header(out);
  asm_generate_code_header(out);
}

void ast_gen_code_end(FILE *out) { asm_generate_code_end(out); }

void ast_gen_code(AST *ast, FILE *out) {
  if (!ast) return;

  switch (ast->type) {
    case AST_USER_FUNC:
      ast_userfunc_gen_code(ast, out);
      break;
    case AST_FUNC_CALL:
      ast_funcall_gen_code(ast, out);
      break;
    case AST_BLOCK_ITEM_LIST:
      ast_blockitems_gen_code(ast, out);
      break;
    case AST_JMP:
      ast_jmp_gen_code(ast, out);
      break;
    case AST_NUMBER:
      ast_number_gen_code(ast, out);
      break;
    case AST_BUILTIN_FUNC:
      ast_builtinfn_gen_code(ast, out);
      break;
    case AST_DECLARATION:
      ast_declaration_gen_code(ast, out);
      break;
    case AST_ASSIGN_OP:
      ast_assign_gen_code(ast, out);
      break;
    case AST_SYM_REF:
      ast_symref_gen_code(ast, out);
      break;
    case AST_PROG:
      LIST_FOR_EACH(ast->children, { ast_gen_code(__IT__->data, out); });
      break;
    default:
      printf("AST type: %d gen_code not implemented yet\n", ast->type);
      break;
  }
}

void ast_fake_stack_pop(ListNode *node) {}

AST *ast_find_node(AST *root, AstTypes type) {
  StackNode *l = list_node_init(root);
  AST *v = NULL;
  while ((v = stack_peek(&l))) {
    stack_pop(&l, ast_fake_stack_pop);

    if (v->type == type) break;

    switch (v->type) {
      case AST_BLOCK_ITEM_LIST:
        LIST_FOR_EACH(v->value.blockitems->value, {
          AST *child = __IT__->data;
          if (child) stack_push(&l, child);
        });
        break;
      case AST_PARAM_LIST:
        LIST_FOR_EACH(v->value.params->value, {
          AST *child = __IT__->data;
          if (child) stack_push(&l, child);
        });
        break;
      default:
        LIST_FOR_EACH(v->children, {
          AST *child = __IT__->data;
          if (child) stack_push(&l, child);
        });
    }
  }

  stack_free(l, ast_fake_stack_pop);

  return v;
}
