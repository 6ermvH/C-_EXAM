#ifndef CLIST_H_
#include <stddef.h>
#define CLIST_H_

typedef struct node {
  int value;
  struct node* next;
  struct node* prev;
} Node;

typedef struct list {
  Node* head;
  size_t size;
} List;

void init_list(List* list);
void insert(List* list, int val);
void erase(List* list, int val);
static void add_node(List* list, Node* node);
static void remove_node(List* list, Node* node);

size_t get_length(List* list);

#endif

