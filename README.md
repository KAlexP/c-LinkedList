# LinkedList

## Summary

This code effectively creates a linked list. There are two ways to create the 
linked list; one way is to create it using `insrt_in_ord_lst`, which makes it 
an ordered linked list. The other way to create a linked list is using `inst_in_list`, 
which makes it not sorted. 

This code uses function pointers to make this linked list handle different data 
types more easily. An important definition in the included header file is 
the `CompareFunc` type that is simply the function pointer type that is the 
correct function for comparison.

## Complexity

Using big O notation for time complexity we find insertion complexity is O(n),
delete is O(n), and find is O(n). Overall not the best data structure to use for time 
reasons.

Looking at auxiliary space complexity we find that each operation is O(1). This 
is because each operation only requires making one Node, which isn't proportional
to how many elements there are. 

## How to Use

To instantiate the linked list you need to choose a data type to store in the 
linked list. You will need one `Node *` type that keeps track of the root node.

The data is stored in the linked list with type `void *`, which 
allows the code to be generic and reusable. When you want to input data you 
need to alloacate memory for your data to pass it to the insert functions.

Below is an example of how to use the liniked list. Additionally there are unit
tests for the code in the UnitTests directory.

```c
#include "LinkedList.h"
#include <time.h>

int main(int argc, char **argv){
  Node *root = NULL,*new_node;
  Node  *s_root= NULL, *s_new_node;
  int itr;
  void *data, *s_data;
  srand(time(NULL));
  for(itr=0;itr < 22;++itr){
    data = malloc(sizeof(int));
    s_data = malloc(sizeof(int));
    *(int *)data = rand();
    *(int *)s_data = rand();
    new_node = make_new_node(data);
    s_new_node = make_new_node(s_data);
    root = insrt_in_list(root,new_node);
    s_root = insrt_in_ord_lst(s_root, s_new_node, compare_int);
  }
  printf("\n\n");
  print_out(root,stdout);
  printf("\n\n");
  print_out(s_root,stdout);
  clear_linked_list(root);
  return 0;
}

}
```
