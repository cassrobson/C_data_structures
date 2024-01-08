/*
 -------------------------------------
 File:    myrecord_avl.c
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
#include <math.h>
#include "queue_stack.h"
#include "avl.h"
#include "myrecord_avl.h"

void merge_tree(TNODE **rootp1, TNODE **rootp2) {  
  // use recursive or iterative algorithm to traverse tree rootp2, 
  // get record data of each node and insert into rootp1
  QUEUE que = {0};
  TNODE *ptr;
  enqueue(&que, *rootp2);
  while (que.front != NULL){
    ptr = dequeue(&que);
    if (ptr->left){
      enqueue(&que, ptr->left);
    }
    if (ptr->right) {
      enqueue(&que, ptr->right);
    }
    RECORD record = ptr->data;
    insert_avl(rootp1, record.name, record.score);
  }
}

void merge_data(AVL *t1, AVL *t2) {
  merge_tree(&t1->root, &t2->root);
  // aggregate existing t1->stats and  t2->stats, and then update t1->stats 
  float count1 = (float) t1->stats.count;
  float count2 = (float) t2->stats.count;
  float count = count1 + count2;
  float mean1 = t1->stats.mean;
  float mean2 = t2->stats.mean;
  t1->stats.count = t1->stats.count + t2->stats.count;
  t1->stats.mean = (t1->stats.mean * (float)count1 + t2->stats.mean * (float)t2->stats.count) / (float)t1->stats.count;
  t1->stats.stddev = sqrtf((1/count)*(t1->stats.stddev*t1->stats.stddev*count1 + mean1*mean1*count1 + t2->stats.stddev*t2->stats.stddev*count2 + mean2*mean2*count2)-(t1->stats.mean*t1->stats.mean));

}

void clear_avl(AVL *avl) {
  TNODE *root = avl->root;
  clear_tree(&root);
  avl->root = NULL;
  avl->stats.count = 0;
  avl->stats.mean = 0;
  avl->stats.stddev = 0;
  avl->stats.median = 0;
}