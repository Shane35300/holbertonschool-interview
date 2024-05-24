#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);

/* Queue structure for level order insertion */
typedef struct queue_node_s
{
	binary_tree_t *node;
	struct queue_node_s *next;
} queue_node_t;

typedef struct queue_s
{
	queue_node_t *front;
	queue_node_t *rear;
} queue_t;

/* Queue management function prototypes */
queue_t *queue_create(void);
queue_node_t *enqueue(queue_t *queue, binary_tree_t *node);
binary_tree_t *dequeue(queue_t *queue);
void free_queue(queue_t *queue);

/* Heap management function prototypes */
heap_t *heapify_up(heap_t *node);

#endif /* BINARY_TREES_H */
