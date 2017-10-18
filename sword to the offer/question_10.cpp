//一个数二进制中位为1的个数
#include <iostream>

int numberOfOne(int n)
{
	int count = 0;
	int i = sizeof(n) * 8;
	while (i)
	{
		count += n & 0x1;
		n >>= 1;
		--i;
	}
	return count;
}

int main()
{
	using namespace std;
	int n = 9;
	cout << "n=" << n << ":" << numberOfOne(n) << endl;

	n = 0;
	cout << "n=" << n << ":" << numberOfOne(n) << endl;

	n =-1;
	cout << "n=" << n << ":" << numberOfOne(n) << endl;
	return 0;
}