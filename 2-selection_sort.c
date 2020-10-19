#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of array
 * Return: is void
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int i, j, index;

	if (!array)
	{
		return;
	}

	for (i = 0 ; i < size - 1 ; i++)
	{
		index = i;
		for (j = i + 1 ; j < size ; j++)
		{
			if (array[j] < array[index])
			{
				index = j;
			}
		}
		swap(&array[index], &array[i]);
		print_array(array, size);
	}
}

/**
 * swap - swaps two integers
 * @first: first int to be swapped
 * @second: second int to be swapped
 * Return: is void
 */
void swap(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
