#include "data-structures/stack.h"

#include <stdlib.h>

StackNode *stack_node_init(void *data) {
  StackNode *n = calloc(1, sizeof(StackNode));
  n->value = data;
  return n;
}

void stack_node_destroy(StackNode *node) {
  free(node->value);
  free(node);
}

void stack_destroy(StackNode **root) {
    free(*root);
}

void stack_push(StackNode **root, void *data) {
  StackNode *stackNode = stack_node_init(data);
  stackNode->next = *root;
  *root = stackNode;
}

void stack_pop(StackNode **root) {
  if (*root) {
    StackNode *temp = *root;
    *root = (*root)->next;
    free(temp);
  }
}

void *stack_peek(StackNode *root) {
  return root->value;
}
