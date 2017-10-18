//动态规划求fibonacci数列

#include <iostream>

int fibonacci(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	int pre1 = 1, pre2 = 1, pre3;
	for (int i = 3; i <= n; ++i)
	{
		pre3 = pre1 + pre2;
		pre1 = pre2;
		pre2 = pre3;
	}
	return pre3;
}
int main()
{
	using namespace std;
	int n = 3;
	cout << "n="<<n<<" :"<<fibonacci(n) << endl;
	n = 4;
	cout << "n=" << n << " :" << fibonacci(n) << endl;
	n = 5;
	cout << "n=" << n << " :" << fibonacci(n) << endl;
	n = 6;
	cout << "n=" << n << " :" << fibonacci(n) << endl;
	n = 7;
	cout << "n=" << n << " :" << fibonacci(n) << endl;
	return 0;
}