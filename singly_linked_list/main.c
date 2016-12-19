#include <stdio.h>
#include "singly_linked_list.h"
#include <stdlib.h>
/*#define DESTROY(node) free(node)*/

void destroy(node *delete_node)
{
  free(delete_node);
}

void print(node *head)
{
  if(head == NULL)
  {
    printf("Empty list\n");
    return;
  }
  node *temp = NULL;
  for(temp = head; temp != NULL; temp = temp->next)
  {
    if(temp->next != NULL)
    {
      printf("%c->",temp->val);
    }
    else
    {
      printf("%c\n",temp->val);
    }
  }
}

void int_destroy(node *delete_node)
{
  free(delete_node);
  delete_node = NULL;
}

void int_print(node *head)
{
  if(head == NULL)
  {
    printf("Empty list\n");
    return;
  }
  node *temp = NULL;
  for(temp = head; temp != NULL; temp = temp->next)
  {
    if(temp->next != NULL)
    {
      printf("%d->",temp->val);
    }
    else
    {
      printf("%d\n",temp->val);
    }
  }
}

int main(void)
{
  //for character
  sll *list = list_init(destroy, print);
  add_back(list,'a');
  add_back(list,'b');
  add_back(list,'c');
  add_back(list,'d');
  add_back(list,'e');
  list->print(list->head);
  reverse(list);
  list->print(list->head);
  add_front(list, 'f');
  add_front(list, 'g');
  add_front(list, 'h');
  list->print(list->head);
  remove_front(list);
  remove_back(list);
  printf("%c\n",tail_val(list));
  printf("%c\n",head_val(list));
  list->print(list->head);

  //for integer
  sll *int_list = list_init(int_destroy,int_print);
  add_back(int_list,1);
  add_back(int_list,2);
  add_back(int_list,3);
  add_back(int_list,4);
  add_back(int_list,5);
  int_list->print(int_list->head);
  add_front(int_list, 0);
  add_front(int_list,-1);
  int_list->print(int_list->head);

  //destroy the lists
  destroy_list(list);
  destroy_list(int_list);
  list = int_list = NULL;
  return 0;
}
