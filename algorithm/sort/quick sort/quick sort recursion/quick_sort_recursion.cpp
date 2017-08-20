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


//交换排序 之 快速排序


//以最低位元素为枢纽值
int partition(int arr[], int low, int high)
{
	int pivot = arr[low];//将pivot这个值排在最终的位置上
	while (low < high)
	{
		while (low<high && arr[high] >= pivot) --high;//high不断前移
		arr[low] = arr[high];
		while (low < high && arr[low] <= pivot) ++low;//low不断后移
		arr[high] = arr[low];
	}
	arr[high] = pivot;
	return high;
}


//枢纽值随机选择
int partition_wiht_random_pivot(int arr[], int low, int high)
{
	int random_index = low + rand() % (high - low + 1);
	swap(&arr[random_index], &arr[low]);

	int pivot = arr[low];
	while (low < high)
	{
		while (low<high && arr[high] >= pivot) --high;//high不断前移
		arr[low] = arr[high];
		while (low < high && arr[low] <= pivot) ++low;//low不断后移
		arr[high] = arr[low];
	}
	arr[high] = pivot;
	return high;
}


void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		//int pivotpos = partition(arr, low, high);//arr[pivotpos]位置已经排好序

		int pivotpos = partition_wiht_random_pivot(arr, low, high);
		quick_sort(arr, low, pivotpos - 1);//对pivotpos前后的元素，分别递归进行快排
		quick_sort(arr, pivotpos + 1, high);
	}
}



int main()
{

	int max_num = 100;
	int arr_len = 20;//第一个元素不使用
	int arr_random[100];



	std::cout << "快速排序：" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	quick_sort(arr_random, 1, arr_len - 1); 
	arr_print(arr_random, arr_len); 
	std::cout << std::endl;

	return 0;
}