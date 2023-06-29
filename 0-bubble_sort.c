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
	size_t i, j;
	int flag;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_elements(&array[j], &array[j + 1]);
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}


/**
 * swap_elements - function that swaps two elements.
 * @a: The first element.
 * @b: The second element.
 */
void swap_elements(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
