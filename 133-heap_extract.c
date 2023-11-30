#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height or 0 if tree is NULL.
 */
size_t tree_height(const heap_t *tree)
{
size_t height_left = 0;
size_t height_right = 0;

if (!tree)
{
return (0);
}

if (tree->left)
{
height_left = 1 + tree_height(tree->left);
}

if (tree->right)
{
height_right = 1 + tree_height(tree->right);
}

return (height_left > height_right ? height_left : height_right);
}

/**
 * tree_size_h - Measures the sum of heights of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height or 0 if tree is NULL.
 */
size_t tree_size_h(const binary_tree_t *tree)
{
size_t height_left = 0;
size_t height_right = 0;

if (!tree)
{
return (0);
}

if (tree->left)
{
height_left = 1 + tree_size_h(tree->left);
}

if (tree->right)
{
height_right = 1 + tree_size_h(tree->right);
}

return (height_left + height_right);
}

/**
 * _preorder - Goes through a binary tree using pre-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @node: Will be the last node in traverse.
 * @height: Height of the tree.
 *
 * Return: No Return.
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
if (!tree)
{
return;
}

if (!height)
{
*node = tree;
}
height--;

_preorder(tree->left, node, height);
_preorder(tree->right, node, height);
}

/**
 * heapify - Heapifies max binary heap.
 * @root: Pointer to binary heap.
 */
void heapify(heap_t *root)
{
int value;
heap_t *tmp1, *tmp2;

if (!root)
{
return;
}

tmp1 = root;

while (1)
{
if (!tmp1->left)
break;
if (!tmp1->right)
{
tmp2 = tmp1->left;
}
else
{
tmp2 = (tmp1->left->n > tmp1->right->n) ? tmp1->left : tmp1->right;
}
if (tmp1->n > tmp2->n)
break;
value = tmp1->n;
tmp1->n = tmp2->n;
tmp2->n = value;
tmp1 = tmp2;
}
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap.
 * @root: Pointer to the heap root.
 * Return: Value of the extracted node.
 */
int heap_extract(heap_t **root)
{
int value;
heap_t *heap_root, *node;

if (!root || !*root)
{
return (0);
}
heap_root = *root;
value = heap_root->n;
if (!heap_root->left && !heap_root->right)
{
*root = NULL;
free(heap_root);
return (value);
}

_preorder(heap_root, &node, tree_height(heap_root));

heap_root->n = node->n;
if (node->parent->right)
{
node->parent->right = NULL;
}
else
{
node->parent->left = NULL;
}
free(node);
heapify(heap_root);
*root = heap_root;
return (value);
}
