/*
 -------------------------------------
 File:    bigint.h
 Project: cp264_a5
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-02-17
 -------------------------------------
 */ 
 
#ifndef BIGINT_H
#define BIGINT_H
#include "dllist.h"

typedef DLLIST BIGINT;
BIGINT bigint(char *digitstr);
BIGINT add(BIGINT oprand1, BIGINT oprand2);
BIGINT Fibonacci(int n);

#endif