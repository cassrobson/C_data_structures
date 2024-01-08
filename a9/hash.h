/*
 -------------------------------------
 File:    hash.h
 Project: cp264_a7
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-03-12
 -------------------------------------
 */ 
#ifndef HASH_H
#define HASH_H

typedef struct hashnode {
  char name[20]; // used as key 
  int value;
  struct hashnode *next; 
} HASHNODE;

typedef struct hashtable {
  HASHNODE **hna;
  int size;      
  int count; 
} HASHTABLE;

int hash(char *name); 
HASHNODE *new_hashnode(char *name, int vale); 
HASHTABLE *new_hashtable(int size); 
HASHNODE *search(HASHTABLE *ht, char *name);
int insert(HASHTABLE *ht, HASHNODE *np);
int delete(HASHTABLE *ht, char *name);
void clean_hash(HASHTABLE **ht);
#endif