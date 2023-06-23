#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers in ascending
 * order.
 * @list: The array to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL, *current = NULL;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do
	{
		swapped = 0;
		for (current = *list; current->next != end; current = current->next)
        	{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
		end = current;
		swapped = 0;
		for (current = current->prev; current->prev != start->prev; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
		}
		start = current->next;
	}
	while (swapped);
}


/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to a pointer to the first element of the list
 * @node1: Pointer to the first node to swap
 * @node2: Pointer to the second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *temp;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;

	temp = node1->prev;
	node1->prev = node2;
	node2->prev = temp;

	temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;
}
