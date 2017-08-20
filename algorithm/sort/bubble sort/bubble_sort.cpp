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

void swap(int * a1, int * a2)
{
	if (*a1 == *a2)
		return;
	*a1 = *a1 ^ *a2;
	*a2 = *a1 ^ *a2;
	*a1 = *a1 ^ *a2;
}


//交换排序 之 冒泡排序

void bubble_sort(int arr[], int n)
{
	int i, j, flag;
	for (i = 1; i < n - 1; i++)
	{
		flag = false;
		//每趟冒泡一个最小元素到上面
		for (j = n - 1; j>i; --j)
		{
			if (arr[j - 1] > arr[j])
			{
				swap(&arr[j - 1], &arr[j]);
				flag = true;
			}
		}
		//arr_print(arr, n);
		if (flag == false)
			break;
	}

	arr_print(arr, n);
}

//双向冒泡排序

void bubble_sort_bidirection(int arr[], int n)
{
	int i, j, flag;
	for (i = 1; i < n - 1; i++)
	{
		flag = false;
		//每趟冒泡一个最小元素到上面
		for (j = n - 1; j>i; --j)
		{
			if (arr[j - 1] > arr[j])
			{
				swap(&arr[j - 1], &arr[j]);
				flag = true;
			}
		}
		if (flag == false)
			break;
		//每趟下沉一个最大元素到下面
		for (j = i + 2; j <= n - i; ++j)
		{
			if (arr[j - 1] > arr[j])
			{
				swap(&arr[j - 1], &arr[j]);
				flag = true;
			}
		}
		//arr_print(arr, n);
		if (flag == false)
			break;
	}

	arr_print(arr, n);
}


//荷兰国旗问题
//编写时间复杂度为O(n)的算法：有由红、白、蓝三种颜色的条块组成的条块序列，使条块按红、白、蓝的顺序排好

typedef enum { RED, WHITE, BLUE } color;

void flag_arrage(int arr[], int n)
{
	int front, end, cur;
	for (int i = 1; i < n; i++)
		arr[i] %= 3;
	arr_print(arr, n);

	//front以前的元素全部为红色，end以后的元素全部为蓝色，k为当前工作指针
	front = 1, end = n - 1, cur = 1;
	while (cur <= end)
	{
		switch (arr[cur])
		{
			//当前条形为红色，则和前面的元素交换
		case RED:
			swap(&arr[front], &arr[cur]);
			++front; ++cur;
			break;

			//当前颜色为白色，暂时不交换
		case WHITE:
			++cur;
			break;

			//当前条形为蓝色，则和后面的元素交换
		case BLUE:
			swap(&arr[end], &arr[cur]);
			--end; //这里不进行k++，是因为交换到前面的arr[k]还需要进行处理
			break;
		default:
			break;
		}
	}
	arr_print(arr, n);

}

int main()
{

	int max_num = 100;
	int arr_len = 20;//第一个元素不使用
	int arr_random[100];

	std::cout << "冒泡排序：" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	bubble_sort(arr_random, arr_len); 
	std::cout << std::endl;

	std::cout << "双向冒泡排序：" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num);
	bubble_sort_bidirection(arr_random, arr_len);
	std::cout << std::endl;

	std::cout << "荷兰国旗问题：" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num);
	flag_arrage(arr_random, arr_len);
	std::cout << std::endl;

	return 0;
}