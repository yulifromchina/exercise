//���������е������

//�㷨���ģ��鲢��
//ͳ�ƹ鲢������������������������
//���Ϻϲ�ʱ��������������������ظ�ͳ�ƣ���Ҫ������������
//

#include <iostream>
using namespace std;


//����ϲ����̲����������
int MergePairBetweenArray(int * arr, int * brr, int start, int mid, int end)
{
	int index_left = mid;
	int index_right = end;
	int index_brr = end;
	int count = 0;
	while (index_left >= start && index_right >= mid + 1)
	{
		if (arr[index_left] > arr[index_right])
		{
			count += index_right - mid;//����arr����������õ����飬������ߵ�ĳһλ�����ұߵ�ĳһλ����ô�������ұߵ�ȫ��
			brr[index_brr--] = arr[index_left--];
		}
		else
		{
			brr[index_brr--] = arr[index_right--];
		}
	}
	while(index_left >= start)
		brr[index_brr--] = arr[index_left--];
	while(index_right >= mid + 1)
		brr[index_brr--] = arr[index_right--];

	//����������brr������arr,ʹ֮����
	for (int i = end; i > index_brr; --i)
		arr[i] = brr[i];

	return count;

}


//����鲢�ͺϲ��������
int CountMergePairs(int * arr, int * brr, int start, int end)
{
	int pair_num = 0;
	if (start < end)
	{
		int mid = (start + end) >> 1;
		pair_num += CountMergePairs(arr, brr, start, mid);
		pair_num += CountMergePairs(arr, brr, mid+1, end);
		pair_num += MergePairBetweenArray(arr, brr, start, mid, end);
	}
	return pair_num;
}

//��װ����
int CountTotalPairs(int * arr, int len)
{
	if (arr == NULL || len <= 0)
		return 0;

	int * brr = new int[len];
	for (int i = 0; i < len; ++i)
		brr[i] = arr[i];

	int sum = CountMergePairs(arr, brr, 0, len -1);
	delete[] brr;
	brr = NULL;
	return sum;
}

int main()
{
	int arr[] = {1,2,3,4,5};
	cout << "except 0, actually:" << CountTotalPairs(arr, sizeof(arr) / sizeof(arr[0])) << endl;
	int arr1[] = {5,4,3,2,1};
	cout << "except 10, actually:" << CountTotalPairs(arr1, sizeof(arr1) / sizeof(arr1[0])) << endl;
	int arr2[] = { 5,4,3,3,1 };
	cout << "except 9, actually:" << CountTotalPairs(arr2, sizeof(arr2) / sizeof(arr2[0])) << endl;
	int arr3[] = { 5,3,3,3,1 };
	cout << "except 7, actually:" << CountTotalPairs(arr3, sizeof(arr3) / sizeof(arr3[0])) << endl;
	int arr5[] = { 1 };
	cout << "except 0, actually:" << CountTotalPairs(arr5, sizeof(arr5) / sizeof(arr5[0])) << endl;
	int arr6[] = { 2,1 };
	cout << "except 1, actually:" << CountTotalPairs(arr6, sizeof(arr6) / sizeof(arr6[0])) << endl;
	int * arr7 = NULL;
	cout << "except 0, actually:" << CountTotalPairs(arr7, 3) << endl;
	return 0;
}