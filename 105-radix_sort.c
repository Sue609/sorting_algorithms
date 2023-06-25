#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <stdbool.h>
#include <limits.h>


/**
 * radix_sort - function that sorts using the radix sort algorithm.
 * @array: The array to be sorted.
 * @size: The lenght of the array.
 */

void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort_array(array, size, exp);
		print_array(array, size);
	}
}


/**
 * count_sort_array - function that permorms counting sort on an array.
 * @array: The input array.
 * @size: The size of the array.
 * @exp: The current digit position.
 */

void count_sort_array(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;

	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}


/**
 * get_max - Get the maximum element from an array
 * @array: The input array
 * @size: The size of the array
 * Return: The maximum element
 */
int get_max(int *array, size_t size)
{
	int max = INT_MIN;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
