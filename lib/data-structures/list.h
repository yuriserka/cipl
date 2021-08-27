#pragma once

typedef struct cipl_list_node {
  void *data;
  struct cipl_list_node *next;
  struct cipl_list_node *parent;
} ListNode;

typedef void (*list_free_fn)(ListNode *);
typedef void (*list_for_each_cb)(ListNode *node);

void list_free(ListNode *head, list_free_fn free_cb);

ListNode *list_node_init_extra(void *data, ListNode *next, ListNode *parent);

ListNode *list_node_init(void *data);
void list_node_free(ListNode *node, list_free_fn free_cb);

void list_push(ListNode **head, void *data);

void list_pop(ListNode **head, list_free_fn free_cb);

void *list_peek(ListNode **head, unsigned int index);

#define LIST_FOR_EACH(__FE_ARG__, __MAP_CODE__) \
  {                                             \
    ListNode *__MAP_IT__ = __FE_ARG__;          \
    while (__MAP_IT__) {                        \
      ListNode *__MAP_TMP__ = __MAP_IT__->next; \
      __MAP_CODE__;                             \
      __MAP_IT__ = __MAP_TMP__;                 \
    }                                           \
  }

#define LIST_FOR_EACH_REVERSE(__FE_ARG__, __MAP_CODE__) \
  {                                                     \
    ListNode *__MAP_IT__ = __FE_ARG__;                  \
    while (__MAP_IT__) {                                \
      ListNode *__MAP_TMP__ = __MAP_IT__->parent;       \
      __MAP_CODE__;                                     \
      __MAP_IT__ = __MAP_TMP__;                         \
    }                                                   \
  }

#define LIST_FREE(__F_ARG__, __MAP_CODE__)      \
  {                                             \
    ListNode *__MAP_IT__ = __F_ARG__;           \
    while (__MAP_IT__) {                        \
      ListNode *__MAP_TMP__ = __MAP_IT__->next; \
      __MAP_CODE__;                             \
      free(__MAP_IT__);                         \
      __MAP_IT__ = __MAP_TMP__;                 \
    }                                           \
  }

#define LIST_FREE_REVERSE(__FE_ARG__, __MAP_CODE__) \
  {                                                 \
    ListNode *__MAP_IT__ = __FE_ARG__;              \
    while (__MAP_IT__) {                            \
      ListNode *__MAP_TMP__ = __MAP_IT__->parent;   \
      __MAP_CODE__;                                 \
      free(__MAP_IT__);                             \
      __MAP_IT__ = __MAP_TMP__;                     \
    }                                               \
  }
