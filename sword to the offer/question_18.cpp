//树的子结构
//判断tree2是否是tree1的子结构

#include <iostream>
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
};

bool IsSameTree(BinaryTreeNode * tree1, BinaryTreeNode * tree2)
{
	if (tree1 == NULL && tree2 == NULL)
		return true;
	if (tree1 == NULL || tree2 == NULL)
		return false;
	if (tree1->value != tree2->value)
		return false;
	return IsSameTree(tree1->left, tree2->left) && IsSameTree(tree1->right, tree2->right);
}

bool HasSubtree(BinaryTreeNode * tree1, BinaryTreeNode * tree2)
{
	if (tree1 == NULL && tree2 == NULL)
		return true;
	if (tree1 == NULL || tree2 == NULL)
		return false;

	return IsSameTree(tree1, tree2) || HasSubtree(tree1->left, tree2) || HasSubtree(tree1->right, tree2);

}