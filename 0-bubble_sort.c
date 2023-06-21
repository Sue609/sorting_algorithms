#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


/**
 * bubble_sort - a function that sorts an array of integers in ascending
 * order using the Bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_elements(&array[j], &array[j + 1]);
			}
			for (k = 0; k < size; k++)
			{
				printf("%d", array[k]);
				if (k != size - 1)
					printf(", ");
			}
			printf("\n");
		}
	}
}


/**
 * swap_elements - Function that swaps elements in an array.
 * @a: Element to be swapped.
 * @b: Element to be swapped.
 */
void swap_elements(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
