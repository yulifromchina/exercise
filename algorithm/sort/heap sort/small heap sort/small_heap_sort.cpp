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

//小根堆




//向下调整堆，较小的元素上移
void adjust_down_2(int arr[], int k, int n)
{
	arr[0] = arr[k];
	for (int i = 2 * k; i < n; i *= 2)
	{
		if (i + 1 < n && arr[i] > arr[i + 1])
			++i;//i为左右孩子中，较小孩子的坐标

		if (arr[0] <= arr[i])//根比孩子小
			break;
		else
		{
			swap(&arr[k], &arr[i]);//交换元素，较小的上移
			k = i;//继续往下找
		}
	}

}

//建立小根堆
void build_min_heap(int arr[], int n)
{
	//从最后一颗子树到根结点
	for (int i = n / 2; i > 0; --i)
	{
		adjust_down_2(arr, i, n);
	}
}


//小根堆排序，小根堆排好的是升序
void heap_sort_2(int arr[], int n)
{
	build_min_heap(arr, n);
	for (int i = n - 1; i > 1; --i)
	{
		//把堆最下面的元素和第一个元素交换（排好序的元素已经出堆，不参与）
		swap(&arr[i], &arr[1]);

		//向下调整堆
		adjust_down_2(arr, 1, i - 1);
	}

	arr_print(arr, n);
}


//判断一个数据序列是否是小根堆
bool is_min_heap(int arr[], int n)
{
	if (n % 2 != 0)//arr[0]不存放元素，因此n为奇数时，有一个单结点分支
	{
		if (arr[n / 2] > arr[n - 1])
			return false;
	}

	for (int i = n / 2 - 1; i >= 1; --i)
	{
		if (arr[i] > arr[2 * i] || arr[i] > arr[2 * i + 1])
			return false;
	}

	return true;
}




int main()
{

	int max_num = 100;
	int arr_len = 20;//第一个元素不使用
	int arr_random[100];

	std::cout << "小根堆排序：" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	heap_sort_2(arr_random, arr_len); 
	std::cout << std::endl;

	bool f1 = is_min_heap(arr_random, arr_len);
	if (f1) std::cout << "是小根堆" << std::endl << std::endl;
	else std::cout << "不是小根堆" << std::endl << std::endl;


	return 0;
}