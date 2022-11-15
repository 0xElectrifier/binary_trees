#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to node to measure the depth
 *
 * Return: the depth of @tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while ((tree != NULL) && (tree->parent != NULL))
	{
		depth += 1;
		tree = tree->parent;
	}

	return (depth);
}
