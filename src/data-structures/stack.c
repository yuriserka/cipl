#include "data-structures/stack.h"
#include "data-structures/scope.h"

#include <stdlib.h>
#include <stdio.h>

void stack_push(StackNode **top, void *data) {
  StackNode *new_node = list_node_init(data);
  new_node->next = *top;
  *top = new_node;
}

void stack_pop(StackNode **top, list_free_fn cb) {
  StackNode *node = *top;
  *top = (*top)->next;
  list_node_free(node, cb);
}

void *stack_peek(StackNode **top) {
  return *top ? (*top)->data : NULL;
}

void stack_free(StackNode *top, list_free_fn cb) { list_free(top, cb); }
