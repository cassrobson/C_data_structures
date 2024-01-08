/*
 -------------------------------------
 File:    mystring.c
 Project: cp264_a3
 file description
 - string functinos
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-02-03
 -------------------------------------
 */
#include <stdio.h>
#include "mystring.h"


int str_length(char *s) {
    int counter = 0;
    char *p = s;
    if (s == NULL) return -1;
    else {
        while (*p) {
            counter++;
            p++;
        }
    }
    return counter;
 
 
}

int word_count(char *s) {
    int counter = 0;
    char *p;
    if (s == NULL ) return -1;
    else {
        p = s;
        while (*p) {
            if (*p != 32 && *(p-1) == 32){
                counter++;
            }
            p++;
        }
    }

    return counter;

}

void lower_case(char *s) {
int len = str_length(s);
char *p = s;
for (int i = 0; i < len; i++){
    if (*p >= 'A' && *p <= 'Z' ){
        *p += 32;
    }
        p++;
}
}

void str_trim(char *s) {
    char *p=s, *dp=s;
    while (*p) {
        if (*p != ' ' || (p > s && *(p-1) != ' ' )) { // pattern
            *dp = *p;
            dp++;
        }
        p++; // next
    }
    if(*(dp-1) == ' '){
        *(dp-1) = '\0';
    } else {
        *dp = '\0';
    }
}


