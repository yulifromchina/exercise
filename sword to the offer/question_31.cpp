//连续子数组的最大和
//输入一个包含正负数的整形数组，数组中一个或多个连续的数字组成数组，求所有子数组和的最大值

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//动态规划
int MaxSub(vector<int> & data)
{
	if (data.empty())
		throw new exception("Invalid Parameter.");

	int len = data.size();
	if (len == 1)
		return data[0];

	int start = 0, end = 0;//记录最大子数组的起始和结束下标
	int max_sub = 0;//最大子数组和
	vector<int>dp; //动态规划数组

	dp.push_back(data[0]);
	max_sub = data[0];

	int temp;
	for (int i = 1; i < len; ++i)
	{
		//如果前面的子数组和小于等于0，则直接丢弃
		if (dp[i - 1] <= 0)
		{
			dp.push_back(data[i]);
			temp = i;//标记起始位置
		}
		else
			dp.push_back(data[i] + dp[i - 1]);

		if (dp[i] > max_sub)
		{
			max_sub = dp[i];
			start = temp;
			end = i;
		}
	}
	cout << "最大子序列：（";
	for (int i = start; i <= end; ++i)
		cout << data[i] << ",";
	cout << ")" << endl;
	return max_sub;
}

int main()
{
	vector<int> data = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	int result = MaxSub(data);
	cout << result << endl;
	return 0;
}