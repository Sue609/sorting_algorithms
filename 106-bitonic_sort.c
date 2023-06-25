#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"


/**
 * botonic_sort - sorts an array using botonic sort algorithm.
 * @array: The input array.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	size_t half;

	if (size > 1)
	{
		half = size / 2;
		bitonic_sort(array, half);
		bitonic_sort(array + half, half);
		bitonic_merge(array, size, true);
	}
	printf("Result [%lu/%lu] (UP):\n", (unsigned long)size, (unsigned long)size);
	print_array(array, size);
}


/**
 * bitonic_merge - Recursively merge two bitonic sequences
 * @array: The input array
 * @size: The size of the sequence
 * @start: The start index of the first sequence
 * @step: The step size for comparing elements
 * @dir: The sorting direction (true for ascending, false for descending)
 */
void bitonic_merge(int *array, size_t size, bool dir)
{
	size_t half, i;

	if (size > 1)
	{
		half = size / 2;

		for (i = 0; i < half; i++)
		{
			bitonic_compare(array, i, i + half, dir);
		}
		bitonic_merge(array, half, dir);
		bitonic_merge(array + half, half, dir);
	}
	printf("Merging [%lu/%lu] (%s):\n", (unsigned long)size, (unsigned long)size, dir ? "UP" : "DOWN");
	print_array(array, size);
}


/**
 * botonic_compare - Compares two elements in a botonic sequence.
 * @array: The input array
 * @size: The size of the sequence.
 * @i: The index of the first element.
 * @j: The index of the second element.
 * @dir: The sorting direction (true for ascending &vise versa.
 */
void bitonic_compare(int *array, size_t i, size_t j, bool dir)
{
	int temp;

	if ((array[i] > array[j]) == dir)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}
