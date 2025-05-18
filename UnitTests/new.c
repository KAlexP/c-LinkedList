#include "./../LinkedList.h"
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
