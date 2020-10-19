#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of array
 * Return: is void
 */
void quick_sort(int *array, size_t size)
{
	int high, low;

	high = size - 1;
	low = 0;
	quick_sort_recursive(array, low, high, size);
}

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
		quick_sort_recursive(array, low, pi - 1, size);
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
	int pivot, i, j;

	pivot = array[high];
	i = (low - 1);
	j = low;

	for (; j < high ; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (pivot < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap - swaps 2 elements
 * @first: first element
 * @second: second element
 * Return: is void
 */
void swap(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
