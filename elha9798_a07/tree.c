/*
 * your program signature
 */ 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include "queue_stack.h"
 #include "tree.h"
 
 TPROPS tree_property(TNODE *root) {
    if (root == NULL) {
        return (TPROPS){0, -1}; // Empty tree has height -1
    }

    TPROPS left = tree_property(root->left);
    TPROPS right = tree_property(root->right);

    TPROPS result;
    result.order = 1 + left.order + right.order; // Total nodes
    result.height = 1 + (left.height > right.height ? left.height : right.height); // Max height

    return result;
}
 
 void preorder(TNODE *root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
 
 void inorder(TNODE *root) {
    if (root) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}
 
 void postorder(TNODE *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}
 
 void bforder(TNODE *root) {
    if (root == NULL) return;

    QUEUE queue = {0};
    enqueue(&queue, root);

    while (queue.front) {
        TNODE *current = dequeue(&queue);
        printf("%c ", current->data);

        if (current->left) enqueue(&queue, current->left);
        if (current->right) enqueue(&queue, current->right);
    }
}
 
 TNODE *bfs(TNODE *root, char val) {
    if (root == NULL) return NULL;

    QUEUE queue = {0};
    enqueue(&queue, root);

    while (queue.front) {
        TNODE *current = dequeue(&queue);
        if (current->data == val) return current;

        if (current->left) enqueue(&queue, current->left);
        if (current->right) enqueue(&queue, current->right);
    }
    return NULL;
}
 
 TNODE *dfs(TNODE *root, char val) {
    if (root == NULL) return NULL;

    STACK stack = {0};
    push(&stack, root);

    while (stack.top) {
        TNODE *current = pop(&stack);
        if (current->data == val) return current;

        if (current->right) push(&stack, current->right);
        if (current->left) push(&stack, current->left);
    }
    return NULL;
}

 
 
 
 // the following functions are given, need to add to your program.
 
 TNODE *tree_node(char val) {
     TNODE *np = (TNODE *) malloc(sizeof(TNODE));
     if (np != NULL) {
         np->data = val;
         np->left = NULL;
         np->right = NULL;
     }
     return np;
 }
 
 void clean_tree(TNODE **rootp) {
     TNODE *p = *rootp;
     if (p) {
         if (p->left)
             clean_tree(&p->left);
         if (p->right)
             clean_tree(&p->right);
         free(p);
     }
     *rootp = NULL;
 }
 
 void insert_tree(TNODE **rootp, char val) {
     if (*rootp == NULL) {
         *rootp = tree_node(val);
     } else {
         QUEUE queue = { 0 };
         TNODE *p;
         enqueue(&queue, *rootp);
         while (queue.front) {
             p = dequeue(&queue);
             if (p->left == NULL) {
                 p->left = tree_node(val);
                 break;
             } else {
                 enqueue(&queue, p->left);
             }
 
             if (p->right == NULL) {
                 p->right = tree_node(val);
                 break;
             } else {
                 enqueue(&queue, p->right);
             }
         }
     }
 }