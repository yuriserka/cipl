#include "data-structures/stack.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/scope.h"

void stack_push(StackNode **top, void *data) {
  StackNode *new_node = list_node_init(data);
  new_node->parent = *top;
  if (*top) (*top)->next = new_node;
  *top = new_node;
}

void stack_pop(StackNode **top, list_free_fn cb) {
  StackNode *node = *top;
  *top = (*top)->parent;
  if (*top) (*top)->next = NULL;
  list_node_free(node, cb);
}

void *stack_peek(StackNode **top) { return *top ? (*top)->data : NULL; }

void stack_free(StackNode *top, list_free_fn cb) { list_free_reverse(top, cb); }
