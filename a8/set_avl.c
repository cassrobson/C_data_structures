/*
 -------------------------------------
 File:    set_avl.c
 Project: cp264_a7
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-03-12
 -------------------------------------
 */
 
 
 #include "avl.h"
#include "set_avl.h"
#include <string.h>
#include <stdio.h>

int size(SET *s) {
    return s->size;
}

int contains_element(SET *s, char *e){
    TNODE *node = search_avl(s->root, e);
    if (node == NULL) return 0;
    return 1;
}

void add_element(SET *s, char *e)
{
    if (!contains_element(s, e)){
        insert_avl(&s->root, e, s->size);
        s->size++;
    }
}

void remove_element(SET *s, char *e)
{
    if (contains_element(s, e)){
    delete_avl(&s->root, e);
    s->size--;
} 
}

void clear_set(SET *s){
    s->root = NULL;
    s->size = 0;

}   
