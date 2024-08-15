#include "search.h"
#include <stdio.h>

/**
 * linear_skip - Searches for a value in a sorted skip list
 *
 * @list: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list;
	skiplist_t *prev = NULL;

	if (list == NULL)
		return (NULL);

	// Use the express lane to skip ahead
	while (current->express && current->express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   current->express->index, current->express->n);
		prev = current;
		current = current->express;
	}

	if (current->express)
		printf("Value found between indexes [%lu] and [%lu]\n",
			   prev ? prev->index : 0, current->express->index);
	else
		printf("Value found between indexes [%lu] and [%lu]\n",
			   prev ? prev->index : 0, current->index);

	// Linear search within the block
	while (current && current->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   current->index, current->n);
		current = current->next;
	}
	if (current)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   current->index, current->n);
	}

	return (current && current->n == value) ? current : NULL;
}
