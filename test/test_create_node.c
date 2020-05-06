#include <stdio.h>
#include "list.h"
#include "my_assert.h"

void test_create_node(void)
{
    printf("\nTesting create_node\n");
    Node_ptr node = create_node(12);
    assert(node->value, 12, "Value should be passed value");
    ptr_assert(node->next, NULL, "Next should be NULL");
}