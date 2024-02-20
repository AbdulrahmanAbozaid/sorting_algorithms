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
	int temp;

	if (*x != *y)
	{
		temp = *x;
		*x = *y;
		*y = temp;
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
	int pivot = array[lb];
	int i, j;

	i = lb;
	j = ub;

	while (1)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i >= j)
			return (j);
		swap(array, size, &array[i], &array[j]);
	}
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
	if (lb >= 0 && ub >= 0 && lb < ub)
	{
		size_t loc = partition(array, size, lb, ub);

		quickSort(array, size, lb, loc);
		quickSort(array, size, loc + 1, ub);
	}
}


/**
 * quick_sort_hoare - sort
 * @array: the arr
 * @size: the size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || !size)
		return;

	quickSort(array, size, 0, size - 1);
}
