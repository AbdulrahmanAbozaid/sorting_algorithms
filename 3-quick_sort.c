#include "sort.h"

/**
 * swap - swap two integers
 * @array: the array
 * @size: the size
 * @x: the first
 * @y: the second
*/
void swap(int *array, size_t size, int *x, int *y)
{
	if (*x != *y)
	{
		*x = *x + *y;
		*y = *x - *y;
		*x = *x - *y;
		print_array((const int *)array, size);
	}
}

/**
 * partition - partition the array
 * @array: the array
 * @size: the size
 * @lb: lower bound
 * @ub: upper bound
 * Return: index of the pivot
*/
int partition(int *array, size_t size, int lb, int ub)
{
	int pivot = array[ub];
	int i, j;

	for (i = j = lb; j < ub; j++)
	{
		if (array[j] <= pivot)
			swap(array, size, &array[i++], &array[j]);
	}

	swap(array, size, &array[i], &array[ub]);

	return (i);
}

/**
 * quickSort - sort the bound
 * @array: the array
 * @size: size of the array
 * @lb: lower bound
 * @ub: upper bound
*/
void quickSort(int *array, size_t size, int lb, int ub)
{
	if (lb < ub)
	{
		size_t loc = partition(array, size, lb, ub);

		quickSort(array, size, lb, loc - 1);
		quickSort(array, size, loc + 1, ub);
	}
}

/**
 * quick_sort - sort a list of objects
 * @array: list of objects
 * @size: number of objects
*/
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	quickSort(array, size, 0, size - 1);
}
