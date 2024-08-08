#include "sort.h"
/**
 * insertion_sort_list - sort array lements from min to max value
 * @list: array
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *tmp;
if (list == NULL || *list == NULL)
return;
current = (*list)->next;
while (current)
{
while (current->prev && current->n < current->prev->n)
{
tmp = current->prev;
current->prev = tmp->prev;
if (tmp->prev)
tmp->prev->next = current;
tmp->next = current->next;
if (current->next)
current->next->prev = tmp;
tmp->next = current;
current->prev = tmp;
if (!current->prev)
*list = current;
print_list(*list);
}
current = current->next;
}
}
