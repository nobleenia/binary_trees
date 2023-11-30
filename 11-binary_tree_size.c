#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{

if (tree == NULL)
{
return (0);
}

size_t tree_size = 1;
tree_size += binary_tree_size(tree->left);
tree_size += binary_tree_size(tree->right);

return (tree_size);
}
