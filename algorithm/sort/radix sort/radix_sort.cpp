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


int get_special_bit(int dig, int m)
{
	for (int i = 0; i < m - 1; i++)
		dig /= 10;
	dig %= 10;
	return dig;
}


void insertion_sort_adapt_to_radix_sort(int arr[], int n, int m)
{
	int i, j;
	for (i = 2; i < n; i++)//arr[i]认为已经排好序
	{
		if (get_special_bit(arr[i], m) < get_special_bit(arr[i - 1], m))//如果比前一个元素小，说明需要将当前元素插入前面某个位置
		{
			arr[0] = arr[i];
			for (j = i - 1; get_special_bit(arr[0], m) < get_special_bit(arr[j], m); j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = arr[0];
		}
	}

}

//获取最大的位数
int get_max_bits(int arr[], int n)
{
	if (n <= 2) return -1;
	int max = arr[1];
	for (int i = 2; i < n; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	int count = 0;
	while (max > 0)
	{
		max /= 10;
		count++;
	}
	return count;
}

//按第b位排序
void sort_by_bits(int arr[], int n, int m)
{
	int * temp = new int[n];
	for (int i = 1; i < n; i++)
	{
		temp[i] = arr[i];

	}
	//使用修改过的插入排序
	insertion_sort_adapt_to_radix_sort(temp, n, m);

	for (int i = 1; i < n; i++)
	{
		arr[i] = temp[i];
	}
	delete temp;
}

//基数排序
void radix_sort(int arr[], int n)
{
	int m = get_max_bits(arr, n);
	//最大数有m位(最高位为m，最低位为1)，排序m次
	for (int i = 1; i <= m; i++)
		sort_by_bits(arr, n, i);

	arr_print(arr, n);
}


int main()
{

	int max_num = 100;
	int arr_len = 20;//第一个元素不使用
	int arr_random[100];

	std::cout << "基数排序：" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	radix_sort(arr_random, arr_len); 
	std::cout << std::endl;


	return 0;
}