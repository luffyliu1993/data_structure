#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

sll* list_init(void (*destroy)(node* delete_node), void (*print)(node *head))
{
  sll *list = (sll*) malloc(sizeof(sll));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  list->destroy = destroy;
  list->print = print;
  return list;
}

void add_back(sll *list, void *val)
{
  if(list == NULL)
  {
    printf("Please init the list first\n");
    return;
  }
  /*segmentaion fault problem is not initializing the list*/
  node *new_node = (node*) malloc(sizeof(node));
  new_node->val = val;
  new_node->next = NULL;
  if(list->head == NULL)
  {
    list->head = list->tail = new_node;
  }
  else
  {
    list->tail->next = new_node;
    list->tail = list->tail->next;
  }
  list->size++;
}

void add_front(sll *list, void *val)
{
  if(list == NULL)
  {
    printf("Please init the list first\n");
  }
  node *new_node = (node*) malloc(sizeof(node));
  new_node->val = val;
  new_node->next = list->head;
  if(list->head == NULL)
  {
    list->head = list->tail = new_node;
  }
  else
  {
    list->head = new_node;
  }
  list->size++;
}

void remove_front(sll *list)
{
  if(list == NULL)
  {
    printf("Please init the list first\n");
    return;
  }
  if(list->head == NULL)
  {
    printf("Empty List\n");
    return;
  }
  node *temp = list->head;
  /*case for one node in the list*/
  if(list->head == list->tail)
  {
    list->head = list->tail = list->head->next;
  }
  else
  {
    /*case for more than one node in the list*/
    list->head = list->head->next;
  }
  list->destroy(temp);
  list->size--;
}

/*o(n) for sll*/
void remove_back(sll *list)
{
  if(list == NULL)
  {
    printf("Please init the list first\n");
    return;
  }
  if(list->head == NULL)
  {
    printf("Empty List\n");
    return;
  }
  node *temp = list->tail;
  /*case for one node in the list*/
  if(list->head == list->tail)
  {
    list->head = list->tail = list->tail->next;
  }
  else
  {
    /*case for more than one node in the list*/
    node *temp = NULL;
    for(temp = list->head; temp != NULL; temp = temp->next)
    {
      if(temp->next == list->tail)
      {
        temp->next = NULL;
        list->tail = temp;
      }
    }
  }
  list->destroy(temp);
  list->size--;
}

void *head_val(sll *list)
{
  if(list == NULL)
  {
    printf("Please init the list first\n");
    return NULL;
  }
  if(list->head == NULL)
  {
    printf("Empty list\n");
    return NULL;
  }
  return list->head->val;
}

void *tail_val(sll *list)
{
  if(list == NULL)
  {
    printf("Please init the list first\n");
    return NULL;
  }
  if(list->tail == NULL)
  {
    printf("Empty List\n");
    return NULL;
  }
  return list->tail->val;
}

unsigned int size(sll *list)
{
  if(list == NULL)
  {
    printf("Please init the list first\n");
    return NULL;
  }
  return list->size;
}

void reverse(sll *list)
{
  if(list == NULL)
  {
    printf("Please init the list first\n");
    return;
  }
  if(list->size == 1)
  {
    return;
  }
  list->tail = list->head;
  node *prev = NULL;
  node *curr = list->head;
  node *next = NULL;
  while(curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  list->head = prev;
}

void destroy_list(sll *list)
{
  if(list == NULL)
    {
      printf("Empty list\n");
      return;
    }
  node *temp = list->head;
  node *next = NULL;
  for(;temp != NULL; temp = next)
    {
      next = temp->next;
      free(temp);
    }
  list->size = 0;
  free(list);
}
