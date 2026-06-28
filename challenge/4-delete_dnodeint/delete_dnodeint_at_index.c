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
    dlistint_t *current;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;

    /* Silinəcək elementin indeksinə qədər gedirik */
    for (i = 0; current != NULL && i < index; i++)
    {
        current = current->next;
    }

    /* Əgər verilən indeks siyahının ölçüsündən böyükdürsə */
    if (current == NULL)
        return (-1);

    /* Əgər silinəcək element ilk elementdirsə (head) */
    if (current == *head)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        /* Əvvəlki elementin next pointerini yeniləyirik */
        if (current->prev != NULL)
            current->prev->next = current->next;
        
        /* Növbəti elementin prev pointerini yeniləyirik */
        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    free(current);
    return (1);
}
