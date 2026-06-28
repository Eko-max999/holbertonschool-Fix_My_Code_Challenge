#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t list
 * @head: Pointer to the pointer of the first node of the list
 * @index: Index of the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *saved_head;
    unsigned int p;

    if (*head == NULL)
    {
        return (-1);
    }
    saved_head = *head;
    p = 0;
    while (p < index && saved_head != NULL)
    {
        saved_head = saved_head->next;
        p++;
    }
    if (p != index || saved_head == NULL)
    {
        return (-1);
    }
    if (saved_head == *head)
    {
        *head = saved_head->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
    else
    {
        saved_head->prev->next = saved_head->next;
        if (saved_head->next != NULL)
        {
            saved_head->next->prev = saved_head->prev;
        }
    }
    free(saved_head);
    return (1);
}
