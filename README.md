# LinkedList

## Summary

This code effectively creates a linked list. There are two ways to create the 
linked list; one way is to create it using `insrt_in_ord_lst`, which makes it 
an ordered linked list. The other way to create a linked list is using `inst_in_list`, 
which makes it not sorted. 

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
