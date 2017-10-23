//输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//从树的根结点开始一直往下，直到叶结点，所经过的结点形成一条路径

#include <iostream>
#include <vector>

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

void SubFindPath(BinaryTreeNode * tree, int value, std::vector<int> path, int path_sum)
{
	//处理当前结点
	path_sum += tree->value;
	path.push_back(tree->value);

	//如果该结点是叶结点，且路径和为指定值，则输出
	if (path_sum == value && tree->left == NULL && tree->right == NULL)
	{
		std::cout << "path:(";
		for (auto it : path)
			std::cout << it << " ";
		std::cout << ")" << std::endl;
	}

	//如果不是叶结点，则遍历子结点
	if (tree->left)
		SubFindPath(tree->left, value, path, path_sum);
	if (tree->right)
		SubFindPath(tree->right, value, path, path_sum);


	//因为传递的path是引用，所以返回父结点前，需要弹出此次入栈的结点
	//如果传递值，则不需要下面两行
	path.pop_back();
	path_sum -= tree->value;
}

void FindPath(BinaryTreeNode * tree, int value)
{
	if (tree == NULL)
		return;

	std::vector<int> path;
	int path_sum = 0;
	SubFindPath(tree, value, path, path_sum);

}

int main()
{
	using namespace std;
	BinaryTreeNode * tree = new BinaryTreeNode(10);
	tree->left = new BinaryTreeNode(5);
	tree->right = new BinaryTreeNode(12);
	tree->left->left = new BinaryTreeNode(4);
	tree->left->right = new BinaryTreeNode(7);
	FindPath(tree, 22);
	return 0;
}