#pragma once
#include <iostream>
#include <stack>
#define DEBUG

struct Node
{
	int weight;
	int left;
	int right;
	int parent;

	struct Node ()
	{
		weight = 0;
		left = -1;
		right = -1;
		parent = -1;
	};

};

using Node = struct Node;



/*
FindMin: 返回前k个结点中，parent=-1且权重最小的结点的位置
*/
int FindMin(Node * tree, int k)
{
	int i, min;
	for (i = 0; i < k; i++)
	{
		if (tree[i].parent == -1)
		{
			min = i;
			break;
		}
	}
	for (; i < k; i++)
	{
		if ((tree[i].weight < tree[min].weight)&&(tree[i].parent==-1))
			min = i;
	}
	return min;
}



/*
HfmCreate: 构造Hfm树
输入：权重数组wet, 数组长度n
返回：树
*/
Node * HfmCreate(int * wet, int n)
{
	Node * tree = new Node[2*n-1]();
	int i;
	for (i = 0; i < n; i++)
		tree[i].weight = wet[i];
	for (i; i < 2 * n - 1; i++)
	{
		int min1 = FindMin(tree, i);
		tree[min1].parent = i;
		int min2 = FindMin(tree, i);
		tree[min2].parent = i;

		tree[i].left = min1;
		tree[i].right = min2;	
		tree[i].weight = tree[min1].weight + tree[min2].weight;
	}
#ifdef DEBUG
	std::cout << "各结点信息：" << std::endl;
	for (int i = 0; i < 2 * n - 1; i++)
	{
		std::cout << "权重：" << tree[i].weight << " 左孩子：" << tree[i].left << " 右孩子" << tree[i].right
			<< " 父亲：" << tree[i].parent << std::endl;
	}
#endif
	return tree;
}

void GetHfmCode(Node * tree, int n)
{
	std::stack<int>stack_;
	for (int i = 0; i < n; i++)
	{
		std::cout << tree[i].weight << "权重的结点，HFM编码为： ";
		int temp1 = i, temp2;
		while (tree[temp1].parent != -1)
		{
			temp2 = temp1;
			temp1 = tree[temp1].parent;
			if (tree[temp1].left == temp2)
				stack_.push(0);
			else
				stack_.push(1);
		}
		while (!stack_.empty())
		{
			std::cout << stack_.top() << " ";
			stack_.pop();
		}
		std::cout << std::endl;
	}
	
}