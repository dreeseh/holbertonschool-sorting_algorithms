#include "sort.h"

/**
 * quick_sort_recursive - use recursion with quick_sort
 * @array: array to be sorted
 * @low: first element of array
 * @high: last element of array
 * @size: size of array
 * Return: is void
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quick_sort_recursive(array, low, pi, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * partition - splits array aroud a pivot
 * @array: array to be split
 * @low: low side of array
 * @high: high side of array
 * @size: size fo array
 * Return: element that is a pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1;
	int y = high + 1;
	int tmp;

	while (1)
	{
		do {
			x++;
		} while (array[x] < pivot);

		do {
			y--;
		} while (array[y] > pivot);

		if (x > y)
			return (y);
		if (x == y)
			return (y - 1);
		tmp = array[x];
		array[x] = array[y];
		array[y] = tmp;
		print_array(array, size);
	}
}

/**
 * quick_sort_hoare - sort using hoare method
 * @array: our array
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	unsigned int low = 0;
	unsigned int high = size - 1;

	if (size == 0 || size == 1)
		return;

	quick_sort_recursive(array, low, high, size);
}
