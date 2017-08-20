#include <iostream>
#include <ctime>
#include <random>

void arr_print(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void get_random_sequence(int arr[], int n, int  max)
{
	std::default_random_engine e(time(0));//���棬��������unsigned�������
	std::uniform_int_distribution<unsigned> u(0, max);//����[0,max]�ھ��ȷֲ�����
													  //arr[0]��ʹ��
	for (int i = 1; i < n; i++)
	{
		arr[i] = u(e);
	}
	std::cout << "������У�" << std::endl;
	arr_print(arr, n);
}


//�������� ֮ �۰��������

void binary_sort(int arr[], int n)
{
	int i, j, low, high, mid;
	for (i = 2; i < n; ++i)
	{
		arr[0] = arr[i];
		low = 1;
		high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (arr[mid] > arr[0]) high = mid - 1;
			else low = mid + 1;
		}
		for (j = i - 1; j > high; --j)
		{
			arr[j + 1] = arr[j];
		}
		arr[high + 1] = arr[0];
	}

	arr_print(arr, n);
}

int main()
{

	int max_num = 100;
	int arr_len = 20;//��һ��Ԫ�ز�ʹ��
	int arr_random[100];

	get_random_sequence(arr_random, arr_len, max_num); 
	binary_sort(arr_random, arr_len); 
	std::cout << std::endl;
	return 0;
}