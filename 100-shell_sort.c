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

	if (size < 2 || array == NULL)
		return;

	for (gap = size/2 ; gap > 0 ; gap /= 2)
	{

		for (i = gap ; i < size ; i += 1)
		{
			temp = array[i];
			for (j = i ; j >= gap && array[j - gap] > temp ; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
