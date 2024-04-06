#ifndef myLinkedList_h
#define myLinkedList_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define read "r"
#define write "w"
#define MAX_INPUT 3

struct node{
	double value;
	struct node *next;
};

struct node *insrt_in_ord_lst(struct node *list, struct node *new_node);
struct node *make_new_node(double a);

bool search_linked_list(double a, struct node *first);
void print_out(struct node *first, FILE *ARG2);
void clear_linked_list(struct node *first);
double pull_input(FILE *ARG1);

#endif /* myLinkedList_h */
