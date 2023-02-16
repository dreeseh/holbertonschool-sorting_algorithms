#include "sort.h"


/**
 * list_len - finds lenght of linked list
 *
 * @head: head of list
 * Return: lenght
 */
size_t list_len(const listint_t *head)
{
	size_t lenght = 0;

	while (head != NULL)
	{
		lenght++;
		head = head->next;
	}

	return (lenght);
}

/**
 * swap_nodes - swap node with node at pointer
 * @list: head of list
 * @p: pointer to node
 */
void swap_nodes(listint_t **list, listint_t **p)
{
	listint_t *one, *two, *three, *four;

	one = (*p)->prev;
	two = *p;
	three = (*p)->next;
	four = (*p)->next->next;
	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;
	if (one)
		one->next = three;
	else
		*list = three;
	two->prev = three;
	*p = three;
}

/**
 * cocktail_sort_list - sorts a doubly
 * linked list of integers in ascending order using the Cocktail shaker sort *
 * algorithm
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int sorted = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	p = *list;
	while (!sorted)
	{
		sorted = 1;
		while (p->next)
		{
			if (p->n > p->next->n)
			{
				sorted = 0;
				swap_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (sorted)
			break;
		p = p->prev;
		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				sorted = 0;
				p = p->prev;
				swap_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}
