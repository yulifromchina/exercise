//判断一棵树是不是平衡二叉树

#include <iostream>


struct BinaryNode
{
	int key;
	BinaryNode * left;
	BinaryNode * right;
	BinaryNode(int value) :key(value), left(NULL), right(NULL) {}
};


bool IsBalanced(BinaryNode * root, int & dep)
{
	if (root == NULL)
	{
		dep = 0;
		return true;
	}
	int left_dep=0, right_dep = 0;
	if (IsBalanced(root->left, left_dep) && IsBalanced(root->right, right_dep))
	{
		if (left_dep - right_dep > 1 || left_dep - right_dep < -1)
		{
			return false;
		}
		else
		{
			dep = left_dep > right_dep ? left_dep + 1 : right_dep + 1;
			return true;
		}
	}
	else
		return false;
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

	int dep = 0;
	cout << "except 1, actually " << IsBalanced(root, dep)<< endl;
	cout << " depth excpet 4, actually " << dep << endl;

	return 0;
}