#include "binary_trees.h"

/**
 * root_traverse - traverses the tree from root searching for two nodes
 * @current: pointer to the current tree to traverse
 * @firsr: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the found node, or NULL if non is found
 */
binary_tree_t *root_traverse(const binary_tree_t *current,
			     const binary_tree_t *first,
			     const binary_tree_t *second)
{
	binary_tree_t *left, *right;

	if (current == NULL)
		return (NULL);

	if (current == first || current == second)
		return (binary_tree_t *)(current);

	left = root_traverse(current->left, first, second);
	right = root_traverse(current->right, first, second);

	if (left && right)
		return (binary_tree_t *)(current);
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

	while (first_root->parent)
		first_root = first_root->parent;
	while (second_root->parent)
		second_root = second_root->parent;

	if (first_root == second_root)
		return(root_traverse(first_root, first, second));

	return (NULL);
}
