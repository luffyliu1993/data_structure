#include <stdio.h>
#include <stdlib.h>
#include "linked_queue.h"

static void int_print(node *head)
{
    if(head == NULL)
    {
        printf("Empty Queue\n");
        return;
    }
    node *temp = NULL;
    for(temp = head; temp != NULL; temp=temp->next)
    {
        if(temp->next == NULL)
        {
            printf("%d\n",temp->val);
        }
        else
        {
            printf("%d->",temp->val);
        }
    }
}

static void destroy(node *delete_node)
{
    free(delete_node);
    delete_node = NULL;
}

int main(void)
{
    linked_queue *queue = queue_init(destroy, int_print);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    queue->queue->print(queue->queue->head);
    printf("peek: %d\n", peek(queue));
    printf("size: %d\n",queue_size(queue));
    dequeue(queue);
    queue->queue->print(queue->queue->head);
    printf("peek: %d\n", peek(queue));
    printf("size: %d\n",queue_size(queue));
    enqueue(queue,6);
    queue->queue->print(queue->queue->head);
    printf("peek: %d\n", peek(queue));
    printf("size: %d\n",queue_size(queue));
    destroy_queue(queue);
    queue = NULL;
    printf("peek: %d\n", peek(queue));
    printf("size: %d\n",queue_size(queue));
    return 0;
}
