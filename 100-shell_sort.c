#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * shell_sort - Function that sorts an array using the shell sort algorithm.
 * @array: The array to be sorted.
 * @size: The length of the array.
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j;
	size_t gap = 1;
	int temp;

	while (gap < size) /*find the initial gap using the kKnuth Sequence*/
	{
		gap = gap * 3 + 1;
	}
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i < size && array[i + gap] < array[i]; i -= gap)
			{
				/*swap elements*/
				temp = array[i + gap];
				array[i + gap] = array[i];
				array[i] = temp;
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3; /*calculate next gap using the Knuth Sequence.*/
	}
}
