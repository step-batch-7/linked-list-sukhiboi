#include <stdio.h>
#include "list.h"

int assert(int expectation, int actual)
{
    return expectation == actual;
}

int ptr_assert(Node_ptr expectation, Node_ptr actual)
{
    return expectation == actual;
}

void print_result(int result, char *test_name)
{
    if (result == 1)
    {
        printf("✔ %s\n", test_name);
        return;
    }
    printf("✘ %s\n", test_name);
}
