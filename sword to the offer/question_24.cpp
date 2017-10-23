//输入一个整数数组，判断该数组是否是某二叉搜索树的后续遍历序列

#include <iostream>

bool VerifySequenceOfBST(int * sequence , int len)
{
	if (sequence == NULL || len <= 0)
		return false;

	//后续遍历二叉搜索树，数组可以分为3部分
	//第一部分值均小于根结点
	//第二部分值均大于根结点
	//第三部分即最后一个元素，为根结点

	int root = sequence[len -1];
	int i = 0;
	for (; i < len - 1; ++i)
	{
		if (sequence[i] > root)
			break;
	}
	int j = i;
	for (; j < len - 1; ++j)
	{
		if (sequence[j] < root)
			return false;
	}
	//递归判断左子树
	bool left = true;
	if (i)
		left = VerifySequenceOfBST(sequence, i);

	//递归判断右子树
	bool right = true;
	if (j > i)
		right = VerifySequenceOfBST(sequence + i, len -i-1);

	return left && right;
}

int main()
{
	using namespace std;

	//test case 1
	int seq1[] = { 1 };
	cout << VerifySequenceOfBST(seq1, 1)<<endl;

	//test case 2
	int seq2[] = {7,4,6,5};
	cout << VerifySequenceOfBST(seq2, 4) << endl;

	//test case 3
	int seq3[] = {5,7,6,9,11,10,8};
	cout << VerifySequenceOfBST(seq3, 7) << endl;
	return 0;
}