/*
 -------------------------------------
 File:    queue.c
 Project: cp264_a6
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-03-03
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
	if (qp->front == NULL) {
		qp->front = np;
		qp->rear = np;
	} else {
		qp->rear->next = np;
		qp->rear = np;
		qp->rear->next = NULL;
	}
	qp->length++;
}

/*
 * dequeue and return the pointer of the removed NOPE, maintain length property.
 * do not free the removed node in the function.
 */
NODE* dequeue(QUEUE *qp) {
	NODE *nd = qp->front;
	if (nd != NULL) {
		if (qp->length == 1) {
			qp->front = NULL;
			qp->rear = NULL;
		} else {
			qp->front = qp->front->next;
		}
		qp->length--;
	}

	return nd;

}

/*
 * delete and free all nodes of the queue, and reset the front, rear, and length.
 */
void clean_queue(QUEUE *qp) {
// call clean() function in common.h
// set qp's front, rare to NULL and length to 0
	NODE *temp;
    NODE *ptr = qp->front;
	while (ptr != NULL) {
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
	qp->front = NULL;
	qp->rear = NULL;
	qp->length = 0;
}