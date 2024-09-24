#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>  /* Pour size_t */
#include <stdlib.h>  /* Pour malloc, free */
#include <stdio.h>   /* Pour printf */

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

/* Prototypes */
int heap_extract(heap_t **root);
void heapify_down(heap_t *node);
heap_t *last_node(heap_t *root);
void binary_tree_print(const binary_tree_t *);

#endif /* BINARY_TREES_H */
