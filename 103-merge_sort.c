#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_sort - Function that merges an array.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	merge_sort_helper(array, 0, size - 1);
}


/**
 * merge_sort_helper - Recursive helper function for merge sort.
 * @array: Pointer to first element of the array.
 * @l: Left index of the subarray.
 * @r: Right index of the subarray.
 */

void merge_sort_helper(int *array, int l, int r)
{
	int m;

	if (l < r)
	{
		m = l + (r - l) / 2;

		merge_sort_helper(array, l, m);
		merge_sort_helper(array, m + 1, r);

		printf("Merging...\n");
		printf("[left]: ");
		print_array(array + l, m - l + 1);
		printf("[right]: ");
		print_array(array + m + 1, r - m);

		merge(array, 1, m, r);
		printf("[Done]: ");
		print_array(array + l, r - l + 1);
		printf("\n");
	}
}


/**
 * merge - function that merges the two subarrays.
 * @array: The array to be marged.
 * @l: left index of subarray.
 * @r: The right index os fubarray.
 * @m: The merged array.
 */

void merge(int *array, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int *left = malloc(n1 * sizeof(int));
	int *right = malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
		left[i] = array[l + i];
	for (j = 0; j < n2; j++)
		right[j] = array[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		array[k] = left[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = right[j];
		j++;
		k++;
	}
	free(left);
	free(right);
}
