#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - function that sorts an array of integers in ascending order
 * using te counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void counting_sort(int *array, size_t size)
{
	int max = 0;
	int *count_array, *output;
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count_array = malloc((max + 1) * sizeof(int));
	if (count_array == NULL)
		return;

	for (i = 0; i <= max; i++)
		count_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;

	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];

	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count_array);
		return;
	}

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	print_array(count_array, max + 1);

	free(count_array);
	free(output);
}
