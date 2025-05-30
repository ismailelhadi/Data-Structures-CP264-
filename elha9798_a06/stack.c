#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {
    if (!sp || !np) return;
    
    np->next = sp->top; // New node points to the current top
    sp->top = np;       // Update top to the new node
    sp->length++;
}

NODE *pop(STACK *sp) {
    if (!sp || !sp->top) return NULL;
    
    NODE *temp = sp->top;
    sp->top = sp->top->next;
    temp->next = NULL; // Disconnect from the stack
    sp->length--;
    
    return temp;
}

void clean_stack(STACK *sp) {
    if (!sp) return;
    clean(&(sp->top));
    sp->top = NULL;
    sp->length = 0;
}
