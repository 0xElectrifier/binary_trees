#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if @tree is full, otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int ret_left, ret_right;

	if (tree == NULL)
		return (0);

	if ((tree->left == NULL) && (tree->right == NULL))
		return (1);

	if ((tree->left != NULL) && (tree->right != NULL))
	{
		ret_left = binary_tree_is_full(tree->left);
		/*
		 * The 'if statement' makes sure a recursion doesn't start
		 * if ret_left == 0, to speed up performance
		 */
		if (ret_left != 0)
			ret_right = binary_tree_is_full(tree->right);

		return (ret_left && ret_right);
	}
	else
		return (0);
}
