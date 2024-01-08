/*
------------------------------------------------------------------------------------------
File:    fibonacci.h
Project: a2
Purpose: fibonacci iterative and recursive
         ===================================
Author:  Cassel Robson
ID:      210507000
Email:   robs7000@mylaurier.ca
Last updated: 2023-01-27
-------------------------------------
*/
#include <stdio.h>
#ifndef FIBONACCI_H
#define FIBONACCI_H

extern int *la;  // global pointer variable to hold lowest variable address

int recursive_fibonacci(int n) {
  if (&n < la) la = &n;
  if (n <=0) {
    return 0;
  }
  if (n <= 2){
    return 1;
  }
  else 
    return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);

  
}

int iterative_fibonacci(int n) 
{
  if (&n < la) la = &n;
    int f1 = 0;
    int f2 = 1;
    int temp = 0;
    for(int i = 0; i <= n; i++){
        if(i<=1){
            temp = i;
        } else {
            temp = f1 + f2;
            f1 = f2;
            f2 = temp;
        }
        
    }
    return temp;
}

#endif