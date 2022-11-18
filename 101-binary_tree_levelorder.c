#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t  height_left, height_right;

	if ((tree == NULL) || (tree->left == NULL && tree->right == NULL))
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);
	if (height_left >= height_right)
		return (height_left + 1);
	else
		return (height_right + 1);
}
/**
 * levelorder - traverses a binary tree using level order traversal
 * @level: depth to traverse to
 * @i: current depth during traversal
 * @tree: pointer to root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: nothing
 */
void levelorder(int level, int i, const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || i > level)
		return;

	if (level == 0)
		func(tree->n);

	if (i != level)
	{
		levelorder(level, i + 1, tree->left, func);
		levelorder(level, i + 1, tree->right, func);
	}
	func(tree->n);
}
/**
 * binary_tree_levelorder - goes through a binary tree using
 *			    level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height, level, i = 0;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	for (level = 0; level <= height; level++)
		levelorder(level, i, tree, func);
}
