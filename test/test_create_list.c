#include <stdio.h>
#include "list.h"
#include "my_assert.h"

void test_create_list(void)
{
    printf("\nTesting create_list\n");
    List_ptr list = create_list();
    assert(list->count, 0, "Count should be 0");
    ptr_assert(list->head, NULL, "Head should be NULL");
    ptr_assert(list->last, NULL, "Last should be NULL");
}