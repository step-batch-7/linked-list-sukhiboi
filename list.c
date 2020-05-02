#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node_ptr create_node(int value)
{
    Node_ptr node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

List_ptr create_list(void)
{
    List_ptr list = malloc(sizeof(List));
    list->head = NULL;
    list->last = NULL;
    list->count = 0;
    return list;
}

Status add_to_end(List_ptr list, int value)
{
    Node_ptr new_node = create_node(value);
    if (list->head == NULL)
    {
        list->head = new_node;
    }
    else
    {
        list->last->next = new_node;
    }
    list->last = new_node;
    list->count++;
    return Success;
}

Status add_to_start(List_ptr list, int value)
{
    Node_ptr new_node = create_node(value);
    if (list->head == NULL)
    {
        list->head = new_node;
        list->last = new_node;
    }
    else
    {
        new_node->next = list->head;
        list->head = new_node;
    }
    list->count++;
    return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
    int idx = 0;
    if (position == 0)
    {
        return add_to_start(list, value);
    }
    Node_ptr previous_node, p_walker = list->head, new_node = create_node(value);
    while (p_walker != NULL)
    {
        if (idx == position)
        {
            previous_node->next = new_node;
            new_node->next = p_walker;
            list->count++;
            return Success;
        }
        previous_node = p_walker;
        p_walker = p_walker->next;
        idx++;
    }
    return Failure;
}

Status is_number_available(List_ptr list, int number)
{
    Node_ptr p_walker = list->head;
    while (p_walker != NULL)
    {
        if (p_walker->value == number)
        {
            return Success;
        }
        p_walker = p_walker->next;
    }
    return Failure;
}

Status add_unique(List_ptr list, int value)
{
    if (is_number_available(list, value))
        return Failure;
    return add_to_end(list, value);
}

void display(List_ptr list)
{
    Node_ptr p_walker = list->head;
    while (p_walker != NULL)
    {
        printf("%d\n", p_walker->value);
        p_walker = p_walker->next;
    }
}

Status remove_from_start(List_ptr list)
{
    Node_ptr to_be_removed = list->head;
    list->head = list->head->next;
    free(to_be_removed);
    list->count--;
    return Success;
}

Status remove_at(List_ptr list, int position)
{
    if (position == 0)
    {
        return remove_from_start(list);
    }
    if (list->head == list->last)
    {
        return clear_list(list);
    }
    int pos = 0;
    Node_ptr previous_node, p_walker = list->head;
    while (p_walker != NULL)
    {
        if (pos == position)
        {
            previous_node->next = p_walker->next;
            free(p_walker);
            list->count--;
            return Success;
        }
        previous_node = p_walker;
        p_walker = p_walker->next;
        pos++;
    }
    return Failure;
}

Status remove_from_end(List_ptr list)
{
    return remove_at(list, list->count - 1);
}

Status remove_first_occurrence(List_ptr list, int value)
{
    int position = get_position(list, value);
    if (position == -1)
        return Failure;
    return remove_at(list, position);
}

Status remove_all_occurrences(List_ptr list, int value)
{
    int position = get_position(list, value);
    if (position == -1)
        return Failure;
    while (position != -1)
    {
        remove_at(list, position);
        position = get_position(list, value);
    }
    return Success;
}

int get_position(List_ptr list, int value)
{
    int pos = 0;
    Node_ptr p_walker = list->head;
    while (p_walker != NULL)
    {
        if (p_walker->value == value)
        {
            return pos;
        }
        pos++;
        p_walker = p_walker->next;
    }
    return -1;
}

Status clear_list(List_ptr list)
{
    Node_ptr previous_node, p_walker = list->head;
    while (p_walker != NULL)
    {
        previous_node = p_walker;
        p_walker = p_walker->next;
        free(previous_node);
    }
    list->head = NULL;
    list->last = NULL;
    list->count = 0;
    return Success;
}

void destroy_list(List_ptr list)
{
    clear_list(list);
    free(list);
}