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

void list_for_each(ListNode *head, list_for_each_cb cb);
