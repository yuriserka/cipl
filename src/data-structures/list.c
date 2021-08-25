#include "data-structures/list.h"

#include <stdio.h>
#include <stdlib.h>

ListNode *list_node_init(void *data) { return list_node_init_next(data, NULL); }

ListNode *list_node_init_next(void *data, ListNode *next) {
  ListNode *node = calloc(1, sizeof(ListNode));
  node->data = data;
  node->next = next;
  return node;
}

void list_node_free(ListNode *node, list_free_fn cb) {
  cb ? cb(node) : free(node->data);
  free(node);
}

void list_free(ListNode *head, list_free_fn free_fn) {
  ListNode *it = head;
  while (it) {
    ListNode *tmp = it->next;
    list_node_free(it, free_fn);
    it = tmp;
  }
}

void list_push(ListNode **head, void *data) {
  if (!data) return;

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

void list_for_each(ListNode *head, list_for_each_cb cb) {
  ListNode *it = head;
  while (it) {
    ListNode *tmp = it->next;
    cb(it);
    it = tmp;
  }
}
