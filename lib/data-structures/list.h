#pragma once

typedef struct cipl_list_node {
  void *data;
  struct cipl_list_node *next;
  struct cipl_list_node *parent;
} ListNode;

typedef void (*list_free_fn)(ListNode *);
typedef void (*list_for_each_cb)(ListNode *node);

void list_free(ListNode *head, list_free_fn free_cb);
void list_free_reverse(ListNode *head, list_free_fn free_cb);

ListNode *list_node_init_extra(void *data, ListNode *next, ListNode *parent);
ListNode *list_node_init(void *data);
void list_node_free(ListNode *node, list_free_fn free_cb);

void list_push(ListNode **head, void *data);
void list_pop(ListNode **head, list_free_fn free_cb);
void list_pop_front(ListNode **head, list_free_fn free_cb);

unsigned int list_empty(ListNode *head);
unsigned int list_size(ListNode *head);

void *list_peek(ListNode **head, unsigned int index);
void *list_peek_reverse(ListNode **head, unsigned int index);
void *list_peek_last(ListNode **head);

#define LIST_FOR_EACH(__FE_ARG__, __CODE__) \
  {                                         \
    ListNode *__IT__ = __FE_ARG__;          \
    unsigned int __K__ = 0;                 \
    while (__IT__) {                        \
      ListNode *__IT_NXT__ = __IT__->next;  \
      __CODE__;                             \
      __IT__ = __IT_NXT__;                  \
      ++__K__;                              \
    }                                       \
  }

#define LIST_FREE(__F_ARG__, __CODE__)     \
  {                                        \
    ListNode *__IT__ = __F_ARG__;          \
    unsigned int __K__ = 0;                \
    while (__IT__) {                       \
      ListNode *__IT_NXT__ = __IT__->next; \
      __CODE__;                            \
      free(__IT__);                        \
      ++__K__;                             \
      __IT__ = __IT_NXT__;                 \
    }                                      \
  }
