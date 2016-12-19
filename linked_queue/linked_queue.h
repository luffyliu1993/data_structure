#ifndef LINKED_QUEUE
#define LINKED_QUEUE
#include <stdlib.h>
#include "../singly_linked_list/singly_linked_list.h"

typedef struct
{
    unsigned int size;
    sll *queue;
}linked_queue;

linked_queue *queue_init(void (*destroy)(node *delete_node), void (*print)(node *head))
{
    linked_queue *new_queue = malloc(sizeof(linked_queue));
    new_queue->queue = list_init(destroy, print);
    new_queue->size = 0;
    return new_queue;
}

void *peek(linked_queue *queue)
{
    if(queue == NULL)
    {
        printf("Please init queue first\n");
        return NULL;
    }
    return head_val(queue->queue);
}

unsigned queue_size(linked_queue *queue)
{
    if(queue == NULL)
    {
        printf("Please init queue first\n");
        return NULL;
    }
    return queue->size;
}

void enqueue(linked_queue *queue, void *val)
{
    if(queue == NULL)
    {
        printf("Please init queue first\n");
        return;
    }
    add_back(queue->queue, val);
    queue->size++;
}

void *dequeue(linked_queue *queue)
{
    if(queue == NULL || queue_size(queue) == 0)
    {
        printf("Empty queue\n");
        return NULL;
    }
    void *delete_val = peek(queue);
    remove_front(queue->queue);
    queue->size--;
    return delete_val;
}



void destroy_queue(linked_queue *queue)
{
    destroy_list(queue->queue);
    queue->size = 0;
    queue->queue = NULL;
    free(queue);
    //queue = NULL;
    //return NULL;
}

#endif
