#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
if (tree == NULL)
{
return (NULL);
}

if (*tree == NULL)
{
*tree = binary_tree_node(NULL, value);
return (*tree);
}

if (value == (*tree)->n)
{
return (NULL);
}

if (value < (*tree)->n)
{
if ((*tree)->left == NULL)
{
(*tree)->left = binary_tree_node(*tree, value);
return ((*tree)->left);
}
else
{
return (bst_insert(&((*tree)->left), value));
}
}

else
{
if ((*tree)->right == NULL)
{
(*tree)->right = binary_tree_node(*tree, value);
return ((*tree)->right);
}
else
{
return (bst_insert(&((*tree)->right), value));
}
}
}
