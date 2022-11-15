#include "binary_trees.h"

/**
 * check_depth - checks the height of the left side tree structure down till
 *		 till a leave is found
 * @tree: pointer to root of node to check it left side height
 *
 * Return: leftside height of tree
 */
int check_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->left == NULL)
		return (0);

	return (1 + check_depth(tree->left));
}

/**
 * is_perfect - checks recursively if a binary tree is perfect
 * @tree: pointer to root of node to check
 * @height: height of left side branch of tree
 * @level: current visitation level as we traverse down the tree
 *
 * Return: 1 if perfect, otherwise 0
 */
int is_perfect(const binary_tree_t *tree, int height, int level)
{
	int left_ret = 0, right_ret = 0;

	if (tree == NULL)
		return (0);

	/* Check if node is leaf (tree) */
	if (!tree->left && !tree->right)
		return (level == height);
	else if (!tree->left || !tree->right)
		return (0);

	if (tree->left && tree->right)
	{
		left_ret = is_perfect(tree->left, height, level + 1);
		if (left_ret != 0)
			right_ret = is_perfect(tree->right, height, level + 1);
	}

	return (left_ret && right_ret);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root of the tree to check
 *
 * Return: 1 if tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, ret;

	left_height = check_depth(tree);

	ret = is_perfect(tree, left_height, 0);

	return (ret);
}
