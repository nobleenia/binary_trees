#include "binary_trees.h"
#include "0-binary_tree_node.c"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: Size of the tree, 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
if (!tree)
{
return (0);
}

return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: A double pointer to the root node of the Heap to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *tree, *new, *flip;
int size, leaves, sub, bit, level, tmp;

if (!root)
{
return (NULL);
}

if (!(*root))
{
return (*root = binary_tree_node(NULL, value));
}

tree = *root;
size = binary_tree_size(tree);
leaves = size;

for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
{
leaves -= sub;
}

for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
{
tree = leaves & bit ? tree->right : tree->left;
}

new = binary_tree_node(tree, value);
leaves & 1 ? (tree->right = new) : (tree->left = new);

flip = new;
for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
{
tmp = flip->n;
flip->n = flip->parent->n;
flip->parent->n = tmp;
new = new->parent;
}

return (new);
}
