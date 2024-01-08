
/*
 -------------------------------------
 File:    stack.c
 Project: cp264_a6
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-03-03
 -------------------------------------
 */
#include <stdio.h>
#include "stack.h"
#include <stdlib.h>


void push(STACK *sp, NODE *np) {
    np->next = sp->top;
    sp->top = np;
    sp->height++;
}

NODE *pop(STACK *sp) {
    NODE *ptr = sp->top;
    if(ptr != NULL){
        if(sp->height == 1){
            sp->top = NULL;
        } else {
            sp->top = sp->top->next;
        }
        sp->height--;
    }
    return ptr;
}

void clean_stack(STACK *sp) {
    NODE *temp;
    NODE *ptr = sp->top;
    while(ptr != NULL){
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    sp->top = NULL;
    sp->height = 0;
}