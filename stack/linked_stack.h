#ifndef LINKED_STACK
#define LINKED_STACK
#include "../singly_linked_list/singly_linked_list.h"
typedef struct
{
  int size;
  sll *stack;
} linked_stack;

linked_stack *stack_init(void (*destroy)(node *delete_node), void (*print)(node *head));
void push(linked_stack *stack, void *val);
void *pop(linked_stack *stack);
unsigned int stack_size(linked_stack *stack);
void destroy_stack(linked_stack *stack);

#endif
