//��һ����ά�����У�ÿһ�ж����մ����ҵݹ��˳������
//ÿһ��Ҳ���մ��µ��ϵݹ��˳������
//����һ����ά������������ж��������Ƿ��и�����
#include <iostream>


bool Find(int * matrix, int col, int row, int key)
{
	if (*matrix == NULL || col == NULL || row == NULL)
		return false;

	int cur_row = 0;
	int cur_col = col - 1;
	while (cur_row <= row && cur_col >= 0)
	{
		int * cur = matrix + cur_row*col + cur_col;
		if (*cur == key)
			return true;
		else if (*cur > key)
		{
			--cur_col;
		}
		else
		{
			++cur_row;
		}
	}
	return false;
}


int main()
{
	int matrix[][4] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	int key = 10;
	bool flag = Find(matrix[0], 4, 4, key);
	std::cout <<"find "<<key<<": "<< flag << std::endl;
	return 0;
}