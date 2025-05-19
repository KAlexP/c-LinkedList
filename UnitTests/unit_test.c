#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "./../LinkedList.h"

void test_insrt_in_list(void){
  Node *head = NULL, *new_node;
  void *data = malloc(sizeof(int));
  *(int *)data = 10;
  new_node = make_new_node(data);
  head = insrt_in_list(head, new_node);

  CU_ASSERT(length(head) == 1);
  CU_ASSERT(*(int *)head->value == 10);
  CU_ASSERT(head->next == NULL);

  data = malloc(sizeof(int));
  *(int *)data = 12;
  new_node = make_new_node(data);
  insrt_in_list(head,new_node);
  CU_ASSERT(search_linked_list(data,head,compare_int) == 1);
}

int main(void){
	CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("LinkedList",0,0);

  CU_add_test(suite, "test_insrt_in_list", test_insrt_in_list);

  CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}
