#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending
 * order using the Shell sort algorithm.
 * @array: array of integers to be sorted.
 * @size: length of @array.
 *
 * Description: impliment using Knuth sequence,
 * 1, 4, 13, 40, 121, 364,...
 * Print array each time the interval of Knuth sequence
 * is decreased
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, h, j, k;
	int tmp;

	if (array == NULL || size < 2)
		return;
	h = 1;
	/* compute last value of Knuth sequence */
	while (h < size)
		h = 3 * h + 1;
	/* h is greater than size, hence gap starts from h/3 */
	for (gap = h / 3; gap > 0; gap /= 3)
	{
		for (j = gap; j < size; j++)
		{
			for (k = j - gap; k < size; k += gap)
			{
				if (array[k] < array[j - gap])
				{
					tmp = array[k];
					array[k] = array[j - gap];
					array[j - gap] = tmp;
				}
			}
		}
		print_array(array, size);
	}
}

