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
	int max = array[0];
	int *count, *sorted;
	int j;
	size_t i;

	if (array == NULL || size <= 1)
		return;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (j = 0; j <= max; j++)
		count[j] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (j = 1; j <= max; j++)
		count[j] += count[j - 1];

	sorted = malloc(size * sizeof(int));
	if (sorted == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	for (j = 0; j <= max; j++)
		printf("%d%s", count[j], (j == max) ? "\n" : ", ");
	free(count);
	free(sorted);
}
