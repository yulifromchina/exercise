//求二叉树的深度

#include <iostream>

struct BinaryNode
{
	int key;
	BinaryNode * left;
	BinaryNode * right;
	BinaryNode(int value) :key(value), left(NULL), right(NULL) {}
};

int GetDepth(BinaryNode * root)
{
	if (root == NULL)
		return 0;
	int left = GetDepth(root->left);
	int right = GetDepth(root->right);
	return left > right ? left + 1 : right + 1;
}

int main()
{
	using namespace std;

	BinaryNode * root = new BinaryNode(1);
	root->left = new BinaryNode(2);
	root->right = new BinaryNode(3);
	root->right->right = new BinaryNode(6);

	root->left->left = new BinaryNode(4);
	root->left->right = new BinaryNode(5);
	root->left->right->left = new BinaryNode(7);

	cout << "except 4, actually " << GetDepth(root) << endl;

	return 0;
}