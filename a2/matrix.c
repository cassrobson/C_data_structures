/*
------------------------------------------------------------------------------------------
File:    matrix.c
Project: a2
Purpose: matrix.c
         ===================================
Author:  Cassel Robson
ID:      210507000
Email:   robs7000@mylaurier.ca
Last updated: 2023-01-27
-------------------------------------
*/
#include<stdio.h>
#include "matrix.h"


float vsum(float *v, int n) {
 int sum = 0;
 for (int i = 0; i < n; i++){
    sum += *(v+i);
 }
 return sum;
}

float msum(float *m, int n) {
 int sum = 0;
 for (int i = 0; i < n*n; i++){
    sum += *(m + i);
 }
 return sum;
 }


void multiply_vector(float *m, float *vin, float *vout, int n) {
 int sum;
 for (int i = 0; i < n; i++){
    sum = 0;
    for (int j =0 ; j < n; j++){
        sum += *(m + i*n + j) * *(vin + j);
    }
    *(vout + i) = sum;
 }
}

void transpose_matrix(float *m1, float *m2, int n) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            *(m2 + j * n + i) = *(m1 + i * n + j);
        }
    }
}

void multiply_matrix(float *m1, float *m2, float *m3, int n) {
int sum;
for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
        sum = 0;
        for (int k = 0; k < n; k++){
            sum += *(m1 + i*n + k) * *(m2 + k*n + j);
        }
        *(m3 + i * n + j) = sum;
    }
}
}