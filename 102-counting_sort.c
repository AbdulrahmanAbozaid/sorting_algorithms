#include "sort.h"

/**
 * getMax - get the max
 * @arr: the array
 * @size: sz
 *
 * Return: the max ele
 */
int getMax(int *arr, size_t size)
{
	int mx = INT_MIN;
	size_t i = 0;

	for (; i < size; i++)
	{
		if (arr[i] > mx)
			mx = arr[i];
	}
	return (mx);
}

/**
 * counting_sort - count then sort techniqe
 * @array: arr
 * @size: sz
 */
void counting_sort(int *array, size_t size)
{
	int k = getMax(array, size);
	int *count;
	int *arr;
	size_t i;

	if (!array || !size)
		return;
	count = malloc((k + 1) * sizeof(k));
	arr = malloc(size * sizeof(array[0]));
	if (!count)
	{
		if (arr)
			free(arr);
		return;
	}
	if (!arr)
	{
		free(count);
		return;
	}
	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}
	for (i = 1; (int)i <= k; i++)
	{
		count[i] += count[i - 1];
	}
	print_array(count, k + 1);
	for (i = size - 1; (int)i >= 0; i--)
	{
		arr[--count[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = arr[i];
	}
	free(arr);
	free(count);
}
