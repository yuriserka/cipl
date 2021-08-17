#pragma once

typedef struct __listnode {
  void *data;
  struct __listnode *next;
} ListNode;

void list_destroy(ListNode *head);

ListNode *list_node_init(void *data);
void list_node_destroy(ListNode *node);

void list_push(ListNode **head, void *data);

void list_pop(ListNode **head);

void *list_peek(ListNode **head, unsigned int index);

void list_for_each(ListNode *head, void (*cb)(ListNode *node));
