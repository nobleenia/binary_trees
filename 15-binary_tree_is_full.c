#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{

if (tree == NULL)
{
return (0);
}
else
{
if (tree->left && tree->right)
{
int left_tree = binary_tree_is_full(tree->left);
int right_tree = binary_tree_is_full(tree->right);
if (left_tree == 0 || right_tree == 0)
{
return (0);
}
return (1);
}
else if (!tree->left && !tree->right)
{
return (1);
}
else
{
return (0);
}
}
}
