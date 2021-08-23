#include "data-structures/list.h"

#include <stdio.h>
#include <stdlib.h>

ListNode *list_node_init(void *data) {
  ListNode *node = calloc(1, sizeof(ListNode));
  node->data = data;
  node->next = NULL;
  return node;
}

void list_node_free(ListNode *node, list_free_fn cb) {
  cb ? cb(node) : free(node->data);
  free(node);
}

void list_free(ListNode *head, list_free_fn free_fn) {
  ListNode *temp;
  while (head) {
    temp = head;
    head = head->next;
    list_node_free(temp, free_fn);
  }
  free(head);
}

void list_push(ListNode **head, void *data) {
  ListNode *new_node = list_node_init(data);
  ListNode *last = *head;

  if (!last) {
    *head = new_node;
    return;
  }

  while (last->next) last = last->next;
  last->next = new_node;
}

void list_pop(ListNode **head, list_free_fn fn) {
  ListNode *last = *head;

  while (last->next) last = last->next;
  list_node_free(last, fn);
}

void *list_peek(ListNode **head, unsigned int index) {
  int i = 0;
  for (ListNode *it = *head; it; it = it->next, ++i) {
    if (i == index) return it->data;
  }
  return NULL;
}

void list_for_each(ListNode *head, void (*cb)(ListNode *node)) {
  ListNode *it = head;
  while (it) {
    cb(it);
    it = it->next;
  }
}
