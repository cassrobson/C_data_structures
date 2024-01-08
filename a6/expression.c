/*
 -------------------------------------
 File:    expression.c
 Project: cp264_a6
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-03-03
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

/*
 * auxiliary function
 */
int get_priority(char op) {
	if (op == '/' || op == '*' || op == '%')
		return 1;
	else if (op == '+' || op == '-')
		return 0;
	else
		return -1;
}

/*
 * auxiliary function
 */
int type(char c) {
	if (c >= '0' && c <= '9')
		return 0;
	else if (c == '/' || c == '*' || c == '%' || c == '+' || c == '-')
		return 1;
	else if (c == '(')
		return 2;
	else if (c == ')')
		return 3;
	else
		return 4;
}

QUEUE infix_to_postfix(char *infixstr) {
	char *ptr = infixstr;
	QUEUE queue = { 0 };
	STACK stack = { 0 }; 
	int positive = 1, num = 0;
	while (*ptr) {
		if (*ptr == '-' && (ptr == infixstr || *(ptr - 1) == '(')) {
			positive = -1;
		} else if (*ptr >= '0' && *ptr <= '9') {
			num = *ptr - '0';
			while ((*(ptr + 1) >= '0' && *(ptr + 1) <= '9')) {
				num = num * 10 + *(ptr + 1) - '0';
				ptr++;
			}
			enqueue(&queue, new_node(positive * num, 0));
			positive = 1;
		} else if (*ptr == '(') {
			push(&stack, new_node(*ptr, 2));

		} else if (*ptr == ')') {
			NODE *node = pop(&stack);
			while (node->type != 2) {
				enqueue(&queue, node);
				node = pop(&stack);
			}

		} else if (type(*ptr) == 1) {
			push(&stack, new_node(*ptr, 1));
		}
		ptr++;
	}
	while (stack.top) {
		enqueue(&queue, pop(&stack));
	}
	return queue;
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

int evaluate_infix(char *infixstr) {

	return evaluate_postfix(infix_to_postfix(infixstr));
}

