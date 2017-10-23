//����һ���������飬�жϸ������Ƿ���ĳ�����������ĺ�����������

#include <iostream>

bool VerifySequenceOfBST(int * sequence , int len)
{
	if (sequence == NULL || len <= 0)
		return false;

	//��������������������������Է�Ϊ3����
	//��һ����ֵ��С�ڸ����
	//�ڶ�����ֵ�����ڸ����
	//�������ּ����һ��Ԫ�أ�Ϊ�����

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
	//�ݹ��ж�������
	bool left = true;
	if (i)
		left = VerifySequenceOfBST(sequence, i);

	//�ݹ��ж�������
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