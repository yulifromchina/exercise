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

void swap(int * a1, int * a2)
{
	if (*a1 == *a2)
		return;
	*a1 = *a1 ^ *a2;
	*a2 = *a1 ^ *a2;
	*a1 = *a1 ^ *a2;
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


//��ѡ������
void selection_sort(int arr[], int n)
{
	for (int i = 1; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[min] > arr[j]) min = j;
		}
		if (min != i)
			swap(&arr[min], &arr[i]);
	}

	arr_print(arr, n);
}



int main()
{

	int max_num = 100;
	int arr_len = 20;//��һ��Ԫ�ز�ʹ��
	int arr_random[100];


	std::cout << "ѡ������" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	selection_sort(arr_random, arr_len); 
	std::cout << std::endl;


	return 0;
}