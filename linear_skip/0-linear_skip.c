#include "search.h"
#include <stdio.h>

/**
 * linear_skip - Searches for a value in a sorted skip list
 *
 * @list: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *node = list;
skiplist_t *prev = NULL;

if (list == NULL)
	return (NULL);

while (node->express != NULL && node->express->n < value)
{
	prev = node;
	node = node->express;
	printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
}

if (node->express != NULL)
	printf("Value found between indexes [%lu] and [%lu]\n",
			prev ? prev->index : 0, node->express->index);
else
	printf("Value found between indexes [%lu] and [%lu]\n",
			prev ? prev->index : 0, node->index);

node = prev ? prev : list;
while (node != NULL &&
	node->index <= (node->express ? node->express->index : SIZE_MAX))
{
	printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
	if (node->n == value)
		return (node);
	node = node->next;
}

return (NULL);
}
