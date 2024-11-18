#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/* Structure de base d'un nœud d'arbre binaire */
typedef struct binary_tree_s
{
int n;
struct binary_tree_s *parent;
struct binary_tree_s *left;
struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s avl_t;

/* Prototypes des fonctions */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
int binary_tree_is_avl(const binary_tree_t *tree);

/* Fonction fournie pour afficher un arbre binaire */
void binary_tree_print(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
