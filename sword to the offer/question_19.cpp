//¶þ²æÊ÷µÄ¾µÏñ

#include <iostream>

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
};

void MirrorRecursively(BinaryTreeNode * pNode)
{
	if (pNode == NULL)
		return;
	if (pNode->left == NULL && pNode->right == NULL)
		return;

	BinaryTreeNode * temp = pNode->left;
	pNode->left = pNode->right;
	pNode->right = temp;

	MirrorRecursively(pNode->left);
	MirrorRecursively(pNode->right);
}