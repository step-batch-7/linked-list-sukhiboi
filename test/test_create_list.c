#include <stdio.h>
#include "list.h"
#include "assert.h"

void test_is_count_zero(List_ptr list)
{
    int test_result = assert(list->count, 0);
    print_result(test_result, "Count is 0");
}

void test_is_head_null(List_ptr list)
{
    int test_result = ptr_assert(list->head, NULL);
    print_result(test_result, "Head is null");
}

void test_is_last_null(List_ptr list)
{
    int test_result = ptr_assert(list->last, NULL);
    print_result(test_result, "Last is null");
}

void test_create_list(void)
{
    printf("Testing create_list\n");
    List_ptr list = create_list();
    test_is_count_zero(list);
    test_is_head_null(list);
    test_is_last_null(list);
}