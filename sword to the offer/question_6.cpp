//根据前序和中序遍历重建二叉树
//前序：1 2 4 7 3 5 6 8
//中序：4 7 2 1 5 3 8 6

#include <iostream>
#include <queue>
#include <stack>
#include <cassert>


using namespace std;


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

typedef struct BinaryTreeNode BinaryTreeNode;



//递归前序遍历二叉树
void prePrintRecursion(BinaryTreeNode * tree)
{
	if (tree == NULL)
		return;
	cout << tree->value << " ";
	prePrintRecursion(tree->left);
	prePrintRecursion(tree->right);
}



//根据前序和中序遍历建立二叉树
BinaryTreeNode * pre_in_create(int * pre, int * in, int pre_start, int pre_end, int in_start, int in_end);
BinaryTreeNode * constructTree(int * pre, int * in, size_t len)
{
	if(pre==NULL || in == NULL || len <=0)
		return NULL;
	return pre_in_create(pre, in, 0, len-1, 0, len-1);
}


//子函数
BinaryTreeNode * pre_in_create(int * pre, int * in, int pre_start, int pre_end, int in_start, int in_end)
{
	BinaryTreeNode * root = new BinaryTreeNode(pre[pre_start]);
	assert(root);
 
	int i;
	for (i = 0; in[i] != root->value && i<=in_end; ++i);
	
	int left_child = i - in_start;
	int right_child = in_end - i;

	if (left_child)
		root->left = pre_in_create(pre, in, pre_start+1, pre_start + left_child,
			in_start, in_start + left_child -1); 

	if (right_child)
		root->right = pre_in_create(pre, in, pre_end- right_child +1, pre_end,
			in_end - right_child+1,in_end);

	return root;
}



int main()
{
	int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	BinaryTreeNode * tree = constructTree(pre, in, sizeof(pre)/sizeof(int));

	cout << "前序遍历二叉树：";
	prePrintRecursion(tree);
	return 0;
}