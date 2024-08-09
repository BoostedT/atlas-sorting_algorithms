#include "sort.h"
/**
 * insertion_sort_list - sort array lements from min to max value
 * @list: array
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *next, *prev;

if (!list || !*list)
return;
current = *list;
while (current)
{
next = current->next;
while (current->prev && current->n < current->prev->n)
{
prev = current->prev;
prev->next = current->next;
if (current->next)
current->next->prev = prev;
current->prev = prev->prev;
current->next = prev;
if (prev->prev)
prev->prev->next = current;
else
*list = current;
prev->prev = current;
prev = current->prev;
print_list(*list);
}
current = next;
}
}
