#include "sort.h"
/**
 * _swap - swaps positions in the list
 * @position_1: position 1/2 to be swapped
 * @position_2: position 2/2 to be swapped
 * Return: is void
 */
void swap(int position_1, int position_2)
{
	int place_holder;

	place_holder = position_1;
	position_1 = position_2;
	position_2 = place_holder;
}
