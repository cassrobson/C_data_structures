/*
 -------------------------------------
 File:    heap.c
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
#include "heap.h"

int heap_up(HEAP *source, int a){
    HEAPNODE *ptr = source->hna;
    int i = a;
    int j = (i-1)/2;
    while (i!= 0){
        if(cmp((ptr+j)->key, (ptr+i)->key) == 1){
            heap_swap((ptr+j), (ptr+i));
            i = j;
            j = (i-1)/2;
        } else {
            break;
        }
    }
    return i;
}

int heap_down(HEAP *source, int a){
    HEAPNODE *ptr = source->hna;
    int i = a;
    int k = 2*i+1;
    int d = 2*i+2;
    int j;
    while (i < source->size){
        if (d>=source->size){
            if(k>=source->size){
                break;
            } else {
                j = k;
            }

        } else {
            j = (cmp((ptr+k)->key, (ptr+d)->key) == -1)?k:d;
        }
        if (cmp((ptr+j)->key, (ptr+i)->key) == -1){
            heap_swap((ptr+j), (ptr+i));
            i = j;
            k = 2*i+1;
            d = 2*i+2;
        } else {
            break;
        }
    }
    return i;
}

void heap_swap(HEAPNODE *a, HEAPNODE *b){
    HEAPNODE temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
HEAP *new_heap(int capacity)
{
    HEAP *h = (HEAP *) malloc(sizeof(HEAP));
    h->capacity = capacity;
    h->size = 0;
    h->hna = (HEAPNODE*) malloc(sizeof(HEAPNODE)*capacity);
    return h;
}

void insert(HEAP *heap, HEAPNODE new_node)
{
    if (heap->size == heap->capacity){
        heap->capacity = heap->capacity * 2;
        void *temp = realloc(heap->hna, sizeof(HEAPNODE) * heap->capacity);
        if (temp){
            heap->hna = temp;

        } else {
            temp = malloc(sizeof(HEAPNODE) * heap->capacity);
            if (temp){
                memcpy(temp, heap->hna, sizeof(HEAPNODE) * heap->size);
                free(heap->hna);
                heap->hna = temp;
            }
        }
    }
    HEAPNODE *ptr = heap->hna;
    *(ptr+heap->size) = new_node;
    heap->size++;
    heap_up(heap, heap->size-1);
    return;
}

HEAPNODE extract_min(HEAP *heap)
{
    HEAPNODE *ptr = heap->hna;
    heap_swap(ptr, ptr+heap->size-1);
    HEAPNODE result = *(ptr+heap->size-1);
    heap->size--;
    heap_down(heap, 0);

    if (heap->size <= heap->capacity/4){
        heap->capacity/=2;
        void *temp = realloc(heap->hna, sizeof(HEAPNODE) * heap->capacity);
        if (temp){
            heap->hna = temp;
        } else {
            temp = malloc(sizeof(HEAPNODE) * heap->capacity);
            if (temp) {
                memcpy(temp, heap->hna, sizeof(HEAPNODE) * heap->size);
                free(heap->hna);
                heap->hna = temp;
            }
        }
    }
    return result;
}

int change_key(HEAP *heap, int index, KEYTYPE new_key)
{
    HEAPNODE *ptr = heap->hna;
    KEYTYPE old = (ptr+index)->key;
    (ptr+index)->key = new_key;

    int i;
    if(index == 0){
        i = heap_down(heap, 0);
    } else if (index == heap->size-1){
        i = heap_up(heap, heap->size-1);
    } else {
        if(cmp(old, new_key) == -1){
            i = heap_down(heap, index);
        } else if (cmp(old, new_key) == 1){
            i = heap_up(heap, index);
        } else {
            i = index;
        }
    }
    return i;

}

int find_data_index(HEAP *heap, DATA data) {
    HEAPNODE *ptr = heap->hna;
    int i = 0;

    while (i < heap->size){
        if((ptr+i)->data == data){
            break;
        } else {
            i++;
        }
    }
    return i;
}
void make_heap(HEAPNODE *hna, int n, int i){
    int min = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if (l<n && cmp(hna[l].key, hna[min].key) < 0){
        min = l;
    }
    if (r < n && cmp(hna[r].key, hna[min].key) < 0){
        min = r;
    }
    if (min != i){
        heap_swap(&hna[i], &hna[min]);
        make_heap(hna, n, min);
    }
}

void heap_sort(HEAPNODE *hna, int n) {
    for (int i = n/2 - 1; i >= 0; i--){
        make_heap(hna, n, i);
    }
    for (int j = n-1; j > 0; j--){
        heap_swap(&hna[0], &hna[j]);
        make_heap(hna, j, 0);
    }
}

int cmp(KEYTYPE a, KEYTYPE b) {
  int r = 0;
  if (a < b) r = -1;
  else if (a > b) r = 1;
  return r;
}