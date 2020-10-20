#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: double pointer to doubly linked list
 * Return: is void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current->next;

		while (current->prev && current->n < current->prev->n)
		{
			current->prev->next = current->next;

			if (current->next != NULL)
			{
				current->next->prev = current->prev;

			}
			current->next = current->prev;
			current->prev = current->next->prev;

			if (current->prev != NULL)
			{
				current->prev->next = current;
			}
			else
			{
				*list = current;
			}
			current->next->prev = current;
			print_list(*list);
		}
		current = temp;
	}
}
