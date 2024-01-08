/*
 -------------------------------------
 File:    dllist.c
 Project: cp264_a5
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-02-17
 -------------------------------------
 */ 
 
#include <stdio.h>
#include <stdlib.h> 
#include "dllist.h"

NODE* new_node(char data) {

	NODE *np = (NODE*) malloc(sizeof(NODE));

	np->data = data;
	np->next = NULL;
	np->prev = NULL;

	return np;
}

void clean(DLLIST *dllistp) {

	NODE *temp, *p = dllistp->start;
	while (p != NULL) {
		temp = p;
		p = p->next;
		free(temp);
	}
	dllistp->start = NULL;
	dllistp->length = 0;
}

void insert_start(DLLIST *dllistp, NODE *np) {
    NODE *p = dllistp->start;
	if (p == NULL) {
		np->prev = NULL;
		np->next = NULL;
		dllistp->start = np;
		dllistp->end = np;
	} else {
		np->prev = NULL;
		np->next = p;
		dllistp->start->prev = np;
		dllistp->start = np;
	}
	dllistp->length++;
}

void insert_end(DLLIST *dllistp, NODE *np) {
    NODE *p = dllistp->start;
	if (p == NULL) {
		np->prev = NULL;
		np->next = NULL;
		dllistp->start = np;
		dllistp->end = np;
	} else {
		np->prev = p;
		np->next = NULL;
		dllistp->end->next = np;
		dllistp->end = np;
	}
	dllistp->length++;
}

void delete_start(DLLIST *dllistp) {
    NODE *p = dllistp->start;
	if (p != NULL) {
		if (dllistp->length == 1) {
			dllistp->start = NULL;
			dllistp->end = NULL;
		} else {
			NODE *temp = dllistp->start->next;
			dllistp->start->prev = dllistp->start;
			dllistp->start = temp;
			dllistp->start->prev = NULL;
		}
		dllistp->length--;
	}
}

void delete_end(DLLIST *dllistp) {
    NODE *p = dllistp->start;
	if (p != NULL) {
		if (dllistp->length == 1) {
			dllistp->start = NULL;
			dllistp->end = NULL;
		} else {
			NODE *temp = dllistp->end->prev;
			dllistp->end->prev = dllistp->end;
			dllistp->end = temp;
			dllistp->end->next = NULL;
		}
		dllistp->length--;
	}
}

