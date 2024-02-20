#include "sort.h"

/**
 * swap - swap two
 * @x: node
 * @y: node
*/
void swap(listint_t *x, listint_t *y)
{
	if (x->prev)
	{
		x->prev->next = y;
	}
	if (y->next)
	{
		y->next->prev = x;
	}

	x->next = y->next;
	y->prev = x->prev;
	x->prev = y;
	y->next = x;
}

/**
 * insertion_sort_list - sort list
 * @list: the list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || !*list || !(*list)->next)
		return;

	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap(j->prev, j);
				if (!j->prev)
				{
					*list = j;
				}
				print_list((const listint_t *)*list);
			}
			else
				j = j->prev;
		}
	}
}
