#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Fusionne deux sous-tableaux triés en un seul tableau trié
 *
 * @array: Le tableau d'origine
 * @temp: Tableau temporaire utilisé pour la fusion
 * @left: Index du début du sous-tableau de gauche
 * @mid: Milieu du tableau, séparant les deux sous-tableaux
 * @right: Index de fin du sous-tableau de droite
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];
	while (j < right)
		temp[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Fonction récursive pour le tri par fusion
 *
 * @array: Le tableau à trier
 * @temp: Tableau temporaire utilisé pour la fusion
 * @left: Index du début du sous-tableau
 * @right: Index de fin du sous-tableau
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	if (right - left < 2)
		return;

	size_t mid = (left + right) / 2;

	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid, right);

	merge(array, temp, left, mid, right);
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
		return;

	int *temp = malloc(size * sizeof(int));

	if (!temp)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}
