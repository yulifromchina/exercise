//打印1到n的整数
//大数问题
#include <iostream>

using namespace std;

//打印大数
void printNum(int * num, int len)
{
	int * ptr = num, i = 0;
	while (*ptr == 0)
	{
		++ptr;
		++i;
	}
	for (; i < len; ++i)
		cout << num[i];
	cout << endl;
}


//大数加法，每次加1
bool Increment(int * num, int len)
{
	bool isOverFlow = false;
	
	num[len - 1]++;
	for (int i = len - 1; i >= 0; --i)
	{
		if (num[i] == 10)
		{
			//最高位加上进位>=10,说明之前已经到达了99..99
			if (i == 0)
			{
				isOverFlow = true;
				break;
			}
			else
			{
				num[i] -= 10;
				++num[i - 1];
			}
		}
	}
	return isOverFlow;
}


//打印大数，从1到n
void printToMaxN(int n)
{
	if (n < 0)
		return;

	int * num = new int[n]();
	if (num == NULL)
		exit(EXIT_FAILURE);

	while (!Increment(num, n))
		printNum(num,n);

	delete[] num;
	num = NULL;
}

int main()
{
	int n;
	cin >> n;
	printToMaxN(n);
	return 0;
}