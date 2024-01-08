/*
 -------------------------------------
 File:    avl.h
 Project: cp264_a7
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-03-12
 -------------------------------------
 */
 
#ifndef AVL_H
#define AVL_H

typedef struct record {
  char name[40];
  float score;
} RECORD;

typedef struct tnode {
    RECORD data;
    int height;
    struct tnode *left;
    struct tnode *right;
} TNODE;

int balance_factor(TNODE *root);
int is_avl(TNODE *root);
TNODE *rotate_left(TNODE *root);  
TNODE *rotate_right(TNODE *root);
void insert_avl(TNODE **rootp, char *name, float score);
void delete_avl(TNODE **rootp, char *name);  
TNODE *search_avl(TNODE *root, char *name);
void clear_tree(TNODE **rootp); 
#endif