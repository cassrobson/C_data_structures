/*
 -------------------------------------
 File:    hash.c
 Project: cp264_a7
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-03-12
 -------------------------------------
 */ 

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "hash.h"

extern int htsize;

int hash(char *name) {
  unsigned int value = 0, i;
  char *p = name;
  while (*p) {
    value = 31 * value + *p;
    p++;
  }
  return value % htsize;
}

HASHNODE *new_hashnode(char *name, int value) {
    HASHNODE *hnode = (HASHNODE*) malloc(sizeof(HASHNODE));
    strcpy(hnode->name, name);
    hnode->value = value;
    hnode->next = NULL;
    return hnode;
}

HASHTABLE *new_hashtable(int size) {
    HASHTABLE *ht = (HASHTABLE*) malloc(sizeof(HASHTABLE));
    ht->hna = (HASHNODE**) malloc(sizeof(HASHNODE**)*size);
    int i;
    for (i = 0; i<size;i++) *(ht->hna+i) = NULL;
    ht->size = size;
    ht->count = 0;
    return ht;
}

HASHNODE *search(HASHTABLE *ht, char *name) { 
    int i = hash(name); //compute the hash index of name
    HASHNODE *p = ht->hna[i]; //get the linked list of the hash value
    while(p){
        if(strcmp(p->name, name) == 0){
            break;
        } else {
            p = p->next;
        }
    }
    return p;
}

int insert(HASHTABLE *ht, HASHNODE *np) {
    int i = hash(np->name);
    HASHNODE *p = ht->hna[i], *prev = NULL;
    if (p == NULL) ht->hna[i] = np;
    else {
        while (p && strcmp(np->name, p->name) > 0){
            prev = p;
            p = p->next;
        }
    
    if (p && strcmp(np->name, p->name) == 0){
        //update the p node value by np->value, free np, return 0
        p->value = np->value;
        free(np);
        return 0;
    }
    //insert  np into the linked list before node p
    if (prev == NULL) ht->hna[i] = np;
    else prev->next = np;
    np->next = p;
    }
    ht->count++;
    return 1;

}


int delete(HASHTABLE *ht, char *name) {
    int i = hash(name);
    int delete  = 0;
    HASHNODE *curr = ht->hna[i]; // get the linked list of the hash value
    HASHNODE *prev = NULL;
    while (curr != NULL){
        if (strcmp(curr->name, name) == 0){
            if(prev == NULL){
                ht->hna[i] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            ht->count --;
            delete = 1;
        }
        prev = curr;
        curr = curr->next;
    }
    return delete;
}


void clean_hash(HASHTABLE **htp) {
  if (*htp == NULL) return;
  HASHTABLE *ht = *htp;
  HASHNODE *sp = ht->hna[0], *p, *temp;
  int i;
  for (i = 0; i < ht->size; i++) {
    p = ht->hna[i];
    while (p) {
      temp = p;  
      p = p->next;
      free(temp);
    }
    ht->hna[i] = NULL;
  }
  free(ht->hna);
  ht->hna = NULL;
  *htp = NULL;
}