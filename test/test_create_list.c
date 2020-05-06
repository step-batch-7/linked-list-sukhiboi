#include <stdio.h>
#include "list.h"
#include "my_assert.h"

void test_create_list(void)
{
    printf("Testing create_list\n");
    List_ptr list = create_list();
    assert(list->count, 0, "Count is 0");
    ptr_assert(list->head, NULL, "Head is null");
    ptr_assert(list->last, NULL, "Last is null");
}