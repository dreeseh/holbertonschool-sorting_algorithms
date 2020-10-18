#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: the array to be sorted
 * @size: size of the array to be printed
 * Return: is void
 */
void bubble_sort(int *array, size_t size)
{
	size_t stepper, i;

	if (array == NULL)
	{
		return;
	}

	for (stepper = 0 ; stepper < size -1 ; stepper++)
	{
		for (i = 0 ; i < (size - stepper) - 1 ; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array[i], array[i + 1]);
				print_array(array, size);
			}
		}
	}
}
