#include <iostream>
#include <ctime>
#include <random>
#include <cassert>

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

//计数排序
//按定义实现
void count_sort_1(int arr[], int n)
{
	//存放结果的数组
	int * C = new int[n]();
	assert(C != NULL);

	//中间数组
	//先找出arr中最大的数
	int max = 1;
	for (int i = 2; i < n; i++)
	{
		if (arr[max] < arr[i])
			max = i;
	}
	int * B = new int[arr[max] + 1]();
	assert(B != NULL);

	//把arr中元素出现的个数统计到B中
	for (int i = 1; i < n; i++)
		B[arr[i]] += 1;
	//B中每个元素=前面元素的和+当前元素
	for (int i = 2; i < arr[max] + 1; i++)
	{
		B[i] += B[i - 1];
	}

	//根据中间数组B，把arr的元素排序到C中
	for (int i = n - 1; i > 0; --i)
	{
		int index = B[arr[i]];
		C[index] = arr[i];
		B[arr[i]]--;
	}
	//最后把结果复制到arr中
	for (int i = 1; i < n; i++)
	{
		arr[i] = C[i];
	}

	delete C;
	delete B;

	arr_print(arr, n);
}


int main()
{

	int max_num = 100;
	int arr_len = 20;//第一个元素不使用
	int arr_random[100];

	std::cout << "计数排序：" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	count_sort_1(arr_random, arr_len); 
	std::cout << std::endl;


	return 0;
}