#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @low: The starting index of the subarray
 * @high: The ending index of the subarray
 */
void print_array(int *array, size_t low, size_t high)
{
	printf("Searching in array: ");
	for (size_t i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i < high)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search_recursive - Helper function to perform binary search recursive
 * @array: Pointer to the first element of the array
 * @low: The starting index of the subarray
 * @high: The ending index of the subarray
 * @value: The value to search for
 *
 * Return: The index where value is located, or -1 if not found
 */
int binary_search_recursive(int *array, size_t low, size_t high, int value)
{
	if (low > high)
		return (-1);

	print_array(array, low, high);

	size_t mid = low + (high - low) / 2;

	if (array[mid] == value)
	{
		if (mid == low || array[mid - 1] != value)
			return (mid);
		return (binary_search_recursive(array, low, mid, value));
	}
	else if (array[mid] > value)
		return (binary_search_recursive(array, low, mid - 1, value));
	else
		return (binary_search_recursive(array, mid + 1, high, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array using binary search
 * @array: Pointer to the first element of the array
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search_recursive(array, 0, size - 1, value));
}
