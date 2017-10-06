//在一个二维数组中，每一行都按照从左到右递归的顺序排列
//每一列也按照从下到上递归的顺序排列
//输入一个二维数组和整数，判断数组中是否含有该整数
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