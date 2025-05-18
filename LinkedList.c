#include "LinkedList.h"
#include <stdlib.h>

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
	Node *cur = first, *prev = NULL;
	if(first == NULL || compare(cur->value,new_node->value) > 0){
		new_node->next = first;
		return new_node;
	}
  while(cur!= NULL && compare(cur->value,new_node->value) < 0){
		prev = cur;
		cur = cur->next;
	}
	prev->next = new_node;
	new_node->next = cur;
	return first;
}

/*******************************************************************************
* Function Title: insrt_in_list
* Summary: this inserts nodes into a linked list without sorting
*
* Inputs:
* 	Node *first: the root node or first node
* 	Node *new_node: the node to be inserted
* 	CompareFunc: A function pointer pointing to a compare function 
* 								--see details below--
* Outputs: n/a 
********************************************************************************
* Pseudocode
*   Begin
*			find end of list 
*			put new_node at the end of the list
*   End
*******************************************************************************/
Node *insrt_in_list(Node *first, Node *new_node){
  Node *cur = first, *prev = NULL;
  if(first == NULL){
    return new_node;
  } 
  while(cur != NULL){
    prev = cur;
   	cur = cur->next;
  }
  prev->next = new_node;
  new_node->next = cur;
  return first;
}

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
Node *make_new_node(void *value){				// Bgin
	Node *temp;													//declare variables
	temp = malloc(sizeof(Node));		//allocate memory for the new node
	if(temp == NULL){														//if memory allocate failed
		printf("Malloc Error in make_new_node");		//print error
		exit(EXIT_FAILURE);													//exit program
	}																						//endif
	temp->next = NULL;													//make the new node point to NULL
	temp->value = value;														//save int value into node
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
bool search_linked_list(void *value, Node *first, CompareFunc compare){//	Begin
	bool flag = false;																	//		declare variables
	Node *temp = first;													
	for(;temp != NULL; temp = temp->next){							//		loop linked list
		if (compare(value,temp->value) == 0){								//			if number found
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
	Node *temp;
	for(temp = first;temp != NULL; temp = temp->next){
    // Perform Print of your data type here
    printf("data: %15d\tnext: %p\n",*(int *)temp->value,temp->next);
	}
}	

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
    free(temp->value);										 //			free current node value ptr
		free(temp);														 //			free current node memory
		if(p == NULL){												 //			if p is NULL
			break;															 //				leave loop
		}																			 //			endif
	}																				 //		endloop
}																					//	End


////////////////////////////////////////////////////////////////////////////////
//
// The Below Functions are important for the linked List. They need passed to 
// the search_linked_list, and insrt_in_ord_lst functions for them to work.
// 
///////////////////////////////////////////////////////////////////////////////

/*******************************************************************************
* Function Title: compare_int
* Summary: makes comparison for int
*
* Inputs:	
* 	const void* left: the left operand of comparison
* 	const void* right: the right operand of comparison
* Outputs:
* 	int: the result of the comparison
*******************************************************************************/
int compare_int(const void* left, const void* right){
	return *(const int*)left - *(const int*)right;
}

/*******************************************************************************
* Function Title: compare_char
* Summary: this correctly compares characters
*
* Inputs:	
* 	const void* left: the left operand of comparison
* 	const void* right: the right operand of comparison
* Outputs:
* 	int: the result of the comparison
********************************************************************************
* Pseudocode
*   Begin
*			set variables
*			if left > right 
*				return 1
*			else if left < right
*				return -1
*			else 
*				return 0;
*   End
*******************************************************************************/
int compare_char(const void* left, const void* right){
	const char c_left = *(const char*) left;
  const char c_right = *(const char*) right;
 	if(c_left > c_right){
		return 1;
  } else if (c_left < c_right){
		return -1;
  }
	return 0;
}

/*******************************************************************************
* Function Title: compare_float
* Summary: This function compares two nodes. Needed for insrt_in_ord_lst.
*
* Inputs:
* 	Node* left: the left side comparison
* 	Node* right: the right side of the comparison
* Outputs:
*		int: the results of the comparison
********************************************************************************
* Pseudocode
*   Begin
*   	assign variables 
*   	perform comparison 
*   	return results
*   End
*******************************************************************************/
int compare_float(const void *left, const void *right){
	float da = *(const float*)left;
  float db = *(const float*)right; 
  if(da>db) return 1;
  else if(da<db) return -1;
  else return 0;
}

/*******************************************************************************
* Function Title: compare_float
* Summary: This function compares two nodes. Needed for insrt_in_ord_lst.
*
* Inputs:
* 	Node* left: the left side comparison
* 	Node* right: the right side of the comparison
* Outputs:
*		int: the results of the comparison
********************************************************************************
* Pseudocode
*   Begin
*   	assign variables 
*   	perform comparison 
*   	return results
*   End
*******************************************************************************/
int compare_double(const void *left, const void *right){
	double da = *(const double*)left;
  double db = *(const double*)right; 
  if(da>db) return 1;
  else if(da<db) return -1;
  else return 0;
}

/*******************************************************************************
* Function Title: compare_string
* Summary: This function compares 
*
* Inputs:
* 	const void* right: the right side of the comparison
* 	const void* left: the left side of comparison
* Outputs:
* 	int: the results of the comparison
********************************************************************************
* Pseudocode
*   Begin
*			assign variables
*			loop while right[i] == left[i]
*				if left > right 
*					set return 1
*					break
*				else if right < left
*					set return -1
*				endif 
*			endloop 
*   End
*******************************************************************************/

int compare_string(const void* left, const void* right){
	int i, retVal = 0;
  const char * s_right = (const char*) right;
  const char * s_left = (const char*) left;
  for(i = 0; i < strlen(s_right) && i < strlen(s_left); ++i){
		if(s_left[i] > s_right[i]){
			retVal = 1;
    } else if (s_left[i] < s_right[i]){
			retVal = -1;
    }
  }
  return retVal;
}

/*******************************************************************************
* Function Title: compare_complex
* Summary:
*
* Inputs:
* Outputs:
*
* Compile Instructions:
********************************************************************************
* Pseudocode
*   Begin
*
*   End
*******************************************************************************/
