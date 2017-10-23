//����һ�ö�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
//�����ĸ���㿪ʼһֱ���£�ֱ��Ҷ��㣬�������Ľ���γ�һ��·��

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
	//����ǰ���
	path_sum += tree->value;
	path.push_back(tree->value);

	//����ý����Ҷ��㣬��·����Ϊָ��ֵ�������
	if (path_sum == value && tree->left == NULL && tree->right == NULL)
	{
		std::cout << "path:(";
		for (auto it : path)
			std::cout << it << " ";
		std::cout << ")" << std::endl;
	}

	//�������Ҷ��㣬������ӽ��
	if (tree->left)
		SubFindPath(tree->left, value, path, path_sum);
	if (tree->right)
		SubFindPath(tree->right, value, path, path_sum);


	//��Ϊ���ݵ�path�����ã����Է��ظ����ǰ����Ҫ�����˴���ջ�Ľ��
	//�������ֵ������Ҫ��������
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