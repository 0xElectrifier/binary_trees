#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: the uncle to @node, or NULL if node NULL or @node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check if node, node parent and node grandparent is not NULL */
	if (node == NULL || node->parent == NULL || !(node->parent->parent))
		return (NULL);

	/*
	 * Check if @node is node grandparent left child. If true, return
	 * node grandparent right child right
	 */
	if ((node->parent->parent)->left == (node->parent))
		return ((node->parent->parent)->right);

	/* Return node grandparent left child if above condition is not met */
	return (node->parent->parent->left);
}
