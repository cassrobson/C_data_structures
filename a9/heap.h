/*
 -------------------------------------
 File:    heap.h
 Project: cp264_a7
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-03-12
 -------------------------------------
 */ 
#ifndef HEAP_H
#define HEAP_H
 
#define MIN_CAPACITY 4

typedef int KEYTYPE; 
typedef int DATA; 

typedef struct heap_node { // data element ds for binary heap
  KEYTYPE key;
  DATA data;
} HEAPNODE;

typedef struct heap {  
  unsigned int capacity; // the MAX length of array
  unsigned int size;     // the current heap size, i.e., heap node count
  HEAPNODE *hna;  // pointer pointing the heap node array
} HEAP;

HEAP *new_heap(int capacity);
void insert(HEAP *heap, HEAPNODE a);
HEAPNODE extract_min(HEAP *heap);
int change_key(HEAP *heap, int index, KEYTYPE new_key);
int find_data_index(HEAP *heap, DATA data);
void heap_sort(HEAPNODE *hna, int n);
int cmp(KEYTYPE a, KEYTYPE b);   
void heap_swap(HEAPNODE *a, HEAPNODE *b);
void make_heap(HEAPNODE *hna, int n, int i);
#endif 