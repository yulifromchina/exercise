//数字在排序数组中出现的次数
//例如输入排序数组{1,2,3,3,3,3,4,5}，输入3，由于3出现了4次，所以输出4

//算法核心：利用二分查找找到第一个和最后一个指定的数，两者相减，就是指定数出现的次数

#include <iostream>


//寻找第一个出现的k
int GetFirst(int * arr, int k, int low, int high)
{
	if (arr == NULL || low > high)
		return -1;

	while (low <= high)
	{
		int mid = (low + high) >> 1;
		//如果arr[mid]=k
		if (arr[mid] == k)
		{
			//如果当前是第一个k
			if (mid == 0 || (mid > 0 && arr[mid - 1] < k))
				return mid;
			//如果当前不是第一个k
			else
				high = mid - 1;
		}
		//如果arr[mid]<k,则在后半段找第一个k
		else if(arr[mid]<k)
		{
			low = mid + 1;
		}
		//如果arr[mid]>k,则在前半段找第一个k
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}


//寻找最后一个出现的k
int GetLast(int * arr, int k, int len,  int low, int high)
{

	if (arr == NULL || low > high)
		return -1;

	while (low <= high)
	{
		int mid = (low + high) >> 1;
		//如果arr[mid]=k
		if (arr[mid] == k)
		{
			//如果当前是最后一个k
			if (mid == len - 1 || (mid < len - 1 && arr[mid + 1] >k))
				return mid;
			//如果当前不是最后一个k
			else
				low = mid + 1;
		}
		//如果arr[mid]<k,则在后半段找第一个k
		else if (arr[mid]<k)
		{
			low = mid + 1;
		}
		//如果arr[mid]>k,则在前半段找第一个k
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}


int GetNumber(int * arr, int len, int k)
{
	if (arr == NULL || len <= 0)
		return -1;

	int first = GetFirst(arr, k, 0, len -1);
	int last = GetLast(arr, k, len, 0, len-1);
	if (first != -1 && last != -1)
		return last - first + 1;
	return 0;
}


int main()
{
	using namespace std;
	int arr[] = {1,2,3,4,4,4,4,5};
	cout << "except 4, actually " << GetNumber(arr, sizeof(arr) / sizeof(arr[0]), 4) << endl;
	int arr1[] = { 1,2,3,4,5 };
	cout << "except 1, actually " << GetNumber(arr1, sizeof(arr1) / sizeof(arr1[0]), 4) << endl;
	int arr2[] = { 1,2,3,4,5 };
	cout << "except 0, actually " << GetNumber(arr2, sizeof(arr2) / sizeof(arr2[0]), 40) << endl;
	return 0;
}