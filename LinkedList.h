#ifndef myLinkedList_h
#define myLinkedList_h

// Libraries included
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <complex.h>

#define read "r"
#define write "w"

// Define the Node
typedef struct Node{
	void* value;
	struct Node *next;
} Node;

// Define function pointer typedefs
typedef int (*CompareFunc)(const void *a, const void *b);

// Main function previews
Node *insrt_in_ord_lst(Node *list, Node *new_node, CompareFunc compare);
Node *insrt_in_list(Node *first, Node *new_node);
Node *make_new_node(void *value);
bool search_linked_list(void *value, Node *first, CompareFunc compare);
void clear_linked_list(Node *first);
int length(Node *first);

// Should be customized for your specific data type
void print_out(Node *first, FILE *ARG2);

// Comparison functions definitions [CompareFunc]
int compare_char(const void *left, const void *right);
int compare_int(const void *left, const void *right);
int compare_float(const void *left, const void *right);
int compare_double(const void *left, const void *right);
int compare_string(const void *left, const void *right);
int compare_complex(const void *left, const void *right);

#endif /* myLinkedList_h */
