/*
 -------------------------------------
 File:    graph.c
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
#include "queue_stack.h" 
#include "graph.h"

GRAPH *new_graph(int order) {
	GRAPH *graph = malloc(sizeof(GRAPH));
	graph->order =order;
	graph->size = 0;
	graph->nodes = malloc(order *sizeof(GNODE*));
	for(int i = 0; i < order; i++){
		graph->nodes[i] = malloc(sizeof(GNODE));
		graph->nodes[i]->nid = i;
		graph->nodes[i]->neighbor = NULL;
	}
	return graph;
}

void add_edge(GRAPH *g, int from, int to, int weight) {
	if (from < 0 || from >= g->order || to < 0 || to >= g->order) {
		printf("Error: node index out of range\n");
	    return;
	   }
	ADJNODE *newadjusted = (ADJNODE*) malloc(sizeof(ADJNODE));
	newadjusted->nid = to;
	newadjusted->weight = weight;
	newadjusted->next = NULL;
	ADJNODE *currentadjusted = g->nodes[from]->neighbor;
	if (currentadjusted == NULL) {g->nodes[from]->neighbor = newadjusted;} 
  else {
		while (currentadjusted->next != NULL) {
			currentadjusted = currentadjusted->next;
	     }
	        currentadjusted->next = newadjusted;
	}
	g->size++;
}

int get_weight(GRAPH *g, int from, int to) {
	 if (from < 0 || from >= g->order || to < 0 || to >= g->order) {
	        printf("Error: node index out of range\n");
	        return INFINITY;
	    }
	    ADJNODE *currentadjusted = g->nodes[from]->neighbor;
	    while (currentadjusted != NULL) {
	        if (currentadjusted->nid == to) {return currentadjusted->weight;}
	        currentadjusted = currentadjusted->next;
	    }
	    return INFINITY;
}

void clean_graph(GRAPH **gp) {
	if (*gp == NULL) {return;}
	    GRAPH *graph = *gp;
	    for (int i = 0; i < graph->order; i++) {
	        ADJNODE *currentadjusted = graph->nodes[i]->neighbor;
	        while (currentadjusted != NULL) {
	            ADJNODE *next_adjnode = currentadjusted->next;
	            free(currentadjusted);
	            currentadjusted = next_adjnode;
	        }
	        free(graph->nodes[i]);
	    }
	    free(graph->nodes);
	    free(graph);
	    *gp = NULL;
}

void display_bforder(GRAPH *g, int start) {
	if (g == NULL) {return;}
	int n = g->order;
  int visited[n];
	for (int i = 0; i < n; i++){ visited[i] = 0;}

  
	QUEUE q = {0};
	GNODE *gnp = NULL;
	ADJNODE *anp = NULL;
	enqueue(&q, g->nodes[start]);
	visited[start] = 1;
	while (q.front) {
		gnp = (GNODE*) dequeue(&q);
		printf("%d ", gnp->nid);
		anp = gnp->neighbor;
		while (anp) {
			if (!visited[anp->nid]) {visited[anp->nid] = 1; enqueue(&q, g->nodes[anp->nid]);}
			anp = anp->next;
		}
	}
	clean_queue(&q);
	}

void display_dforder(GRAPH *g, int start) {
	if (g == NULL) return;
	  int n = g->order;
    int visited[n];
	  for (int i = 0; i < n; i++){ visited[i] = 0;}


	  STACK s = {NULL};
	  GNODE *gnp = NULL;
	  ADJNODE *anp = NULL;
	  push(&s, g->nodes[start]);
	  visited[start] = 1;
	  while (s.top) {
	    gnp = (GNODE*) pop(&s);
	    printf("%d ", gnp->nid);
	    anp = gnp->neighbor;
	    while (anp) {
	      if (!visited[anp->nid]) {push(&s, g->nodes[anp->nid]); visited[anp->nid] = 1;}
	      anp = anp->next;
	    }
	  }
	  clean_stack(&s);
}


void display_graph(GRAPH *g) {
  if (g == NULL) return;
  printf("order:%d\n", g->order);
  printf("size:%d\n", g->size);
  printf("from:(to weight)");
  int i;
  ADJNODE *ptr;
  for (i = 0; i < g->order; i++) {
    printf("\n%d:", g->nodes[i]->nid);
    ptr = g->nodes[i]->neighbor;
    while (ptr != NULL) {
      printf("(%d %d) ", ptr->nid, ptr->weight);
      ptr = ptr->next;
    }
  }
}