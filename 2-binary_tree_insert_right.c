#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right child of another node
 * @parent: pointer to the node to insert the right-child
 * @value: value to store in the newly created node
 *
 * Return: pointer to the newly created node, otherwise NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	new->right = parent->right;
	parent->right = new;

	if (new->right != NULL)
		new->right->parent = new;

	return (new);

	return (new);
}
