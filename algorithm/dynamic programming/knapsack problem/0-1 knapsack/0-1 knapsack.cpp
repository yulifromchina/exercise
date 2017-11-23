#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//递归的方式
//自上而下，时间复杂度O(n^2),空间复杂度O(1)
//存在重复的计算
int knapSack(int capacity, vector<int> & weight, vector<int> & value, int n)
{
	if (capacity == 0 || n == 0)
		return 0;

	//如果第n个物品的重量大于背包容量，则不能被放进去
	if (weight[n - 1] > capacity)
		return knapSack(capacity, weight, value, n - 1);

	//1) 放入第n个物品
	//2）不放入第n个物品
	else
		return max(value[n-1] + knapSack(capacity - weight[n-1], weight, value, n-1), 
			knapSack(capacity, weight, value, n-1));
}


//动态规划的方式
//时间复杂度O(n * capacity)，空间复杂度O(n* capacity)
//自下而上
//用空间换时间
int knapSack_dp(int capacity, vector<int> & weight, vector<int> & value, int n)
{
	if (capacity == 0 || n == 0)
		return 0;
	vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= capacity; ++j)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;//在初始化dp时已经置零，这里写出来展现思路
			else if (weight[i - 1] <= j)
				dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][capacity];
}

//降维，dp使用一维数组
int knapSack_dp_opt(int capacity, vector<int> & weight, vector<int> & value, int n)
{
	if (capacity == 0 || n == 0)
		return 0;
	vector<int> dp(capacity+1, 0);
	for(int i=1;i<n;++i)
		for (int j = capacity; j >= 0; --j)
		{
			if (weight[i - 1] <= j)
				dp[j] = max(dp[j-weight[i-1]]+value[i-1], dp[j]);
			//否则，不更新dp[j]
		}
	return dp[capacity];
}

int main()
{
	int capacity = 100;
	vector<int> weight = {77,22,29,50,99};
	vector<int> value = {92,22,87,46,90};
	cout << "test knapSack:";
	int total_value = knapSack(capacity, weight, value, 5);
	cout << total_value << endl;

	cout << "test knapSack_dp:";
	total_value = knapSack_dp(capacity, weight, value, 5);
	cout << total_value << endl;

	cout << "test knapSack_dp_opt:";
	total_value = knapSack_dp_opt(capacity, weight, value, 5);
	cout << total_value << endl;
	return 0;
}