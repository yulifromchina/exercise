//圆圈剩下的最后数字
//题目：0,1...n-1这n个数字排成一个圆圈，从数字开始每次从这个圆圈删除第m个数字，求圆圈里剩下的数字


//核心：递推公式：f(n,m) = 0,n=1时，
//f(n,m) = [f(n-1,m)+m]%n ,n >1时
#include <iostream>

int GetLast(int n, int m)
{
	if (m <= 0 || n<1)
		return -1;

	int last = 0;
	for (int i = 2; i <= n; ++i)
	{
		last = (last + m) % i;
	}
	return last;
}

int main()
{
	using namespace std;
	cout << GetLast(13,3) << endl;
}