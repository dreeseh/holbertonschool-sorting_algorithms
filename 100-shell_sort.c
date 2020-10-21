#include "sort.h"
/**
 * shell_sort - sorts an array using the Shell sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: is void
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t gap, i, j;

	if (size == 0 || size == 1)
		return;

	gap = 1;

	while (gap < size)
	{
		gap = gap * 3 - 1;
	}

	gap = (gap - 1) / 3;
	while (gap > 0)
	{
		i = gap;
		while (i < size)
		{
			temp = array[i];
			for (j = i ; j >= gap && array[j - gap] > temp ; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
			i++;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
