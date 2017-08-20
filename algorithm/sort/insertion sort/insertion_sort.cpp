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


//插入排序 之 直接插入排序

void insertion_sort(int arr[], int n)
{
	int i, j;
	for (i = 2; i < n; i++)//arr[i]认为已经排好序
	{
		if (arr[i] < arr[i - 1])//如果比前一个元素小，说明需要将当前元素插入前面某个位置
		{
			arr[0] = arr[i];
			for (j = i - 1; arr[0] < arr[j]; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = arr[0];

			//不使用哨兵：
			/*int temp = arr[i];
			for (j = i - 1; temp < arr[j] && j>= 1; j--)
			{
			arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;*/
		}
	}

	arr_print(arr, n);
}


int main()
{

	int max_num = 100;
	int arr_len = 20;//第一个元素不使用
	int arr_random[100];

	std::cout << "直接插入排序：" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	insertion_sort(arr_random, arr_len);
	std::cout << std::endl;




	return 0;
}