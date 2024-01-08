/*
 -------------------------------------
 File:    myrecord_sllist.c
 Project: cp264_a5
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-02-17
 -------------------------------------
 */ 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include "myrecord_sllist.h"

NODE *search(SLLIST *sllistp, char *name) {
 NODE *p = sllistp->start;
 while (p != NULL){
    if(strcmp(p->data.name, name) == 0){
        return p;
    }
    p = p->next;
 }
 return NULL;
}

void insert(SLLIST *sllistp, char *name, float score) {
    NODE* np = (NODE *) malloc(sizeof(NODE));
    strcpy(np->data.name, name);
    np->data.score = score;
    np->next = NULL;
    NODE *prev = NULL, *p = sllistp->start;
    while (p!= NULL){
        if (strcmp(p->data.name, name)>=0) { //node found
            break;
        }
            prev = p; //save p to prev
            p = p->next; //move to next;
    }
    if (prev == NULL){ //empty linked list or found at start
        sllistp->start = np; //insert at beginning
        np->next = p;
    } else {
        prev->next = np; //insert between prev and p
        np->next = p;
    }
    sllistp->length++;
}


int delete(SLLIST *sllistp, char *name) {
    NODE *prev = NULL, *p = sllistp->start;
    int result = 0;
    while (!p == NULL){
        if(strcmp(p->data.name, name)==0){
            result = 1;
            break;
        }
            prev = p; //save p = prev
            p = p->next; //move to next
        }
        if (prev == NULL){ //first node is matched, first node will be deleted
            sllistp->start = p->next; //reset the start
        } else {
            prev->next = p->next; //insert between prev and p
        }
        free(p); //release the memory block of the deleted node
        return result;
    }
    


void clean(SLLIST *sllistp) {
    NODE *temp, *p = sllistp->start;
    while (p != NULL){
        temp = p;
        p = p->next;
        free(temp);
    }
    sllistp->start = NULL;
    sllistp->length = 0;

}


