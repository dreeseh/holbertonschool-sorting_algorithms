#include "sort.h"

/**
 * bitonic_sort - sorts an array in ascending order using Bitonic sort
 * @array: input array
 * @size: size of the array
 * Return: is void
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}

	recursive_bitonic(array, 0, size, 0, size);
	sort_up(array, 0, size);
	printf("Result [%ld/%ld] (%s):\n", size, size, "UP");
	bitonic_print(array, 0, size);
}

/**
 * recursive_bitonic - a recursive bitonic sort function
 * @array: our array
 * @min: first index
 * @max: last index
 * @bool: "UP"/"DOWN"
 * @size: size_t of our array
 * Return: is void
 */
void recursive_bitonic(int *array, int min, int max, int bool, size_t size)
{
	char *up_down;

	if (max - min < 2)
	{
		return;
	}

	up_down = (bool == 0) ? "UP" : "DOWN";
	printf("Merging [%d/%ld] (%s):\n", max - min, size, up_down);
	bitonic_print(array, min, max);

	if (max - min == 2)
	{
		return;
	}

	recursive_bitonic(array, min, (max + min) / 2, 0, size);
	sort_up(array, min, (max + min) / 2);
	printf("Result [%d/%ld] (%s):\n", ((max + min) / 2) - min, size, "UP");
	bitonic_print(array, min, (max + min) / 2);

	recursive_bitonic(array, (max + min) / 2, max, 1, size);
	sort_down(array, (max + min) / 2, max);
	printf("Result [%d/%ld] (%s):\n", max - ((max + min) / 2), size, "DOWN");
	bitonic_print(array, (max + min) / 2, max);
}

/**
 * sort_up - sorts min to max
 * @array: our array
 * @min: first index
 * @max: last index
 * Return: is void
 */
void sort_up(int *array, int min, int max)
{
	int i, j, k;

	for (i = min; i < max; i++)
	{
		k = i;

		for (j = i + 1; j < max; j++)
		{
			if (array[k] > array[j])
				k = j;
		}

		if (k != i)
		{
			array[i] = array[i] + array[k];
			array[k] = array[i] - array[k];
			array[i] = array[i] - array[k];
		}
	}
}

/**
 * sort_down - sorts max to min
 * @array: our array
 * @min: first index
 * @max: last index
 * Return: is void
 */
void sort_down(int *array, int min, int max)
{
	int i, j, k;

	for (i = min; i < max; i++)
	{
		k = i;

		for (j = i + 1; j < max; j++)
		{
			if (array[k] < array[j])
				k = j;
		}

		if (k != i)
		{
			array[i] = array[i] + array[k];
			array[k] = array[i] - array[k];
			array[i] = array[i] - array[k];
		}
	}
}

/**
 * print_bitonic - prints the bitonic sequence
 * @array: input array
 * @min: first index
 * @max: last index
 * Return: is void
 */
void bitonic_print(int *array, int min, int max)
{
	char *delimiter;

	for (delimiter = ""; min < max; min++)
	{
		printf("%s%d", delimiter, array[min]);
		delimiter = ", ";
	}
	printf("\n");
}
