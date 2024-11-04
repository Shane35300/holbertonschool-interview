#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - get the max value in the array
 * @array: array of integers
 * @size: size of the array
 * Return: Valeur maximale
 */
int get_max(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
 * counting_sort_for_radix - Sort the array with a specific number
 * @array: array of integers
 * @size: size of array
 * @exp: exposer
 */
void counting_sort_for_radix(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};

	for (size_t i = 0; i < size; i++)
	{
		int digit = (array[i] / exp) % 10;

		count[digit]++;
	}

	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--)
	{
		int digit = (array[i] / exp) % 10;

		output[count[digit] - 1] = array[i];
		count[digit]--;
	}

	for (size_t i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(output);
	print_array(array, size);
}

/**
 * radix_sort - sort the array (lsd order)
 * @array: array of integers
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);

	if (!array || size < 2)
		return;

	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_for_radix(array, size, exp);
	}
}
