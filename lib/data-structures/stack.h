#pragma once

#include "data-structures/list.h"

typedef ListNode StackNode;

void stack_push(StackNode **top, void *data);
void *stack_peek(StackNode **top);
void stack_pop(StackNode **top, list_free_fn cb);
void stack_free(StackNode *top, list_free_fn cb);
