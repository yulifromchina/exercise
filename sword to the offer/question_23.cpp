//从上到下层序打印二叉树

#include <iostream>
#include <queue>

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
	BinaryTreeNode(int _value) :value(_value) 
	{
		left = NULL;
		right = NULL;
	}
};

void PrintFromTopToBottom(BinaryTreeNode * tree)
{
	if (tree == NULL)
		return;

	std::queue<BinaryTreeNode *> _queue;
	_queue.push(tree);

	while (!_queue.empty())
	{
		BinaryTreeNode * cur = _queue.front();
		_queue.pop();

		std::cout << cur->value << " ";
		if (cur->left)
			_queue.push(cur->left);
		if (cur->right)
			_queue.push(cur->right);
	}
}

int main()
{
	using namespace std;
	BinaryTreeNode * tree = new BinaryTreeNode(8);
	tree->left = new BinaryTreeNode(6);
	tree->left->left = new BinaryTreeNode(5);
	tree->left->right = new BinaryTreeNode(7);
	tree->right = new BinaryTreeNode(10);
	tree->right->left = new BinaryTreeNode(9);
	tree->right->right = new BinaryTreeNode(11);
	PrintFromTopToBottom( tree);
	cout << endl;

	return 0;
}

