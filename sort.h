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

void heap_sort(int *array, size_t size);
void heapify(int *array, int min, int max, size_t size);
void radix_sort(int *array, size_t size);

/** 100-shell_sort.c **/
void shell_sort(int *array, size_t size);
void swap_k(int *array, int j, int gap);
size_t kunth_seq(size_t max);

/** 101-cocktail_sort_list.c **/
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t **p);

/** 102-counting_sort.c **/
void counting_sort(int *array, size_t size);

/** 106-bitonic_sort.c **/
void bitonic_print(int *arr, int i, int limit);
void sort_up(int *arr, int low, int high);
void sort_down(int *arr, int low, int high);
void recursive_bitonic(int *array, int min, int max, int bool, size_t size);
void bitonic_sort(int *array, size_t size);

/** 107-quick_sort_hoare.c **/
void quick_sort_hoare(int *array, size_t size);

#endif /** _SORT_HEADER_ **/
