/*
------------------------------------------------------------------------------------------
File:    polynomial.h
Project: a2
Purpose: polynomial functions
         ===================================
Author:  Cassel Robson
ID:      210507000
Email:   robs7000@mylaurier.ca
Last updated: 2023-01-27
-------------------------------------
*/
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
 
#include<stdio.h>
#include<math.h>

#define EPSILON 1e-6

float horner(float p[], int n, float x)
{
    float r = 0;
    for (int i = 0; i < n; i++){
        r = r * x + p[i];

    }
    return r;
}

// compute the derivative of polynomial p[], and output to d[]
void derivative(float p[], int n, float d[]){
    for (int i = 0; i < n -1; i++){
        d[i] = (n - (i + 1)) * p[i];
    }
}


// Use Newton's method to find and return a root of polynomial of p[] 
float newton(float p[], int n, float x0)
{
    float x = x0, px, d[n-1];
    derivative(p, n, d);
    do {
        x0 = x;
        px = horner(p, n, x);
        x -= px / horner(d, n-1, x);
    } while (fabs(x - x0) > EPSILON || fabs(px) > EPSILON);
    return x0;
}

#endif