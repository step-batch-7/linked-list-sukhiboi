#include <stdio.h>
#include "list.h"
#include "my_assert.h"

void assert(int expectation, int actual, char *test_name)
{
    print_result(expectation == actual, test_name);
}

void ptr_assert(Node_ptr expectation, Node_ptr actual, char *test_name)
{
    print_result(expectation == actual, test_name);
}

void not_ptr_assert(Node_ptr expectation, Node_ptr actual, char *test_name)
{
    print_result(expectation != actual, test_name);
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
