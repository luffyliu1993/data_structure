#include "linked_stack.h"
#include <stdlib.h>
#include <stdio.h>

linked_stack *stack_init(void (*destroy)(node *delete_node), void (*print)(node *head))
{
  linked_stack *new_stack = (linked_stack*) malloc(sizeof(linked_stack));
  new_stack->stack = list_init(destroy, print);
  new_stack->size = 0;
  return new_stack;
}

void push(linked_stack *stack, void* val)
{
  if(stack == NULL)
  {
    printf("Please init stack first\n");
    return;
  }
  add_front(stack->stack, val);
  stack->size++;
}

void *pop(linked_stack *stack)
{
  if(stack == NULL || stack->size == 0)
  {
    printf("Empty list\n");
  }
  void *returned_data = head_val(stack->stack);
  remove_front(stack->stack);
  stack->size--;
  return returned_data;
}

unsigned int stack_size(linked_stack *stack)
{
  if(stack == NULL)
  {
    printf("Please init stack first\n");
    return;
  }
  return stack->size;
}

void destroy_stack(linked_stack *stack)
{
  destroy_list(stack->stack);
  free(stack);
  stack->size = 0;
}
