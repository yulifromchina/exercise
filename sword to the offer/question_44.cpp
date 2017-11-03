//�˿����е�˳��

//���0-13��5���ƣ��ж��ǲ���˳�ӣ�0���Գ䵱�κ���

#include <iostream>

using namespace std;

int Compare(const void * a, const void * b)
{
	return *(int *)a > *(int *)b;
}

bool IsContinous(int * arr, int len)
{
	if (arr == NULL || len <= 0)
		return false;
	//������������
	qsort(arr, len, sizeof(int), Compare);

	//ͳ��0�ĸ���
	int count_0 = 0;
	int i = 0;
	for (; i < len; ++i)
	{
		if (arr[i] == 0)
			++count_0;
		else
			break;
	}

	//ȫ��0����˳��
	if (i == len)
		return true;

	//ͳ�Ʋ�ֵ
	int gap = 0;
	for (i=count_0; i < len-1; ++i)
	{
		//������ͬ��ֵ������˳��
		if (arr[i + 1] == arr[i])
			return false;
		gap += arr[i + 1] - arr[i];
	}
	if(gap <=count_0 || gap==4)
		return true;

	return false;
}

int main()
{
	int arr1[] = {0,0,0,0,0};
	cout << "expect 1, actually :" << IsContinous(arr1, 5) << endl;
	int arr2[] = { 5,4,1,2,3 };
	cout << "expect 1, actually :" << IsContinous(arr2, 5) << endl;
	int arr3[] = {6,5,9,0,4};
	cout << "expect 0, actually :" << IsContinous(arr3, 5) << endl;
	int arr4[] = { 7,8,9,5,0 };
	cout << "expect 1, actually :" << IsContinous(arr4, 5) << endl;
	int arr5[] = {1,3,4,5,6};
	cout << "expect 0, actually :" << IsContinous(arr5, 5) << endl;
	int arr6[] = { 1,3,3,4,5 };
	cout << "expect 0, actually :" << IsContinous(arr6, 5) << endl;
	return 0;
}