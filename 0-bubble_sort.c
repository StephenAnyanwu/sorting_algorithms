#include "sort.h"

/**
 * bubble_sort -  sorts an array of integers in
 * ascending order using the Bubble sort algorithm.
 * @array: array of integers to be sorted.
 * @size: number of elements in @array.
 */

void bubble_sort(int *array, size_t size)
{
	int temp, swapped = 0;
	size_t i, t, c, n;

	if (size && size > 1)
	{
		t = 0;
		c = size;
		n = size;
		while (t < c)
		{
			for (i = 0; i < n - 1; i++)
				if (array[i] > array[i + 1])
				{
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					swapped = 1;
					/* print array after each time swap */
					print_array((const int *)array, size);
				}
			if (swapped == 0)
				break;
			t++;
			n--;
		}
	}
}
