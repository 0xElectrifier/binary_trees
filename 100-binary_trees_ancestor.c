#include "binary_trees.h"

/**
 * root_traverse - traverses the tree from root searching for the two nodes
 * @current: pointer to the current tree to traverse
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the found node, or NULL if non is found
 */
binary_tree_t *root_traverse(const binary_tree_t *current,
			     const binary_tree_t *first,
			     const binary_tree_t *second)
{
	binary_tree_t *left, *right;

	/* Check if current node is NULL */
	if (current == NULL)
		return (NULL);

	/* Check if current node is same as first or second */
	if (current == first || current == second)
		return ((binary_tree_t *)(current));

	/*
	 * Traverse the two child nodes, checking for the presence of
	 * either of first or second
	 */
	left = root_traverse(current->left, first, second);
	right = root_traverse(current->right, first, second);

	/*
	 * if left and right is a Non-NULL value return the current node
	 * if left or right is a Non-NULL value, return it
	 * if left and right are both NULL value, return NULL
	 */
	if (left && right)
		return ((binary_tree_t *)(current));
	else if (left)
		return (left);
	else if (right)
		return (right);
	else
		return (NULL);

}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *second_root = second;
	const binary_tree_t *first_root = first;

	if (!first || !second)
		return (NULL);

	/* Track the root node of both nodes */
	while (first_root->parent)
		first_root = first_root->parent;
	while (second_root->parent)
		second_root = second_root->parent;

	/* Compare them to know if they belong to the same sub-tree */
	if (first_root == second_root)
		return (root_traverse(first_root, first, second));

	return (NULL);
}
