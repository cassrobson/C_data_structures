/*
 -------------------------------------
 File:    myrecord_avl.h
 Project: cp264_a7
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-03-12
 -------------------------------------
 */ 
 
 #ifndef MYRECORD_AVL_H
#define MYRECORD_AVL_H
#include "avl.h"


typedef struct {
  int count;
  float mean;
  float stddev;
  float median;
} STATS;

typedef struct {
  TNODE *root;
  STATS stats;
} AVL;

void merge_tree(TNODE **rootp1, TNODE **rootp2); 
void merge_data(AVL *t1, AVL *t2);
void clear_avl(AVL *avl);

#endif