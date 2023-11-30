#include "binary_trees.h"

/**
 * binary_tree_height - Computes the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height, right_height;

if (tree == NULL)
{
return (0);
}

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

return ((1 + (left_height > right_height ? left_height : right_height)));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
int balance, left_avl, right_avl;

if (tree == NULL)
{
return (0);
}

left_avl = binary_tree_is_avl(tree->left);
right_avl = binary_tree_is_avl(tree->right);

balance = binary_tree_height(tree->left) - binary_tree_height(tree->right);

if (balance >= -1 && balance <= 1 && left_avl && right_avl)
{
return (1);
}

return (0);
}
