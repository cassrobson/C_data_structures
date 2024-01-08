/*
 -------------------------------------
 File:    tree.c
 Project: cp264_a7
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-03-10
 -------------------------------------
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h"
#include "tree.h"

TNODE *new_node(int value) {
    TNODE *node = (TNODE *)malloc(sizeof(TNODE));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;

}

TPROPS get_props(TNODE *root) {
TPROPS r = {0};
if (root) {
    TPROPS lp = get_props(root->left);
    TPROPS rp = get_props(root->right);
    r.count = 1 + rp.count + lp.count;
    if (lp.height>rp.height) {
        r.height = lp.height + 1;
    } else {
        r.height = rp.height + 1;
    }


}
return r;
}

void display_preorder(TNODE *root) {
    if (root){
        printf("%c ", root->data);
        display_preorder(root->left);
        display_preorder(root->right);
    }
}

void display_inorder(TNODE *root) {
    if(root){
        display_inorder(root->left);
        printf("%c ", root->data);
        display_inorder(root->right);
    }
}

void display_postorder(TNODE *root) {
    if(root){
        display_postorder(root->left);
        display_postorder(root->right);
        printf("%c ", root->data);
    }
}

/* use auxiliary queue data structure for the algorithm  */
void display_bforder(TNODE *root) {
    if (root == NULL) return;
    QUEUE q = {0};
    TNODE *p = NULL;
    enqueue(&q, root);
    while (q.front) {
        p = dequeue(&q);
        if(p){
            printf("%c ", p->data);
            enqueue(&q, p->left);
            enqueue(&q, p->right);
        }
    }
}

/* use auxiliary queue data structure for the algorithm  */
TNODE *iterative_bfs(TNODE *root, int val) {
    QUEUE queue = {0};
    TNODE *r = NULL, *p = NULL;
    if (root){
        enqueue(&queue, root);
        while (queue.front){
            p = dequeue(&queue);
            if (p->data == val){
                r = p;
                break;
            }
            if(p->left) enqueue(&queue, p->left);
            if(p->right) enqueue(&queue, p->right);
        }
        clean_queue(&queue);
    }
    return r;
}

TNODE *iterative_dfs(TNODE *root, int val) {
    STACK stack = {0};
    TNODE *r = NULL, *p = NULL;
    if (root) {
        push(&stack, root);
        while(stack.top){
            p = (TNODE *)(stack.top)->data;
            if(p->data == val){
                r = p;
                break;
            }
            pop(&stack);
            if(p->right) push(&stack, p->right);
            if(p->left) push(&stack, p->left);
        }
    }
    clean_stack(&stack);
    return r;
}

void clean_tree(TNODE **rootp) {
    TNODE *p = *rootp;
    if (p) {
        if (p->left) {
            clean_tree(&p->left);
        }
        if (p->right) {
            clean_tree(&p->right);
        }
        free(p);
    }
    *rootp = NULL;
}