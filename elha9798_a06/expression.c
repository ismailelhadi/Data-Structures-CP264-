#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

QUEUE infix_to_postfix(char *infixstr) {
    QUEUE queue = {0, NULL, NULL};
    STACK stack = {0, NULL};

    for (int i = 0; infixstr[i] != '\0'; i++) {
        if (isdigit(infixstr[i])) {
            NODE *np = create_node(infixstr[i]);
            enqueue(&queue, np);
        } else if (is_operator(infixstr[i])) {
            while (stack.length > 0 && precedence(stack.top->data) >= precedence(infixstr[i])) {
                enqueue(&queue, pop(&stack));
            }
            push(&stack, create_node(infixstr[i]));
        } else if (infixstr[i] == '(') {
            push(&stack, create_node(infixstr[i]));
        } else if (infixstr[i] == ')') {
            while (stack.length > 0 && stack.top->data != '(') {
                enqueue(&queue, pop(&stack));
            }
            pop(&stack); // Remove '(' from the stack
        }
    }
    
    while (stack.length > 0) {
        enqueue(&queue, pop(&stack));
    }
    
    return queue;
}

int evaluate_postfix(QUEUE queue) {
    STACK stack = {0, NULL};
    
    while (queue.length > 0) {
        NODE *node = dequeue(&queue);
        if (isdigit(node->data)) {
            push(&stack, node);
        } else if (is_operator(node->data)) {
            int b = pop(&stack)->data - '0';
            int a = pop(&stack)->data - '0';
            int result;
            switch (node->data) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            push(&stack, create_node(result + '0'));
        }
    }
    return pop(&stack)->data - '0';
}

int evaluate_infix(char *infixstr) {
    QUEUE postfix = infix_to_postfix(infixstr);
    return evaluate_postfix(postfix);
}
