#ifndef _SORT_HEADER_
#define _SORT_HEADER_

#include <stdio.h>
#include <stdlib.h>

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

/** prototypes **/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *first, int *second);
int partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void merge(int *array, int *sub, size_t size);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

void shell_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *array, int min, int max, size_t size);
void radix_sort(int *array, size_t size);

#endif /** _SORT_HEADER_ **/
