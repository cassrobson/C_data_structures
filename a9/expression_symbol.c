/*
 -------------------------------------
 File:    expression_symbol.c
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
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression_symbol.h"

int get_priority(char op) {
  if (op == '/' || op == '*' || op == '%') 
    return 1;
  else if (op == '+' || op == '-')
    return 0;
  else 
    return -1;    
}
//auxiliary function to determin the type of char c
int aux(char c) {
    int result = 0;
    if (c >= '0' &&  c <= '9' ){result = 0;}
    else if (c == '/' || c == '*' || c == '%' || c == '+' || c == '-'){result = 1;}
    else if (c == '('){result = 2;}
    else if ( c == ')'){result = 3;}
    else {result = 4;}
    return result;
}

QUEUE infix_to_postfix_symbol(char *infixstr,  HASHTABLE *ht) {
    QUEUE queue = {0};
    STACK stack = {0};
    char *p = infixstr;
    int sign = 1;
    int num = 0;
    char symbol[20] = {0}; //the above are data structures to implement the algorithm


    while(*p){
        if (*p == '-' && (p == infixstr || *(p-1) == '(')){
            sign = -1;
        } else if (*p >= 'a' && *p <= 'z' || *p >= 'A' && *p <= 'Z'){ //this block processes symbols in expression
      char *sp = symbol;
      *sp = *p;
      while ((*(p+1) >= 'a' && *(p+1) <= 'z') || (*(p+1) >= 'A' && *(p+1) <= 'Z') ||
        (*(p+1) >= '0' && *(p+1) <= '9') ) {
        p++;
        sp++;
        *sp = *p;
      }
      *(sp+1) = '\0';


      HASHNODE *ptr = search(ht, symbol);
      num = ptr->value;
      enqueue(&queue, new_node(sign*num, 0));
      sign = 1;
    } else if(*p >= '0' && *p <= '9'){

      num = *p-'0'; while ((*(p+1) >= '0' && *(p+1) <= '9')) { num = num*10 + *(p+1)-'0'; p++; }
      enqueue(&queue, new_node(sign*num, 0));
      sign = 1;
    } else if(*p == '('){
      push(&stack, new_node(*p, 2));
    } else if(*p == ')'){
      NODE *node = pop(&stack);
      while(node->type != 2){
        if(node->type == 1){
          enqueue(&queue, node);
        }
        node = pop(&stack);
      }



    } else if(aux(*p) == 1){
      push(&stack, new_node(*p, 1));
    }
    p++;
  }

  while(stack.top){
    enqueue(&queue, pop(&stack));
  } 
  return queue;
}


int evaluate_infix_symbol(char *infixstr,  HASHTABLE *ht) {
    QUEUE q = {0};
    q = infix_to_postfix_symbol(infixstr, ht);
    return evaluate_postfix(q);
}


int evaluate_postfix(QUEUE queue) {
    NODE *ptr = queue.front;
	STACK stack = { 0 }; 
	int type = 0;
	while (ptr) {
		type = ptr->type;
		if (type == 0) { 
			push(&stack, new_node(ptr->data, 0));
		} else if (type == 1) { 
			NODE *n2 = pop(&stack);
			NODE *n1 = pop(&stack);
			int result;
			if (ptr->data == '+') {
				result = n1->data + n2->data;
			} else if (ptr->data == '%') {
				result = n1->data % n2->data;
			} else if (ptr->data == '/') {
				result = n1->data / n2->data;
			} else if (ptr->data == '-') {
				result = n1->data - n2->data;
			} else if (ptr->data == '*') {
				result = n1->data * n2->data;
			}
			push(&stack, new_node(result, 0));
		}
		ptr = ptr->next;
	}
	int final = stack.top->data;
	clean_stack(&stack);
	return final;
}

