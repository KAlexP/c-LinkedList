#include "LinkedList.h"

/****************************************************************************
 *	Function Title: insrt_in_ord_lst()
 *
 *	Input: list, which points to the front of the linked list
 *		   new_node, which points to the new node that is being added
 *	Output:a Node pointer, which points to the begining of the linked
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

Node *insrt_in_ord_lst(Node *first, Node *new_node, CompareFunc compare){
	//Begin
	Node *cur = first, *prev = NULL;
		//declare variables
	if(first == NULL || compare(&cur->value,&new_node->value) > 0){
		//if the linked llist is empty or new_node should start
		new_node->next = first;
			//set new_node to point to list
		return new_node;
			//return the pointer to new node
	}	//endif
  while(cur!= NULL && compare(&cur->value,&new_node->value) < 0){
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
 *	Output:a Node pointer, which points to the new node
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

Node *make_new_node(double a){				// Bgin
	Node *temp;													//declare variables
	temp = malloc(sizeof(Node));		//allocate memory for the new node
	if(temp == NULL){														//if memory allocate failed
		printf("Malloc Error in make_new_node");		//print error
		exit(EXIT_FAILURE);													//exit program
	}																						//endif
	temp->next = NULL;													//make the new node point to NULL
	temp->value = a;														//save int value into node
	return temp;																//return the pointer to the new node
}																						//End

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
 *				 endif
 *			endloop
 *			return flag
 *		End
 ***************************************************************************/

bool search_linked_list(double a, Node *first, CompareFunc compare){//	Begin
	bool flag = false;																	//		declare variables
	Node *temp = first;													
	for(;temp != NULL; temp = temp->next){							//		loop linked list
		if (compare(&a,&temp->value) == 0){								//			if number found
      flag = true;																		//				flag is true
			break;																					//				break from loop
		}																									//			endif
	}																										//		endloop
	return flag;																				//		return flag
}																											//	End

/****************************************************************************
 *	Function Title: print_out()
 *	Summary: This function just prints out the contents of the linked list. 
 *					 In particular this includes the square root, cube root and fourth 
 *					 root as well. The behavior can be modified. 
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

void print_out(Node *first, FILE *output){
	//Begin
	Node *temp;
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

void clear_linked_list(Node *first){// Begin
	Node *temp, *p;									 //		declare variables
	for (p = first; p != NULL; p = p->next){ //		loop through whole linked list
		temp = p;															 //			set temp to p
		p = p->next;													 //			set p to next node
		free(temp);														 //			free current node memory
		if(p == NULL){												 //			if p is NULL
			break;															 //				leave loop
		}																			 //			endif
	}																				 //		endloop
}																					//	End

/*******************************************************************************
 *
 * The Below Functions are important for the linked List. They need passed to 
 * the search_linked_list, and insrt_in_ord_lst functions for them to work.
 *
 ******************************************************************************/


/*******************************************************************************
* Function Title: compare_node
* Summary: This function compares two nodes. Needed for insrt_in_ord_lst.
*
* Inputs:
* 	Node* left: the left side comparison
* 	Node* right: the right side of the comparison
* Outputs:
*
********************************************************************************
* Pseudocode
*   Begin
*   	
*   End
*******************************************************************************/
int compare_node(const void *a, const void *b){ // Begin
	double da = *(const double*)a;
  double db = *(const double*)b; 
  
  if(da>db) return 1;
  else if(da<db) return -1;
  else return 0;
}																					 // End
