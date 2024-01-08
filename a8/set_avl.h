/*
 -------------------------------------
 File:    set_avl.h
 Project: cp264_a7
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-03-12
 -------------------------------------
 */
 
#ifndef SET_AVL_H
#define SET_AVL_H
#include "avl.h"

typedef struct {
  TNODE *root;
  int size;
} SET;

int size(SET *s);
int contains_element(SET *s, char *e); 
void add_element(SET *s, char *e);
void remove_element(SET *s, char *e);
void clear_set(SET *s);

#endif 