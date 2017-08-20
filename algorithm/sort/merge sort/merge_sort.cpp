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


//�鲢����

void merge(int arr[], int low, int mid, int high)
{
	int * temp = new int[high + 1];
	int i, j, k;
	for (i = low, j = mid + 1, k = low; i <= mid&&j <= high; k++)
	{
		if (arr[i] <= arr[j])
		{
			temp[k] = arr[i];
			i++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
		}
	}
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= high) temp[k++] = arr[j++];

	for (i = low; i <= high; i++)
	{
		arr[i] = temp[i];
	}

	delete temp;

}

void merge_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}


int main()
{

	int max_num = 100;
	int arr_len = 20;//��һ��Ԫ�ز�ʹ��
	int arr_random[100];



	std::cout << "�鲢����" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	merge_sort(arr_random, 1, arr_len - 1); 
	arr_print(arr_random, arr_len); 
	std::cout << std::endl;

	return 0;
}