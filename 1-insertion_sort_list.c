#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - function that worts a doubly linked list of integers in ascending
 * order using the insert sort algorithm.
 * @list: The array of the list to be sorted.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *temp;
	listint_t *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			if (current->next != NULL)
				current->next->prev = prev;
			prev->next = current->next;
			current->prev = prev->prev;
			current->next = prev;
			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;
			prev->prev = current;
			prev = current->prev;
			print_list(*list);
		}
		current = temp->next;
	}
}
