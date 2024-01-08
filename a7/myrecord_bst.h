/*
 -------------------------------------
 File:    myrecord_bst.h
 Project: cp264_a7
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-03-10
 -------------------------------------
 */
 
#ifndef MYRECORD_BST_H
#define MYRECORD_BST_H
#include "bst.h"

typedef struct {
  TNODE *root;
} BST;

typedef struct {
  int count;
  float mean;
  float stddev;
  float median;
} STATS;

void add_data(BST *bst, STATS *stats, char *name, float score);
void remove_data(BST *bst, STATS *stats, char *name);
#endif