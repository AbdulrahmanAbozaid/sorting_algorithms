#include "sort.h"

/**
 * swap - swap two integers
 * @x: the first
 * @y: the second
*/
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * selection_sort - sort a list of objects
 * @array: list of objects
 * @size: number of objects
*/
void selection_sort(int *array, size_t size)
{
	int i, j, min_idx;

	for (i = 0; i < (int)size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < (int)size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			swap(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
