#include "binary_trees.h"
#include <stdlib.h>

/**
 * heapify_up - Ensures the max-heap property is maintained after insertion
 * @node: Pointer to the newly inserted node
 *
 * Return: Pointer to the node in its correct position
 */
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	queue_t *queue;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*root)
		return (*root = new_node);

	queue = queue_create();
	if (!queue)
		return (NULL);

	enqueue(queue, *root);
	while (queue->front)
	{
		parent = dequeue(queue);
		if (!parent->left || !parent->right)
		{
			if (!parent->left)
				parent->left = new_node;
			else
				parent->right = new_node;
			new_node->parent = parent;
			break;
		}
		enqueue(queue, parent->left);
		enqueue(queue, parent->right);
	}
	free_queue(queue);
	return (heapify_up(new_node));
}

/* Additional necessary functions for queue management */

/**
 * queue_create - Creates a queue
 *
 * Return: Pointer to the created queue, or NULL on failure
 */
queue_t *queue_create(void)
{
	queue_t *queue = malloc(sizeof(queue_t));

	if (!queue)
		return (NULL);
	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}

/**
 * enqueue - Adds a node to the queue
 * @queue: Pointer to the queue
 * @node: Pointer to the node to be added
 *
 * Return: Pointer to the added queue node, or NULL on failure
 */
queue_node_t *enqueue(queue_t *queue, binary_tree_t *node)
{
	queue_node_t *new_node = malloc(sizeof(queue_node_t));

	if (!new_node)
		return (NULL);
	new_node->node = node;
	new_node->next = NULL;
	if (!queue->rear)
	{
		queue->front = new_node;
		queue->rear = new_node;
	}
	else
	{
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
	return (new_node);
}

/**
 * dequeue - Removes a node from the queue
 * @queue: Pointer to the queue
 *
 * Return: Pointer to the removed binary tree node, or NULL on failure
 */
binary_tree_t *dequeue(queue_t *queue)
{
	queue_node_t *temp_node;
	binary_tree_t *node;

	if (!queue->front)
		return (NULL);

	temp_node = queue->front;
	node = temp_node->node;
	queue->front = queue->front->next;
	if (!queue->front)
		queue->rear = NULL;

	free(temp_node);
	return (node);
}

/**
 * free_queue - Frees the queue
 * @queue: Pointer to the queue
 */
void free_queue(queue_t *queue)
{
	queue_node_t *temp;

	while (queue->front)
	{
		temp = queue->front;
		queue->front = queue->front->next;
		free(temp);
	}
	free(queue);
}
