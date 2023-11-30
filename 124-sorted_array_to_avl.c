#include "binary_trees.h"

/**
 * sorted_array_to_avl_helper - Recursive helper function for AVL tree creation.
 * @array: Pointer to the first element of the array.
 * @start: Starting index of the subarray.
 * @end: Ending index of the subarray.
 * @parent: Pointer to the parent node.
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl_helper(int *array, size_t start, size_t end, avl_t *parent)
{
if (start > end)
{
return (NULL);
}

size_t mid = (start + end) / 2;
avl_t *new_node = binary_tree_node(parent, array[mid]);

if (!new_node)
{
return (NULL);
}

new_node->left = sorted_array_to_avl_helper(array, start, mid - 1, new_node);
new_node->right = sorted_array_to_avl_helper(array, mid + 1, end, new_node);

return (new_node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
if (!array || size == 0)
{
return (NULL);
}

return (sorted_array_to_avl_helper(array, 0, size - 1, NULL));
}
