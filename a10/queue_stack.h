/*--------------------------------------------------
Project: cp264-a7q1
File:    queue_stack.h
Description: header of queue and stack data structures for record app
Author:  HBF
Version: 2023-03-02
--------------------------------------------------
*/

#ifndef QUEUE_STACK_H
#define QUEUE_STACK_H

typedef struct node {
  void *data;  // pointing to any data object
  struct node *next;
} NODE;

typedef struct queue {
  NODE *front, *rear;
} QUEUE;

void enqueue(QUEUE *qp, void *data);
void *dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

typedef struct stack {
  NODE *top;
} STACK;

void push(STACK *sp, void *data);
void *pop(STACK *sp);
void clean_stack(STACK *sp);

#endif