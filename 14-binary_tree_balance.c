#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{

if (tree == NULL)
{
return (0);
}

 size_t left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
size_t right_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;

return ((left_height > right_height) ? left_height : right_height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: balance factor of the tree, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{

if (tree == NULL)
{
return (0);
}

return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
