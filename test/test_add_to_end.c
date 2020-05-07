#include <stdio.h>
#include "list.h"
#include "my_assert.h"

void test_add_to_end(void)
{
    printf("\nTesting add_to_end\n");
    List_ptr list = create_list();
    add_to_end(list, 10);
    assert(list->count, 1, "Count should be 1");
    assert(list->head->value, 10, "First element's value should be the passed value");
    assert(list->last->value, 10, "Last element's value should be the passed value");
    ptr_assert(list->head->next, NULL, "Next of the first element should be NULL");
    ptr_assert(list->head, list->last, "Both head and last should point to the same element");
    printf("\n- After adding one more element\n");
    add_to_end(list, 20);
    assert(list->count, 2, "Count should be 2");
    assert(list->head->value, 10, "First element's value should be the first passed value");
    assert(list->last->value, 20, "Last element's value should be the second passed value");
    not_ptr_assert(list->head->next, NULL, "Next of the first element should NOT be NULL");
    ptr_assert(list->head->next, list->last, "Next of the first element should point to the last element");
    ptr_assert(list->last->next, NULL, "Next of the second/last element should be NULL");
    not_ptr_assert(list->head, list->last, "Both head and last should NOT point to the same element");
    printf("\n- After adding one more element\n");
    add_to_end(list, 30);
    assert(list->count, 3, "Count should be 3");
    assert(list->head->value, 10, "First element's value should be the first passed value");
    assert(list->head->next->value, 20, "Second element's value should be the second passed value");
    assert(list->last->value, 30, "Third element's value should be the second passed value");
}