//在一个二维数组中，每一行都按照从左到右递归的顺序排列
//每一列也按照从下到上递归的顺序排列
//输入一个二维数组和整数，判断数组中是否含有该整数
#include <iostream>


bool find(int * start, int * end, int row, int column, int key)
{
	if (start - end > 0)
		return false;
	if (*start == key)
		return true;
	return find(start + 1, end, row, column, key) || find(start + column, end, row, column, key);
}

bool Find(int *matrix, int row, int column, int key)
{
	if (*matrix == key)
		return true;

	int * end = matrix + column*row ;
	int * start = matrix;
	return find(start + 1, end, row, column, key) || find(start + column, end, row, column, key);
}

int main()
{
	int matrix[][4] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	int key = 14;
	bool flag = Find(matrix[0], 4, 4, key);
	std::cout <<"find "<<key<<": "<< flag << std::endl;
	return 0;
}