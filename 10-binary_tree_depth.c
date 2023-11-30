#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure
 *
 * Return: depth of the node, 0 if tree is NULL or node has no parent
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{

if (tree == NULL)
{
return (0);
}

 return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
