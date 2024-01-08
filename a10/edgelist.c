/*
 -------------------------------------
 File:    edgelist.c
 Project: cp264_a7
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-04-07
 -------------------------------------
 */ 

#include <stdio.h>
#include <stdlib.h> 
#include "edgelist.h"

EDGELIST *new_edgelist() {
    EDGELIST *edge = malloc(sizeof(EDGELIST));
    edge->size = 0;
    edge->start = NULL;
    edge->end = NULL;
    return edge;
}

void add_edge_end(EDGELIST *g, int from, int to, int weight) {
    EDGE *edge = (EDGE*) malloc(sizeof(EDGE));
    edge->from = from;
    edge->to = to;
    edge->weight = weight;
    edge->next = NULL;
    if (g->start == NULL){
        g->start = edge;

    } else {
        g->end->next = edge;

    }
    g->end = edge;
    g->size++;
}

void add_edge_start(EDGELIST *g, int from, int to, int weight) {
    EDGE *edge = (EDGE*) malloc(sizeof(EDGE));
    edge->from = from;
    edge->to = to;
    edge->weight = weight;
    edge->next = g->start;
    g->start = edge;
    if (g->size == 0){
        g->end = edge;

    }
    g->size++;
}

int weight_edgelist(EDGELIST *g) {
    EDGE *ptr = g->start;
    int w = 0;
    while (ptr){
        w += ptr->weight;
        ptr = ptr->next;
    }
    return w;
}

void clean_edgelist(EDGELIST **gp) {
    if (*gp == NULL){
        return;
    }
    EDGE *current = (*gp)->start;
    while (current != NULL){
        EDGE *currplus = current->next;
        free(current);
        current = currplus;
    }
    free(*gp);
    *gp = NULL;
}

void display_edgelist(EDGELIST *g) {
  if (g == NULL) return;
  printf("size:%d\n", g->size);
  printf("(from to weight):");
  EDGE *p = g->start;
  while (p) {
    printf("(%d %d %d) ", p->from, p->to, p->weight);
    p = p->next;
  }
}