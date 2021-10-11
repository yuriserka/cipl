#pragma once

#include "data-structures/list.h"

typedef ListNode StackNode;

void stack_push(StackNode **top, void *data);
void *stack_peek(StackNode **top);
void stack_pop(StackNode **top, list_free_fn cb);
void stack_free(StackNode *top, list_free_fn cb);

#define STACK_FREE(__F_ARG__, __CODE__)        \
  {                                            \
    StackNode *__IT__ = __F_ARG__;             \
    unsigned int __K__ = 0;                    \
    while (__IT__) {                           \
      StackNode *__IT_PRNT__ = __IT__->parent; \
      __CODE__;                                \
      free(__IT__);                            \
      ++__K__;                                 \
      __IT__ = __IT_PRNT__;                    \
    }                                          \
  }

#define STACK_FOR_EACH(__FE_ARG__, __CODE__)   \
  {                                            \
    StackNode *__IT__ = __FE_ARG__;            \
    unsigned int __K__ = 0;                    \
    while (__IT__) {                           \
      StackNode *__IT_PRNT__ = __IT__->parent; \
      __CODE__;                                \
      __IT__ = __IT_PRNT__;                    \
      ++__K__;                                 \
    }                                          \
  }
