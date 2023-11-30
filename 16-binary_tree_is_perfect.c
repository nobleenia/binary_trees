#include "binary_trees.h"

/**
 * perfect_tree - recursively checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: height of the perfect tree, 0 if not perfect
 */
int perfect_tree(const binary_tree_t *tree)
{

int left_height, right_height;

if (tree == NULL)
{
return (0);
}

if (!tree->left && !tree->right)
{
return (1);
}

if (tree->left && tree->right)
{
left_height = perfect_tree(tree->left);
right_height = perfect_tree(tree->right);

if (left_height == right_height && left_height != 0)
{
return (1 + left_height);
}
}
return (0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{

if (tree == NULL)
{
return (0);
}
return (perfect_tree(tree) != 0);
}
