#include "sort.h"

/**
 * heapify - Ensures the max heap property for a subtree
 *
 * This function maintains the max heap property for a subtree rooted at
 * index `i` within an array of size `n`. It compares the root element
 * with its children and swaps them if the children are larger, then
 * recursively applies the process to the affected subtree.
 *
 * @array: The array of integers representing the heap
 * @n: The number of elements in the heap
 * @i: The index of the root element of the subtree
 * @size: The total size of the array (used for printing)
 */
void heapify(int *array, size_t n, size_t i, size_t size)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		int temp = array[i];

		array[i] = array[largest];
		array[largest] = temp;

		print_array(array, size);

		heapify(array, n, largest, size);
	}
}

/**
 * heap_sort - Sorts an array using the heap sort algorithm
 *
 * This function sorts an array of integers in ascending order using the
 * heap sort algorithm. It first builds a max heap, then repeatedly
 * extracts the largest element (root of the heap) and reduces the heap
 * size until the entire array is sorted.
 *
 * @array: The array of integers to be sorted
 * @size: The number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (int i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);

		heapify(array, i, 0, size);
	}
}
