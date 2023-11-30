#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor, or NULL if no common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{

if (first == NULL || second == NULL)
{
return (NULL);
}

if (first == second || first == second->parent)
{
return ((binary_tree_t *)first);
}

if (first->parent == second || second == first->parent)
{
return ((binary_tree_t *)second);
}

return (binary_trees_ancestor(first->parent, second->parent));
}
