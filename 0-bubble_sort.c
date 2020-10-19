#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: the array to be sorted
 * @size: size of the array to be printed
 * Return: is void
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int temp, stepper, i;

	if (!array)
	{
		return;
	}

	for (stepper = 0 ; stepper < size - 1 ; stepper++)
	{
		for (i = 0 ; i < size - 1 ; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
