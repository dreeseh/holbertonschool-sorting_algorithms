#include "sort.h"
/**
 * counting_sort - sorts an array with the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count = NULL, *out = NULL, length, num, j, l;
	size_t one, two, three, four;

	if (size < 2)
		return;

	length = array[0];
	for (one = 1; one < size; one++)
		if (array[one] > length)
			length = array[one];

	count = malloc(sizeof(size_t) * (length + 1));
	out = malloc(sizeof(int) * size);

	for (j = 0; j <= length; j++)
		count[j] = 0;
	for (two = 0; two < size; two++)
	{
		num = array[two];
		count[num] += 1;
	}
	for (l = 1; l <= length; l++)
		count[l] += count[l - 1];
	print_array(count, length + 1);
	for (three = 0; three < size; three++)
	{
		out[count[array[three]] - 1] = array[three];
		count[array[three]]--;
	}
	for (four = 0; four < size; four++)
		array[four] = out[four];

	free(count);
	free(out);

}

