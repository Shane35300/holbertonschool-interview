#include "binary_trees.h"
#include <limits.h>

/**
 * height - Calculates the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    int left_height = height(tree->left);
    int right_height = height(tree->right);
    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_bst - Helper function to verify if a tree is a BST
 * @tree: Pointer to the root node
 * @min: Minimum allowable value for a node
 * @max: Maximum allowable value for a node
 *
 * Return: 1 if tree is a valid BST, otherwise 0
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (!tree)
        return (1);
    if (tree->n <= min || tree->n >= max)
        return (0);
    return (is_bst(tree->left, min, tree->n) &&
            is_bst(tree->right, tree->n, max));
}

/**
 * is_avl_helper - Helper function to verify if a tree is an AVL tree
 * @tree: Pointer to the root node
 * @height_diff: Pointer to store height difference
 *
 * Return: 1 if tree is a valid AVL tree, otherwise 0
 */
int is_avl_helper(const binary_tree_t *tree)
{
    if (!tree)
        return (1);

    int left_height = height(tree->left);
    int right_height = height(tree->right);

    /* Check height difference */
    if (abs(left_height - right_height) > 1)
        return (0);

    /* Check if both left and right subtrees are AVL */
    return (is_avl_helper(tree->left) && is_avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    /* Check if tree is a BST */
    if (!is_bst(tree, INT_MIN, INT_MAX))
        return (0);

    /* Check if tree is balanced (AVL property) */
    return (is_avl_helper(tree));
}
