#ifndef SINGLY_LINGKED_LIST
#define SINGLY_LINGKED_LIST

typedef struct Node
{
  void *val;
  struct Node *next;
} node;

typedef struct SLL
{
  node *head;
  node *tail;
  int size;
  void (*destroy)(node *delete_node);
  void (*print)(node *head);
} sll;

sll* list_init(void (*destroy)(node *delete_node), void (*print)(node *head));
void add_back(sll *list, void *val);
void print_list(sll *list);
void reverse(sll *list);
void add_front(sll *list, void *val);
void remove_back(sll *list);
void remove_front(sll *list);
void *head_val(sll *list);
void *tail_val(sll *list);
void destroy_list(sll *list);

#endif
