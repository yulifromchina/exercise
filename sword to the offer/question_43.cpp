//n个骰子的点数
//把n个骰子扔在地上，所有骰子朝上一面的点数之和为s,输入n，打印所有的s可能出现的值的概率

//核心：动态规划
//当有k-1个骰子，再增加一个骰子，这个骰子投出的点数只能是1，2,3,4,5,6
//所以k个骰子和n为的情况,分别对应k-1个骰子投出了n-6,n-5,n-4,n-3,n-2,n-1
//f(k,n) = f(k-1,n-1)+f(k-1,n-2)+f(k-1,n-3)+f(k-1,n-4)+f(k-1,n-5)+f(k-1,n-6)
//f(1,1)=f(1,2)=f(1,3)=f(1,4)=f(1,5)=f(1,6)=1

#include <iostream>


//计算n个骰子投掷和为s的可能组合总数
int CountNumber(int n, int s)
{
	//n个骰子的投掷点数在n~6*n之间
	if (s < n || s>6 * n)
		return 0;


	//只有一个骰子，则投掷出s只有一种可能
	if (n == 1)
		return 1;
	
	return CountNumber(n - 1, s - 1) + CountNumber(n - 1, s - 2) + CountNumber(n - 1, s - 3) + CountNumber(n - 1, s - 4) + CountNumber(n - 1, s - 5) + CountNumber(n - 1, s - 6);
}


//计算概率
void CalculatePossibility(int n)
{
	for (int i = n; i <= 6 * n; ++i)
	{
		int number = CountNumber(n, i);
		std::cout << n << " 个骰子投掷出 " << i << " 的概率为：" << number << " / " << pow(6, n) << std::endl;
	}
}


int main()
{
	using namespace std;
	CalculatePossibility(3);
	return 0;
}