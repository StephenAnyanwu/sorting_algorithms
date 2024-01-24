#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm.
 * @array: array of integers to be sorted.
 * @size: the length of @array.
 *
 * Description: print the array after each time two elements of the
 * array are swapped.
 */
void selection_sort(int *array, size_t size)
{
	int min, tmp;
	size_t i, j, min_idx;

	if (size > 2 || array != NULL)
	{
		for (i = 0; i < size; i++)
		{
			min = array[i];
			min_idx = 0;
			for (j = i; j < size; j++)
			{
				if (array[j] < min)
				{
					min = array[j];
					min_idx = j;
				}
			}
			if (min < array[i])
			{
				tmp = array[i];
				array[i] = min;
				array[min_idx] = tmp;
				print_array((const int *)array, size);
			}
		}
	}
}
