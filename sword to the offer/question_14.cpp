//调整数组顺序使奇数位于偶数前面

#include <iostream>

using namespace std;

void Reorder(int * data, size_t len, bool(*func)(int))
{
	if (data == NULL || len <= 0)
		return;

	int low = 0, high = len - 1;
	while (low < high)
	{
		while (low < high && func(data[high])) --high;
		while (low < high && !func(data[low])) ++low;
		
		if (low < high)
		{
			int temp = data[low];
			data[low] = data[high];
			data[high] = temp;
		}
	}
}

bool isEven(int num)
{
	return num % 2 == 0;
}

void print(int * data, size_t len)
{
	cout << "arr: (";
	for (int i = 0; i < len; ++i)
		cout << data[i] << " ";
	cout <<")"<< endl;
}

int main()
{
	//test case 1: 1 2 3 4 5 6
	int arr1[] = {1,2,3,4,5,6};
	Reorder(arr1, sizeof(arr1)/sizeof(int), isEven);
	print(arr1, sizeof(arr1) / sizeof(int));

	//test case 2: 1 2 3 4 5
	int arr2[] = {1,2,3,4,5};
	Reorder(arr2, sizeof(arr2) / sizeof(int), isEven);
	print(arr2, sizeof(arr2) / sizeof(int));

	//test case 3: 1
	int arr3[] = { 1 };
	Reorder(arr3, sizeof(arr3) / sizeof(int), isEven);
	print(arr3, sizeof(arr3) / sizeof(int));

	//test case 4: 1 3 5 7 9
	int arr4[] = {1,3,5,7,9};
	Reorder(arr4, sizeof(arr4) / sizeof(int), isEven);
	print(arr4, sizeof(arr4) / sizeof(int));

	return 0;
}