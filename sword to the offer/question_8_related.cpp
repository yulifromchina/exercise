//��ת�������С����
//��������Ϊ����������������ת
//���磺3 4 5 1 2
//���磺1 0 1 1 1

#include <iostream>

//˳�������СԪ�أ�ʱ�临�Ӷ�O(n)
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



//���ַ�������СԪ�أ�����ʱ�临�Ӷ�ΪO(log2N)
int getMin(int * arr, size_t len)
{
	if (arr == NULL || len <= 0)
		throw new std::exception("Invalud parameters");

	if (len == 1)
		return arr[0];

	int low = 0, high = len - 1;
	int mid = 0;
	while (arr[high] <= arr[low])//��ʹ��low < high����ѭ��������Ϊ���ܴ�����������
	{
		//����ָ�����ڣ����һ��Ϊ��Сֵ
		if (high - low == 1)
			return arr[high];

		mid = low + (high - low) / 2;

		//����Ԫ����ͬ�������ֻ��ʹ��˳�����
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