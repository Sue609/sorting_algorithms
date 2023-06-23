#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers in ascending order
 * @array: The list of arrays that we should sort.
 * @size: The length of the array that should be sorted.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}


/**
 * quick_sort_recursive - Function the quick sort algorithm on the-arrays.
 * @array: The array that is divided into two.
 * @low: The lowest value of the array.
 * @high: The highest value of the array.
 * @size: The size of the array
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}


/**
 * partition - Function That divides the array into two.
 * @array: The array to be divided.
 * @low: The lowest point of the array.
 * @high: The highest point of the array.
 * @size: Size of the array
 *
 * Return: Index of the pivot
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
