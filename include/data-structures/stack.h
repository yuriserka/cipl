#pragma once

typedef struct __stacknode {
  void *value;
  struct __stacknode *next;
} StackNode;

StackNode *stack_node_init(void *data);
void stack_node_destroy(StackNode *node);

void stack_push(StackNode **root, void *data);

void stack_pop(StackNode **root);

void *stack_peek(StackNode *root);
