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

	if (tree == NULL)
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);
	if (height_left >= height_right)
		return (height_left + 1);
	else
		return (height_right + 1);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: size of @tree or 0 if @tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (size);

	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size + 1);
}

/**
 * _pow_recursion - function that returns the value of x raised to the power
 * of y
 * @x: first integer parameter
 * @y: second integer parameter
 *
 * Return: x raised to the power of y
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, y - 1));
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if @tree is full, otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	double tree_height, tree_size, complete_size;

	if (tree == NULL)
		return (0);

	tree_height = binary_tree_height(tree);
	tree_size = binary_tree_size(tree);

	complete_size = _pow_recursion(2, tree_height) - 1;
	if (complete_size == tree_size)
		return (1);
	else
		return (0);
}
