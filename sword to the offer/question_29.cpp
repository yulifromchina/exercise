//数组中出现次数超过一半的数字
//例如一个长度为9的数组{1,2,3,2,2,2，5,4,2}，输出2


#include <iostream>
#include <random>

using namespace std;

//swap函数
void Swap(int * a, int * b)
{
	if (*a == *b)
		return;

	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

//一趟快速排序
int Partition(int arr[], int low, int high)
{
	int random = low + rand() % (high - low + 1);
	Swap(&arr[random], &arr[low]);

	int pivot = arr[low];
	while (low < high)
	{
		while (low < high && arr[high] >= pivot) --high;
		arr[low] = arr[high];
		while (low < high && arr[low] <= pivot) ++low;
		arr[high] = arr[low];
	}
	arr[high] = pivot;
	return high;

}

//对输入数据进行检查，如果中位数上的数没有到达len/2，说明输入数据不符合要求
bool ChencInput(int arr[], int len, int middle)
{
	int count = 0;
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] == middle)
			++count;
	}
	if (count * 2 < len)
		return false;
	return true;
}


//通过快排找中位数
int MoreThanHalf(int arr[], int len)
{
	if (arr == NULL || len <= 0)
		return -1;

	int middle = len >> 1;
	int low = 0;
	int high = len - 1;
	int index = Partition(arr, low, high);

	//一趟快排放置index位置的数据
	while (index != middle)
	{
		//index比middle大，说明应该到左边找中位数
		if (index > middle)
		{
			high = index - 1;
			index = Partition(arr, low, high);
		}
		else
		{
			//index比middle小，说明应该到右边找中位数
			low = index + 1;
			index = Partition(arr, low, high);
		}
	}
	int result = arr[middle];

	//检查是否输入数据最高频率的数字也不到数组长度1/2
	if (!ChencInput(arr, len, result))
		result = -1;
	
	return result;
}

int main()
{

	//test case 1:
	int arr1[] = { 1,2,3,2,2,2,5,4,2 };
	cout << MoreThanHalf(arr1, sizeof(arr1) / sizeof(arr1[0])) << endl;
	//test case 2:
	int arr2[] = { 1,2,3 };
	cout << MoreThanHalf(arr2, sizeof(arr2) / sizeof(arr2[0])) << endl;
	//test case 3:
	int arr3[] = { 1 };
	cout << MoreThanHalf(arr3, sizeof(arr3) / sizeof(arr3[0])) << endl;

	return 0;
}



