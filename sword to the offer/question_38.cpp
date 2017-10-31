//���������������г��ֵĴ���
//����������������{1,2,3,3,3,3,4,5}������3������3������4�Σ��������4

//�㷨���ģ����ö��ֲ����ҵ���һ�������һ��ָ���������������������ָ�������ֵĴ���

#include <iostream>


//Ѱ�ҵ�һ�����ֵ�k
int GetFirst(int * arr, int k, int low, int high)
{
	if (arr == NULL || low > high)
		return -1;

	while (low <= high)
	{
		int mid = (low + high) >> 1;
		//���arr[mid]=k
		if (arr[mid] == k)
		{
			//�����ǰ�ǵ�һ��k
			if (mid == 0 || (mid > 0 && arr[mid - 1] < k))
				return mid;
			//�����ǰ���ǵ�һ��k
			else
				high = mid - 1;
		}
		//���arr[mid]<k,���ں����ҵ�һ��k
		else if(arr[mid]<k)
		{
			low = mid + 1;
		}
		//���arr[mid]>k,����ǰ����ҵ�һ��k
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}


//Ѱ�����һ�����ֵ�k
int GetLast(int * arr, int k, int len,  int low, int high)
{

	if (arr == NULL || low > high)
		return -1;

	while (low <= high)
	{
		int mid = (low + high) >> 1;
		//���arr[mid]=k
		if (arr[mid] == k)
		{
			//�����ǰ�����һ��k
			if (mid == len - 1 || (mid < len - 1 && arr[mid + 1] >k))
				return mid;
			//�����ǰ�������һ��k
			else
				low = mid + 1;
		}
		//���arr[mid]<k,���ں����ҵ�һ��k
		else if (arr[mid]<k)
		{
			low = mid + 1;
		}
		//���arr[mid]>k,����ǰ����ҵ�һ��k
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