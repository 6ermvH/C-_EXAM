#include "intrusive_list.h"

#include <stdio.h>
#include <stdlib.h>

void init_list(List* list) {
  list->head = NULL;
  list->size = 0;
}

void add_node(List* list, Node* node) {
  if (list->head != NULL) {
    list->head->prev = node;
  }
  node->next = list->head;
  list->head = node;
  ++list->size;
}

void remove_node(List* list, Node* node) {
  if (node == NULL) {
    return;
  }
  Node* next_node = node->next;
  Node* prev_node = node->prev;
  if (node == list->head) {
    list->head = next_node;
  }
  if (next_node != NULL) {
    next_node->prev = prev_node;
  }
  if (prev_node != NULL) {
    prev_node->next = next_node;
  }
  --list->size;
}

size_t get_length(List* list) { return list->size; }


