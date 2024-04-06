#include "myLinkedList.h"

/****************************************************************************
 *	Function Title: insrt_in_ord_lst()
 *
 *	Input: list, which points to the front of the linked list
 *		   new_node, which points to the new node that is being added
 *	Output:a struct node pointer, which points to the begining of the linked
 *	 	   list.
 ****************************************************************************
 *	Pseudocode:
 *		Begin
 *			declare variables
 *			if the linked list is empty or new_node should start
 *				set new_node to point to list
 *				return the pointer to new node
 *			endif
 *			loop while * is not NULL and the current value is < new value
 *				advance temporary pointers down the linked list
 *			endloop
 *			insert node into linked list
 *			return the pointer to list
 *		End
 ***************************************************************************/

struct node *insrt_in_ord_lst(struct node *first, struct node *new_node){
	//Begin
	struct node *cur = first, *prev = NULL;
		//declare variables
	if(first == NULL || cur->value > new_node->value){
		//if the linked llist is empty or new_node should start
		new_node->next = first;
			//set new_node to point to list
		return new_node;
			//return the pointer to new node
	}	//endif
	while(cur != NULL && cur->value < new_node->value){
		//loop while * is not NULL and the current value is < new value
		prev = cur;
		cur = cur->next;
			//advance the temporary pointers down the linked list
	}	//endloop
	prev->next = new_node;
	new_node->next = cur;
		//insert node into linked list
	return first;
		//return the pointer to list
}	//End

/****************************************************************************
 *	Function Title: make_new_node()
 *
 *	Input: a, which is the integer being stored in the new node
 *	Output:a struct node pointer, which points to the new node
 ****************************************************************************
 *	Pseudocode:
 *		Begin
 *			declare variables
 *			allocate memory for the new node
 *			if memory allocate failed
 *				print error
 *				exit program
 *			endif
 *			make the new node point to NULL
 *			save int value into node
 *			return the pointer to the new node
 *		End
 ***************************************************************************/

struct node *make_new_node(double a){
	//Begin
	struct node *temp;
		//declare variables
	temp = malloc(sizeof(struct node));
		//allocate memory for the new node
	if(temp == NULL){
		//if memory allocate failed
		printf("Malloc Error in make_new_node");
			//print error
		exit(EXIT_FAILURE);
			//exit program
	}	//endif
	temp->next = NULL;
		//make the new node point to NULL
	temp->value = a;
		//save int value into node
	return temp;
		//return the pointer to the new node
}	//End

/****************************************************************************
 *	Function Title: search_linked_list()
 *
 *	Input: first, which points to the front of the linked list
 *		   int a, which is the number being searched for
 *	Output:flag, which states if the number was found or not
 ****************************************************************************
 *	Pseudocode:
 *		Begin
 *			declare variables
 *			loop through the whole linked list
 *				 if number for comparison is found
 *				 	flag is true
 *				 	break from loop
 *				 else if number is not found
 *				 	flag is false
 *				 endif
 *			endloop
 *			return flag
 *		End
 ***************************************************************************/

bool search_linked_list(double a, struct node *first){
	//Begin
	bool flag = false;
	struct node *temp = first;
		//declare variables
	for(;temp != NULL; temp = temp->next){
		//loop through the whole linked list
		if (a == temp->value){
			//if number for comparison is found
			flag = true;
				//flag is true
			break;
				//break from loop
		} else if (a != temp->value){
			//else if number is not found
			flag = false;
				//flag is false
		}	//endif
	}	//endloop
	return flag;
		//return flag
}	//End

/****************************************************************************
 *	Function Title: print_out()
 *
 *	Input: first, which points to the front of the linked list
 *		   ARG2 which points to the document being printed to
 *	Output:none
 ****************************************************************************
 *	Pseudocode:
 *		Begin
 *			declare variables
 *			loop through linked list
 *				find fourth root
 *				print table of value sqrt cbrt and fourth root
 *			endloop
 *		End
 ***************************************************************************/

void print_out(struct node *first, FILE *output){
	//Begin
	struct node *temp;
	double fourth_root;
		//declare variables
	for(temp = first;temp != NULL; temp = temp->next){
		//loop through linked list
		fourth_root = sqrt(sqrt(temp->value));
			//find fourth root
		fprintf(output,"%.0f\t%.3f\t",temp->value,sqrt(temp->value));
		fprintf(output,"%.3f\t%.3f\n",cbrt(temp->value), fourth_root);
			//print table of value sqrt cbrt and fourth root
	}	//endloop
}	//End

/****************************************************************************
 *	Function Title: clear_linked_list()
 *
 *	Input:none
 *	Output:none
 ****************************************************************************
 *	Pseudocode:
 *		Begin
 *			declare variables
 *			loop through whole linked list
 *				set temp to p
 *				set p to next node
 *				free current node memory
 *				if p is NULL
 *					leave loop
 *				endif
 *			endloop
 *		End
 ***************************************************************************/

void clear_linked_list(struct node *first){
	//Begin
	struct node *temp, *p;
		//declare variables
	for (p = first; p != NULL; p = p->next){
		//loop through whole linked list
		temp = p;
			//set temp to p
		p = p->next;
			//set p to next node
		free(temp);
			//free current node memory
		if(p == NULL){
			//if p is NULL
			break;
				//leave loop
		}	//endif
	}	//endloop
}	//End

/****************************************************************************
 *	Function Title: pull_input()
 *
 *	Input: File pointer that points to document that has input
 *	Output: double that is the number stored on a line
 ****************************************************************************
 *	Pseudocode:
 *		Begin
 *			declare variables
 *			read and save input
 *			if number was saved
 *				return value of saved input
 *			endif
 *			if end of file reached
 *				return -1;
 *			endif
 *			print error if this is ever reached
 *			return -1 so the compiler doesn't complain
 *		End
 ***************************************************************************/

double pull_input(FILE *input){
	double num;
	int flag = fscanf(input,"%lf",&num);
		//declare variables
		//read and save input
	if(flag == 1){
		//if number was saved
		return num;
			//return value of saved input
	}	//endif
	if(feof(input)){
		//if end of file reached
		return -1;
			//return -1;
	}	//endif
	printf("Error loop fail: pull_input()");
		//print error if this is ever reached
	return -1;
		//return -1 so the compiler doesn't complain
}
