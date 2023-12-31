#ifndef SORT_H
#define SORT_H
#include <stddef.h>
#include <stdbool.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/**
 * enum boolean - function called enum.
 *
 * @false_: Boolean condition.
 * @true_: Boolean condition.
 */
typedef enum boolean
{
	false_,
	true_
} boolean;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void swap_elements(int *a, int *b);
int partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void swap(int *a, int *b);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void merge_sort_helper(int *array, int l, int r);
void merge(int *array, int l, int m, int r);
void sift_down(int *array, size_t start, size_t end);
void heapify(int *array, size_t size, size_t root, size_t heap_size);
int get_max(int *array, size_t size);
void count_sort_array(int *array, size_t size, int exp);
void bitonic_merge(int *array, size_t size, bool dir);
void bitonic_compare(int *array, size_t i, size_t j, bool dir);
#endif
