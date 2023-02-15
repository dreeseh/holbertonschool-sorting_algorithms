#include "sort.h"

/**
 * shell_sort - Kunth Sequence Shell-Sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: is void
 */
void shell_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, gap = 0, flag = 0;
	int right = 0, left = 0;

	if (array == NULL || size < 2)
		return;

	gap = size;
	while (gap > 1)
	{
		gap = kunth_seq(gap);

		for (i = 0; i < size - gap; i++)
		{
			for (j = i + gap; j >= gap; j--)
			{
				left = array[j - gap];
				right = array[j];
				if (right < left)
				{
					swap_k(array, j, gap);
					flag++;
				}

				if (j == 0)
					break;
			}
		}

		print_array(array, size);
		flag = 0;
	}
}

/**
 * kunth_seq - the Kunth sequence
 * @max: limiting the gap size
 * Return: size_t gap size
 */
size_t kunth_seq(size_t max)
{
	size_t n = 0, gap = 0;

	while (n < max)
	{
		gap = n;
		n = n * 3 + 1;
	}
	return (gap);
}

/**
 * swap_k - swaps ints
 * @array: our array
 * @j: int to swap
 * @gap: int to swap
 * Return: is void
 */
void swap_k(int *array, int j, int gap)
{
	int temp = 0;

	temp = array[j - gap];
	array[j - gap] = array[j];
	array[j] = temp;
}
