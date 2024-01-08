/*
 -------------------------------------
 File:    mysort.c
 Project: robs7000_a4
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-02-09
 -------------------------------------
 */
#include "mysort.h"

BOOLEAN is_sorted(float *a, int left, int right)
{
    BOOLEAN result = true;
    int i = left;
    while(result && i < right){
        if (*(a+i) > *(a+i+1)){
            result = false;
        }
        i++;
    }
    return result;
}

void select_sort(float *a, int left, int right)
{
    int i, j, k;
    for (i = 0; i < (right - left + 1); ++i){
        k = i;
        for (j = i + 1; j < (right - left + 1); ++j){
            if (*(a+j) < *(a+k)){
                k = j;
            }
        }
        if (i != k){
            int *p1, *p2;
            p1 = a+k;
            p2 = a+i;
            int temp = *p2;
            *p2 = *p1;
            *p1 = temp;
        }
    }
    
}

void quick_sort(float *a, int left, int right)
{
    int key,i,j,k;
    if( left < right ) {
        k = (left+right)/2;
        key = *(a+k); // use *(a+k) as the pivot
        // split a[left...right] that element at j is equal to key
        // elements from left to j-1 are less or equal to key
        // elements from j+1 to right are bigger than key
        int temp;
        i = left-1;
        j = right+1;
        int lessthan = 1;
        while(lessthan){
            do{
                i++;
            } while(*(a+i) < key);

            do{
                j--;
            } while(*(a+j) > key);

            if(i>= j){
                lessthan = 0;
            } else {
                temp = *(a+j);
                *(a+j) = *(a+i);
                *(a+i) = temp;
            }
        }

        quick_sort(a, left, j);
        quick_sort(a, j+1, right);
    

    }
    
}