#include "../singly_linked_list/singly_linked_list.h"
#include "linked_stack.h"
#include <stdio.h>
#include <stdlib.h>

void int_print(node *head)
{
  if(head == NULL)
  {
    printf("Empty list\n");
    return;
  }
  node *temp = head;
  for(;temp != NULL; temp = temp->next)
  {
    if(temp->next == NULL)
    {
      printf("%d\n", temp->val);
    }
    else
    {
      printf("%d->",temp->val);
    }
  }
}

void destroy(node *delete_node)
{
  free(delete_node);
}

int main(void)
{
  linked_stack *stack = stack_init(destroy, int_print);
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  push(stack, 4);
  push(stack, 5);
  printf("stack size: %d\n", stack_size(stack));
  stack->stack->print(stack->stack->head);
  printf("%d\n",pop(stack));
  printf("stack size: %d\n", stack_size(stack));
  stack->stack->print(stack->stack->head);
  destroy_stack(stack);
  if(stack->size == 0)
  {
    printf("Stack is empty now\n");
  }
  printf("%d\n",size(stack->stack));
  return 0;
}
