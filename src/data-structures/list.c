#include "data-structures/list.h"

#include <stdio.h>
#include <stdlib.h>

ListNode *list_node_init(void *data) {
  return list_node_init_extra(data, NULL, NULL);
}

ListNode *list_node_init_extra(void *data, ListNode *next, ListNode *parent) {
  ListNode *node = calloc(1, sizeof(ListNode));
  node->data = data;
  node->next = next;
  node->parent = parent;
  return node;
}

unsigned int list_empty(ListNode *head) { return !head || !list_size(head); }

unsigned int list_size(ListNode *head) {
  unsigned int k = 0;
  for (ListNode *it = head; it; it = it->next, ++k)
    ;
  return k;
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

void list_free_reverse(ListNode *head, list_free_fn free_fn) {
  ListNode *it = head;
  while (it) {
    ListNode *tmp = it->parent;
    list_node_free(it, free_fn);
    it = tmp;
  }
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

void list_pop_front(ListNode **head, list_free_fn free_cb) {
  ListNode *first = *head;
  *head = (*head)->next;
  if (*head) (*head)->parent = NULL;
  list_node_free(first, free_cb);
}

void *list_peek(ListNode **head, unsigned int index) {
  int i = 0;
  for (ListNode *it = *head; it; it = it->next, ++i) {
    if (i == index) return it->data;
  }
  return NULL;
}

void *list_peek_reverse(ListNode **head, unsigned int index) {
  int i = 0;
  for (ListNode *it = *head; it; it = it->parent, ++i) {
    if (i == index) return it->data;
  }
  return NULL;
}

void *list_peek_last(ListNode **head) {
  ListNode *it = *head;
  if (!it) return NULL;

  while (it->next) it = it->next;
  return it->data;
}
