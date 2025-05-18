#include "LinkedList.h"

int main(int argc, char **argv){
	Node *root,*new_node;
	Node  *s_root, *s_new_node;
	int itr;
	void *data, *s_data;
	for(itr=0;itr < 22;++itr){
		data = malloc(sizeof(int));
		s_data = malloc(sizeof(int));
		*(int *)data = (itr >> 2);
		*(int *)s_data = (itr << 4);
		new_node = make_new_node(data);
		s_new_node = make_new_node(s_data);
		insrt_in_list(root,new_node);
		s_root = insrt_in_ord_lst(s_root, s_new_node, compare_int);
	}
	print_out(root,stdout);
	clear_linked_list(root);
	return 0;
}
