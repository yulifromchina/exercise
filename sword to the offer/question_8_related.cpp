//旋转数组的最小数字
//输入数组为递增排序的数组的旋转
//例如：3 4 5 1 2
//例如：1 0 1 1 1

#include <iostream>

//顺序查找最小元素，时间复杂度O(n)
int sequenceFind(int * arr, size_t len)
{
	if(arr==NULL || len <= 0)
		throw new std::exception("Invalud parameters");
	int result = arr[0];
	for (int i = 1; i < len; ++i)
		if (arr[i] < result)
			result = arr[i];

	return result;
}



//二分法查找最小元素，最优时间复杂度为O(log2N)
int getMin(int * arr, size_t len)
{
	if (arr == NULL || len <= 0)
		throw new std::exception("Invalud parameters");

	if (len == 1)
		return arr[0];

	int low = 0, high = len - 1;
	int mid = 0;
	while (arr[high] <= arr[low])//不使用low < high跳出循环，是因为不能处理升序的情况
	{
		//两个指针相邻，则后一个为最小值
		if (high - low == 1)
			return arr[high];

		mid = low + (high - low) / 2;

		//三个元素相同的情况，只能使用顺序查找
		if (arr[mid] == arr[low] && arr[mid] == arr[high])
			return sequenceFind(arr, len);

		if (arr[mid] >= arr[low])
			low = mid;
		else
			high = mid;
	}

	return arr[mid];
}

int main()
{
	using namespace std;
	//test case : 3 4 5 1 2
	int arr1[] = {3,4,5,1,2};
	cout << "min:" << getMin(arr1, sizeof(arr1)/sizeof(int)) << endl;

	//test case : 1 0 1 1 1
	int arr2[] = { 1,0,1,1,1 };
	cout << "min:" << getMin(arr2, sizeof(arr2) / sizeof(int)) << endl;

	//test case : 1 2 3 4 5
	int arr3[] = { 1,2,3,4,5 };
	cout << "min:" << getMin(arr3, sizeof(arr3) / sizeof(int)) << endl;

	//test case : 2 1
	int arr4[] = { 2,1 };
	cout << "min:" << getMin(arr4, sizeof(arr4) / sizeof(int)) << endl;

	//test case : 1
	int arr5[] = { 1};
	cout << "min:" << getMin(arr5, sizeof(arr5) / sizeof(int)) << endl;
	return 0;
}