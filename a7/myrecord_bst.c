/*
 -------------------------------------
 File:    myrecord_bst.c
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
#include <string.h>
#include <math.h>
#include "queue_stack.h"
#include "bst.h"
#include "myrecord_bst.h"

void add_data(BST *bst, STATS *stats, char *name, float score) {
    if(search(bst->root, name) == NULL){
        insert(&(bst->root), name, score);
        int count = stats->count;
        float mean = stats->mean;
        float stddev = stats->stddev;
        stats->count = count + 1;
        stats->mean =  ((float)1/((float)stats->count+(float)1))*((float)stats->count*(float)mean + score);
        stats->stddev = sqrtf(((float)1/((float)stats->count+(float)1))*((float)stats->count*(stddev*stddev + mean*mean)+(score*score))-(stats->mean*stats->mean));
    }
}

void remove_data(BST *bst, STATS *stats, char *name) {
    TNODE *ptr = search(bst->root, name);
    if(ptr !=NULL){
        float score = ptr->data.score;
        delete(&(bst->root), name);
        int count = stats->count;
        float mean = stats->mean;
        float stddev = stats->stddev;
        stats->count = count - 1;
        stats->mean = ((float)1/(float)(stats->count))*((float)count*mean - score);
        stats->stddev = sqrtf(((float)1/(float)(stats->count))*((float)count*(stddev*stddev + mean*mean) - (score*score))-(stats->mean*stats->mean));
    }
}

