//数组中只出现一次的数字
//有两个数字只出现了一次，其余出现了2次

#include <iostream>


//返回从右到左，第一次出现1的位置
int FindFirstBitIsOne(int value)
{
	int index = 0;
	while (index < sizeof(int) * 8)
	{
		if (value & 0x1)
			return index;
		++index;
	}
	return -1;
}


//判断指定位置上是否是1
bool IsBitOne(int value, int index)
{
	while (index)
	{
		value >>= 1;
		--index;
	}
	return 0x1 & value;
}




bool GetAppearTwice(int * arr, int len, int & result1, int & result2)
{
	if (arr == NULL || len < 2)
		return false;

	//temp为两个只出现了一次的数字的异或结果
	int temp = arr[0];
	for (int i = 1; i < len; ++i)
		temp ^= arr[i];

	if (temp == 0)
		return false;

	//可以根据异或结果某一位不为1为条件来将数组分成两组
	//如果存在两个只出现了一次的数字，必分配在这两个数组中
	//例如2^5=010^101=111,可以以任一位做区分

	int index_first_one_bit = FindFirstBitIsOne(temp);
	if (index_first_one_bit == -1)
		return false;

	result1 = 0; result2 = 0;//在数组中不会出现0的情况下可以这样；否则如果只出现了一次的数字是0，则无法判断

	for (int i = 0; i < len; ++i)
	{
		if (IsBitOne(arr[i], index_first_one_bit))
		{
			result1 ^= arr[i];
		}
		else
		{
			result2 ^= arr[i];
		}
	}
	if (result1 != 0 & result2 != 0)
		return true;

	return false;
}


int main()
{
	using namespace std;
	int arr[] = {1,2,3,4,5,1,2,5};
	int result1, result2;
	if (GetAppearTwice(arr, sizeof(arr)/sizeof(arr[0]), result1, result2))
		cout << "number :" << result1 << ",another number :" << result2 << endl;
	
	return 0;
}