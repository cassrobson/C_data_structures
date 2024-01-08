/*
 -------------------------------------
 File:    bst.c
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
#include "bst.h"

// you can add auxiliary function for the insert and delete operations

TNODE *new_node(char *name, float score) {
    TNODE *node = (TNODE*) malloc(sizeof(TNODE));
	RECORD record = {0};
	strcpy(record.name, name);
	record.score = score;
	node->data = record;
	node->left = NULL;
	node->right = NULL;
	return node;
}



void clean_tree(TNODE **rootp) {
    TNODE *root = *rootp;
    if (root != NULL) {
        if (root->left != NULL)
            clean_tree(&root->left);
        if (root->right != NULL)
            clean_tree(&root->right);
        free(root);
    }
    *rootp = NULL;
}

TNODE *search(TNODE *root, char *name) {
    TNODE *curr = root;
    int found = 0;
    while(!found && curr){
        int compare = strcmp(curr->data.name, name);
        if (compare == 0){
            found = 1;
        } else if (compare > 0) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return curr;
}

void insert(TNODE **rootp, char *name, float score) {
    TNODE *nodepointer = new_node(name, score);
    if (*rootp == NULL){
        *rootp = nodepointer;
    } else {
        int compare = strcmp(nodepointer->data.name, (*rootp)->data.name);
        if (compare != 0){
            if (compare < 0){
                insert(&(*rootp)->left, name, score);
            } else if (compare > 0){
                insert(&(*rootp)->right, name, score);
            }
        }
    }
}

void delete(TNODE **rootp, char *name) {

	TNODE *curr = *rootp, *highernode;
	TNODE **prev = NULL;
	int isfound = 0;
	if (curr == NULL)
		return;
	while (curr != NULL && !isfound) {
		if (strcmp(curr->data.name, name) == 0) {
			if (curr->left == NULL && curr->right == NULL) {
				free(curr);
				*prev = NULL;
			} else if (curr->left != NULL && curr->right == NULL) {
				highernode = curr->left;
				*prev = highernode;
				free(curr);
			} else if (curr->left == NULL && curr->right != NULL) {
				highernode = curr->right;
				*prev = highernode;
				free(curr);
			} else if (curr->left != NULL && curr->right != NULL) {
				highernode = extract_smallest_node(&curr->right);
				highernode->left = curr->left;
				highernode->right = curr->right;
				*prev = highernode;
				free(curr);
			}
			isfound = 1;
		} else {
			if (strcmp(curr->data.name, name) < 0) {
				prev = &curr->right;
				curr = curr->right;
			} else {
				prev = &curr->left;
				curr = curr->left;
			}
		}
	}
}

//axuiliary function for delete
TNODE* extract_smallest_node(TNODE **root){
    TNODE *ptr = *root;
    if (ptr == NULL) {return NULL;}
    else if (ptr->left == NULL){
        *root = ptr->right;
        ptr->left = NULL;
        ptr->right = NULL;
        return ptr;
    } else {
        return extract_smallest_node(&ptr->left);
    }
}


