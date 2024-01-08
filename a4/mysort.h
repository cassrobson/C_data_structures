/*
 -------------------------------------
 File:    mysort.h
 Project: robs7000_a4
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-02-09
 -------------------------------------
 */

#ifndef MYSORT_H
#define MYSORT_H 

typedef enum {false, true} BOOLEAN;
BOOLEAN is_sorted(float *a, int left, int right);
void select_sort(float *a, int left, int right);
void quick_sort(float *a, int left, int right);

#endif