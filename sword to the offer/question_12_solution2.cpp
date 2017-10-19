//打印1到n的整数
//大数问题

//使用全排列
#include <iostream>

using namespace std;


//打印单个数字
void printSingle(int * num, int len)
{
	int index = 0;
	while (num[index] == 0)
		++index;
	while (index < len)
	{
		cout << num[index];
		++index;
	}
	cout << endl;
}

//递归打印
void RecurionPrint(int * num, int len, int index)
{
	if (index == len)
	{
		printSingle(num, len);
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		num[index] = i;
		RecurionPrint(num, len, index + 1);
	}
}

//大数打印
void printToMaxN(int n)
{
	if (n < 0)
		return;

	int * num = new int[n]();
	if (num == NULL)
		exit(EXIT_FAILURE);

	RecurionPrint(num, n, 0);
	delete[] num;
}

int main()
{
	int n;
	cin >> n;
	//test 0 1 2
	printToMaxN(n);
	return 0;
}