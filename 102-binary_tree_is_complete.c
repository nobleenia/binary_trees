#include "binary_trees.h"

/**
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
if (tree == NULL)
{
return (0);
}

binary_tree_t **levels = malloc(sizeof(binary_tree_t *) * 1024);
size_t down = 0, up = 0;
int null_found = 0;

if (levels == NULL)
{
return (0);
}

levels[up++] = (binary_tree_t *)tree;

while (down < up)
{

const binary_tree_t *current = levels[down++];

if (current == NULL)
{
null_found = 1;
}
else
{
if (null_found)
{
free(levels);
return (0);
}

levels[up++] = current->left;

levels[up++] = current->right;
}
}

free(levels);

return (1);
}
