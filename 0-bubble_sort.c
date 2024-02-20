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
 * bubble_sort - sort a list of objects
 * @array: list of objects
 * @size: number of objects
*/
void bubble_sort(int *array, size_t size)
{
	int i, j;
	int swapped = 0;

	if (!array || !size)
		return;

	for (i = 0; i < (int)size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < (int)size - i - 1; j++)
		{
		if (array[j] > array[j + 1])
			{
				swapped = 1;
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}

		if (!swapped)
			break;
	}
}
