#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
    if (!qp || !np) return;
    np->next = NULL; // Ensure the new node does not point to anything
    
    if (qp->rear) {
        qp->rear->next = np; // Link the new node to the end of the queue
    } else {
        qp->front = np; // If the queue was empty, set front to new node
    }
    
    qp->rear = np;
    qp->length++;
}

NODE *dequeue(QUEUE *qp) {
    if (!qp || !qp->front) return NULL;
    
    NODE *temp = qp->front;
    qp->front = qp->front->next;
    temp->next = NULL; // Disconnect from the queue
    
    if (!qp->front) {
        qp->rear = NULL; // If queue becomes empty, reset rear as well
    }
    
    qp->length--;
    return temp;
}

void clean_queue(QUEUE *qp) {
    if (!qp) return;
    clean(&(qp->front));
    qp->front = NULL;
    qp->rear = NULL;
    qp->length = 0;
}
