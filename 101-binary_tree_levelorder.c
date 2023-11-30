#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node
 *
 * If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{

if (tree == NULL || func == NULL)
{
return;
}

binary_tree_t **levels = malloc(sizeof(binary_tree_t *) * 1024);
size_t down = 0, up = 0;

if (levels == NULL)
{
return;
}

levels[up++] = (binary_tree_t *)tree;

while (down < up)
{

const binary_tree_t *current = levels[down++];
{
func(current->n);
}

if (current->left != NULL)
{
levels[up++] = current->left;
}

if (current->right != NULL)
{
levels[up++] = current->right;
}
}

free(levels);
}
