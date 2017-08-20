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


//插入排序 之 希尔排序
void shell_sort(int arr[], int n)
{
	int dk, i, j;
	for (dk = n / 2; dk >= 1; dk--)//增量从n/2逐渐减到1
	{
		//以下为直接插入排序，每组的第一个数默认排好序，所以i从dk+1开始
		for (i = dk + 1; i < n; ++i)
		{
			//如果比前一个元素小，说明需要将当前元素插入前面某个位置
			if (arr[i - dk] > arr[i])
			{
				arr[0] = arr[i];
				for (j = i - dk; arr[0] < arr[j]; j -= dk)
				{
					arr[j + dk] = arr[j];
				}
				arr[j + dk] = arr[0];
			}
		}
	}

	arr_print(arr, n);
}


int main()
{

	int max_num = 100;
	int arr_len = 20;//第一个元素不使用
	int arr_random[100];


	std::cout << "希尔排序：" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	shell_sort(arr_random, arr_len); 
	std::cout << std::endl;


	return 0;
}