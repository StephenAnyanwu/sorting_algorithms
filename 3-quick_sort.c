#include "sort.h"

/**
 * partition - divides the array integers into two partitions.
 * @array: the array of of integers to be partitioned.
 * @size: length of @array.
 * @low: first index of @array.
 * @high: last index of @array.
 * Return: the index the partitioned the array into two.
 */
int partition(int *array, size_t size, size_t low, size_t high)
{
	size_t pivot, i, j;
	int tmp;

	/* initialized pivot */
	pivot = high;
	/* swap marker */
	i = low - 1;
	for (j = low; j <= high; j++)
	{
		if (array[j] <= array[pivot])
		{
			++i;
			if (j > i)
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
		}
	}
	return (i);
}

/**
 * lomuto_sort - recursively impliment quick sort algorithm.
 * @array: array of integers to be sorted.
 * @size: length of @array.
 * @low: first index of @array.
 * @high: last index of @array.
 */
void lomuto_sort(int *array, size_t size, size_t low, size_t high)
{
	size_t pivot;

	if (low < high)
	{
		pivot = partition(array, size, low, high);
		if (pivot > 0)
			lomuto_sort(array, size, low, pivot - 1);
		if (pivot < high)
			lomuto_sort(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm.
 * @array: the array of intehgers to be sorted.
 * @size: length of @array.
 *
 * Decription: The quick sort is implimented using Lomuto
 * Partition Scheme. This algorithm works by assuming the
 * pivot element as the last element. If any other element
 * is given as a pivot element then swap it first with the
 * last element. See https://www.youtube.com/watch?v=WprjBK0p6rw
 * for clarity.
 * Print the array after each time two elements are swapped.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
