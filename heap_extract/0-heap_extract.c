#include "binary_trees.h"

/**
 * heapify_down - Restores the max heap property after extraction
 * @node: Pointer to the node to heapify down from
 */
void heapify_down(heap_t *node)
{
heap_t *max = node;
heap_t *left = node->left;
heap_t *right = node->right;

if (left && left->n > max->n)
	max = left;

if (right && right->n > max->n)
	max = right;

if (max != node)
{
	/* Swap values */
	int temp = node->n;

	node->n = max->n;
	max->n = temp;
	heapify_down(max);  /* Continue heapifying down */
}
}

/**
 * last_node - Finds the last node in a binary heap using level-order traversal
 * @root: Pointer to the root of the heap
 * Return: Pointer to the last node in level-order
 */
heap_t *last_node(heap_t *root)
{
if (!root)
	return (NULL);

/* Utiliser une file pour le parcours en largeur */
heap_t **queue;
int front = 0, rear = 0;
heap_t *node = NULL;

/* Allouer suffisamment de place pour la file */
queue = malloc(sizeof(heap_t *) * 1024);
if (!queue)
	return (NULL);

queue[rear++] = root;  /* Enqueue la racine */

while (front < rear)  /* Tant qu'il reste des éléments dans la file */
{
	node = queue[front++];  /* Dequeue l'élément courant */

	/* Enqueue les enfants gauche et droit */
	if (node->left)
		queue[rear++] = node->left;
	if (node->right)
		queue[rear++] = node->right;
}

free(queue);
return (node);  /* Retourne le dernier nœud rencontré */
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node, or 0 if the heap is empty
 */
int heap_extract(heap_t **root)
{
if (!root || !*root)
	return (0);  /* Heap is empty */

heap_t *node = *root;
int value = node->n;  /* Store the value of the root */

heap_t *last = last_node(node);  /* Find the last node */
if (!last)
	return (0);

/* Swap the last node with the root */
node->n = last->n;

/* Remove the last node from the tree */
if (last->parent)
{
	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;
}
free(last);

/* Heapify down from the new root */
heapify_down(*root);

return (value);
}
