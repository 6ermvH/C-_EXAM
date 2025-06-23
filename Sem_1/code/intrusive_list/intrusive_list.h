#ifndef CLIST_H_
#include <stddef.h>
#define CLIST_H_

typedef struct intrusive_node {
  struct intrusive_node* next;
  struct intrusive_node* prev;
} Node;

typedef struct intrusive_list {
  Node* head;
  size_t size;
} List;

void init_list(List* list);
void add_node(List* list, Node* node);
void remove_node(List* list, Node* node);

size_t get_length(List* list);

#endif

