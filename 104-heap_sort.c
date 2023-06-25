#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * heap_sort - function that sorts an array using heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i != 0; i--)
		heapify(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}


/**
 * heapify - Maintains the heap property for a subtree rooted at index 'root'
 * @array: The array to be sorted
 * @size: Size of the array
 * @root: Root index of the subtree
 * @heap_size: Size of the current heap
 */

void heapify(int *array, size_t size, size_t root, size_t heap_size)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < heap_size && array[left] > array[largest])
		largest = left;

	if (right < heap_size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest, heap_size);
	}
}


/**
 * swap - Function that swaps two elements.
 * @a: The element to be swapped.
 * @b: The element to be swapped.
 */

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
