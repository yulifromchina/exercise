//丑数
//只包含因子2,3,5的数字成为丑数。例如6,8是丑数，14不是，因为包含因子7.
//求按从小到大的顺序的第1500个丑数

//算法核心：对于一个按升序排好序的丑数序列，下一个丑数一定是前面某个丑数*2或*3或*5的到的
//不需要将最大丑数前面的所有丑数都乘以2,3,5
//例如，对*2而言，存在一个临界丑数，在这个丑数之前的丑数*2,结果都小于当前最大丑数；
//在这个丑数之后的丑数*2,结果都大于当前最大丑数；
//所以只用记录下这个丑数的位置，每次生成新的最大丑数后，更新这个位置

#include <iostream>

using namespace std;


//取得三者中的最小值
int Min(int a, int b, int c)
{
	int min_num = a > b ? b : a;
	return min_num > c ? c : min_num;
}


//取得第index位的丑数
int GetUgly(int index)
{
	int * ugly_arr = new int[index]();
	if (ugly_arr == NULL)
		throw new exception("Allocate Error");

	ugly_arr[0] = 1;//1是第一个丑数
	int * mul2_index = ugly_arr;
	int * mul3_index = ugly_arr;
	int * mul5_index = ugly_arr;
	int next_ugly = 1;

	while (next_ugly < index)
	{
		int temp = Min(*mul2_index * 2, *mul3_index*3, *mul5_index*5);
		ugly_arr[next_ugly] = temp;

		while (*mul2_index * 2 <= temp) ++mul2_index;
		while (*mul3_index * 3 <= temp) ++mul3_index;
		while (*mul5_index * 5 <= temp) ++mul5_index;

		++next_ugly;
	}

	int result = ugly_arr[next_ugly - 1];
	delete[] ugly_arr;
	return result;

}

int main()
{
	cout << GetUgly(1500) << endl;
	return 0;
}