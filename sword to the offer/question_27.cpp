//����һ�ö��������������ö���������ת��Ϊһ�������˫������
//Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н���ָ��

#include <iostream>

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


//�Ӻ���
//����treeΪ��/�����ĸ���㣬����last_nodeΪ������˫�������β���
void ConvertHelper(BinaryTreeNode * tree, BinaryTreeNode ** last_node)
{
	if (tree == NULL)
		return;

	if (tree->left)
		ConvertHelper(tree->left, last_node);

	tree->left = *last_node;
	if (*last_node != NULL)
		(*last_node)->right = tree;

	*last_node = tree;

	if (tree->right)
		ConvertHelper(tree->right, last_node);
}


BinaryTreeNode * Convert(BinaryTreeNode * tree)
{
	if (tree == NULL)
		return NULL;

	BinaryTreeNode * last_node = NULL;
	ConvertHelper(tree, &last_node);

	BinaryTreeNode * head = last_node;
	//��ǰ���ҵ�˫������ĵ�һ�����
	while (head != NULL && head->left != NULL)
		head = head->left;
	
	return head;
}

int main()
{
	BinaryTreeNode * tree = new BinaryTreeNode(10);
	tree->left = new BinaryTreeNode(6);
	tree->left->left = new BinaryTreeNode(4);
	tree->left->right = new BinaryTreeNode(8);

	tree->right = new BinaryTreeNode(14);
	tree->right->left = new BinaryTreeNode(12);
	tree->right->right = new BinaryTreeNode(16);

	BinaryTreeNode * head = Convert(tree);

	while (head && head->right)
	{
		std::cout << head->value << "->";
		head = head->right;
	}
	std::cout << std::endl;
	return 0;
}