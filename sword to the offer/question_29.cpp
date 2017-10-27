//�����г��ִ�������һ�������
//����һ������Ϊ9������{1,2,3,2,2,2��5,4,2}�����2


#include <iostream>
#include <random>

using namespace std;

//swap����
void Swap(int * a, int * b)
{
	if (*a == *b)
		return;

	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

//һ�˿�������
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

//���������ݽ��м�飬�����λ���ϵ���û�е���len/2��˵���������ݲ�����Ҫ��
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


//ͨ����������λ��
int MoreThanHalf(int arr[], int len)
{
	if (arr == NULL || len <= 0)
		return -1;

	int middle = len >> 1;
	int low = 0;
	int high = len - 1;
	int index = Partition(arr, low, high);

	//һ�˿��ŷ���indexλ�õ�����
	while (index != middle)
	{
		//index��middle��˵��Ӧ�õ��������λ��
		if (index > middle)
		{
			high = index - 1;
			index = Partition(arr, low, high);
		}
		else
		{
			//index��middleС��˵��Ӧ�õ��ұ�����λ��
			low = index + 1;
			index = Partition(arr, low, high);
		}
	}
	int result = arr[middle];

	//����Ƿ������������Ƶ�ʵ�����Ҳ�������鳤��1/2
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



