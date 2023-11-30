#include "binary_trees.h"

/**
* binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the parent node
 * @value: value to be stored in the new node
 *
 * Return: pointer to the newly created node, or NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *new_node;

if (parent == NULL)
{
return (NULL);
}

new_node = malloc(sizeof(binary_tree_t));
if (new_node == NULL)
{
return (NULL);
}

if (parent->right != NULL)
{
new_node->right = parent->right;
parent->right->parent = new_node;
}
parent->right = new_node;
new_node->n = value;
new_node->parent = parent;
new_node->left = NULL;

return (new_node);
}
