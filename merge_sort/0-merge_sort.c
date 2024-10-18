#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Fusionne deux sous-tableaux triés en un seul tableau trié
 *
 * @array: Le tableau d'origine
 * @left: Le sous-tableau de gauche
 * @right: Le sous-tableau de droite
 * @size_left: La taille du sous-tableau de gauche
 * @size_right: La taille du sous-tableau de droite
 */
void merge(int *array, int *left, int *right, size_t size_left,
size_t size_right)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);

	while (i < size_left && j < size_right)
	{
		if (left[i] <= right[j])
		{
			array[k++] = left[i++];
		}
		else
		{
			array[k++] = right[j++];
		}
	}
	while (i < size_left)
	{
		array[k++] = left[i++];
	}
	while (j < size_right)
	{
		array[k++] = right[j++];
	}

	printf("[Done]: ");
	print_array(array, size_left + size_right);
}

/**
 * merge_sort_recursive - Fonction récursive pour le tri par fusion
 *
 * @array: Le tableau à trier
 * @size: La taille du tableau
 */
void merge_sort_recursive(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}

	size_t mid = size / 2;
	int *left = malloc(mid * sizeof(int));
	int *right = malloc((size - mid) * sizeof(int));

	if (!left || !right)
	{
		free(left);
		free(right);
		return;
	}

	for (size_t i = 0; i < mid; i++)
	{
		left[i] = array[i];
	}
	for (size_t i = mid; i < size; i++)
	{
		right[i - mid] = array[i];
	}

	merge_sort_recursive(left, mid);
	merge_sort_recursive(right, size - mid);

	merge(array, left, right, mid, size - mid);

	free(left);
	free(right);
}

/**
 * merge_sort - Fonction principale pour le tri par fusion
 *
 * @array: Le tableau à trier
 * @size: La taille du tableau
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}

	merge_sort_recursive(array, size);
}
