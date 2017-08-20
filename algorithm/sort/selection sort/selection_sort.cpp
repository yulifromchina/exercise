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
	std::default_random_engine e(time(0));//引擎，用于生成unsigned随机整数
	std::uniform_int_distribution<unsigned> u(0, max);//生成[0,max]内均匀分布的数
													  //arr[0]不使用
	for (int i = 1; i < n; i++)
	{
		arr[i] = u(e);
	}
	std::cout << "随机序列：" << std::endl;
	arr_print(arr, n);
}


//简单选择排序
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
	int arr_len = 20;//第一个元素不使用
	int arr_random[100];


	std::cout << "选择排序：" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	selection_sort(arr_random, arr_len); 
	std::cout << std::endl;


	return 0;
}