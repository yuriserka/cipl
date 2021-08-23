#pragma once

typedef struct cipl_list_node {
  void *data;
  struct cipl_list_node *next;
} ListNode;

typedef void (*list_free_fn)(ListNode *);

void list_free(ListNode *head, list_free_fn free_cb);

ListNode *list_node_init(void *data);
void list_node_free(ListNode *node, list_free_fn free_cb);

void list_push(ListNode **head, void *data);

void list_pop(ListNode **head, list_free_fn free_cb);

void *list_peek(ListNode **head, unsigned int index);

void list_for_each(ListNode *head, void (*cb)(ListNode *node));
