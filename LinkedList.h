#ifndef myLinkedList_h
#define myLinkedList_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <complex.h>

#define read "r"
#define write "w"

typedef struct Node{
	void* value;
	struct Node *next;
} Node;

typedef int (*CompareFunc)(const void *a, const void *b);
typedef void* (*ParseFunc)(const char *line);

Node *insrt_in_ord_lst(Node *list, Node *new_node, CompareFunc compare);
Node *insrt_in_list(Node *first, Node *new_node);
Node *make_new_node(void *value);

bool search_linked_list(void *value, Node *first, CompareFunc compare);
void print_out(Node *first, FILE *ARG2);
void clear_linked_list(Node *first);
int compare_char(const void *left, const void *right);
int compare_int(const void *left, const void *right);
int compare_float(const void *left, const void *right);
int compare_double(const void *left, const void *right);
int compare_string(const void *left, const void *right);

#endif /* myLinkedList_h */
