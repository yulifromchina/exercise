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

//向下调整堆
void adjust_down(int arr[], int k, int n)
{
	arr[0] = arr[k];
	for (int i = 2 * k; i <= n; i *= 2)
	{
		if (i + 1 <= n && arr[i] < arr[i + 1])
			i++;//i为左右孩子中，较大的孩子的下标

		if (arr[0] >= arr[i])
			break;//根比孩子大
		else
		{
			arr[k] = arr[i];
			//也可以直接交换元素：
			//swap(&arr[k], &arr[i]);
			k = i;
		}
	}
	arr[k] = arr[0];

}

//建立大根堆
void build_max_heap(int arr[], int n)
{
	//从最后一颗子树到根结点
	for (int i = n / 2; i >= 1; i--)
	{
		adjust_down(arr, i, n);
		//adjust_down_recursion(arr,i,n);
	}
}



void adjust_down_recursion(int arr[], int k, int n)
{
	if (2 * k > n)
		return;

	int i = 2 * k;
	if (2 * k + 1 <= n && arr[2 * k + 1] > arr[2 * k])
		i = 2 * k + 1;
	if (arr[i]>arr[k])
		swap(&arr[i], &arr[k]);
	adjust_down_recursion(arr, i, n);
}

//向上调整堆
//void adjust_up();


//交换排序 之 堆排序, 大根堆排好的是降序
void heap_sort(int arr[], int n)
{
	build_max_heap(arr, n);
	for (int i = n - 1; i > 1; --i)
	{
		//把堆最下面的元素和第一个元素交换（排好序的元素已经出堆，不参与）
		swap(&arr[i], &arr[1]);

		//向下调整堆
		adjust_down(arr, 1, i - 1);
		//adjust_down_recursion(arr, 1, i-1);
	}

	arr_print(arr, n);
}



int main()
{

	int max_num = 100;
	int arr_len = 20;//第一个元素不使用
	int arr_random[100];

	std::cout << "大根堆排序：" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	heap_sort(arr_random, arr_len); 
	std::cout << std::endl;


	return 0;
}