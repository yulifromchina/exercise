//��һ����ά�����У�ÿһ�ж����մ����ҵݹ��˳������
//ÿһ��Ҳ���մ��µ��ϵݹ��˳������
//����һ����ά������������ж��������Ƿ��и�����
#include <iostream>


bool Find(int *matrix, int row, int column, int key)
{
	int * end = matrix + column*row ;
	int * start = matrix;
	while (start != end)
	{
		if (*start == key)
			return true;
		start++;
	}
	return false;
}

int main()
{
	int matrix[][4] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	int key = 1;
	bool flag = Find(matrix[0], 4, 4, key);
	std::cout <<"find "<<key<<": "<< flag << std::endl;
	return 0;
}