#include "binary_trees.h"

/**
 * balance_avl - Balances an AVL tree.
 * @tree: A pointer to the root node of the AVL tree.
 */
void balance_avl(avl_t **tree)
{
int balance;

if (!tree || !*tree || (!(*tree)->left && !(*tree)->right))
{
return;
}

balance_avl(&(*tree)->left);
balance_avl(&(*tree)->right);

balance = binary_tree_balance((const binary_tree_t *)*tree);
if (balance > 1)
{
*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
}
else if (balance < -1)
{
*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
}

/**
 * get_successor_value - Finds the value of the in-order successor.
 * @node: A pointer to the node.
 * Return: The value of the in-order successor.
 */
int get_successor_value(bst_t *node)
{
int left = 0;

if (!node)
{
return (0);
}

left = get_successor_value(node->left);
if (left == 0)
{
return (node->n);
}

return (left);
}

/**
 * remove_node_type - Handles the removal of a node based on its children.
 * @node: A pointer to the node to be removed.
 * Return: The value to replace the removed node.
 */
int remove_node_type(bst_t *node)
{
int new_value = 0;

if (!node->left && !node->right)
{
if (node->parent->right == node)
{
node->parent->right = NULL;
}
else
{
node->parent->left = NULL;
}
free(node);
return (0);
}
else if ((!node->left && node->right) || (!node->right && node->left))
{
bst_t *child = node->left ? node->left : node->right;

if (node->parent->right == node)
{
node->parent->right = child;
}
else
{
node->parent->left = child;
}

child->parent = node->parent;
free(node);
return (0);
}
else
{
new_value = get_successor_value(node->right);
node->n = new_value;
return (new_value);
}
}

/**
 * remove_bst_node - Removes a node from a BST tree.
 * @root: A pointer to the root node of the BST tree.
 * @value: The value of the node to be removed.
 * Return: The modified root after removal.
 */
bst_t *remove_bst_node(bst_t *root, int value)
{
int type = 0;

if (!root)
{
return (NULL);
}

if (value < root->n)
{
remove_bst_node(root->left, value);
}
else if (value > root->n)
{
remove_bst_node(root->right, value);
}
else if (value == root->n)
{
type = remove_node_type(root);
if (type != 0)
{
remove_bst_node(root->right, type);
}
}
	
return (root);
}

/**
 * bst_remove - Removes a node from a BST tree.
 * @root: A pointer to the root node of the BST tree.
 * @value: The value of the node to be removed.
 * Return: The modified root after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
if (!root)
{
return (NULL);
}

bst_t *root_after_removal = remove_bst_node(root, value);
return (root_after_removal);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: A pointer to the root node of the AVL tree.
 * @value: The value of the node to be removed.
 * Return: The modified root after removal.
 */
avl_t *avl_remove(avl_t *root, int value)
{
avl_t *root_after_removal = (avl_t *)bst_remove((bst_t *)root, value);

if (!root_after_removal)
{
return (NULL);
}

balance_avl(&root_after_removal);
return (root_after_removal);
}
