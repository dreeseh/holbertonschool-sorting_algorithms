#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of array
 * Return: is void
 */
void selection_sort(int *array, size_t size)
{
	int *new_array;
	size_t i, j;

	new_array = NULL;
	for (i = 0 ; array && i < size - 1 ; i++)
	{
		new_array = NULL;
		for (j = i + 1 ; j < size ; j++)
		{
			if (array[j] < array[i])
			{
				if (new_array && array[j] < *new_array)
				{
					new_array = &array[j];
				}
				if (new_array == NULL)
				{
					new_array = &array[j];
				}
			}
		}
		if (new_array)
		{
			swap(new_array, &array[i]);
			print_array(array, size);
		}
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
