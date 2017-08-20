#include <iostream>
#include <ctime>
#include <random>
#include <stack>
#include <queue>


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


//用非递归方法：栈 实现快速排序

struct node
{
	int low;
	int high;
	node(int low_, int high_) :low(low_), high(high_) {}
};

using node = struct node;

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


void quick_sort_by_stack(int arr[], int low, int high)
{
	std::stack<node *> stack_;
	int pivotpos;

	if (low < high)
	{
		pivotpos = partition(arr, low, high);

		//初始划分的两对端点入栈
		if (low < pivotpos - 1)
			stack_.push(new node(low, pivotpos - 1));
		if (high > pivotpos)
			stack_.push(new node(pivotpos + 1, high));
	}

	while (!stack_.empty())
	{
		//出栈一对划分的端点
		node * temp = stack_.top();

		low = temp->low;
		high = temp->high;
		stack_.pop();

		delete temp;

		pivotpos = partition(arr, low, high);

		if (low < pivotpos - 1)
			stack_.push(new node(low, pivotpos - 1));
		if (high > pivotpos)
			stack_.push(new node(pivotpos + 1, high));
	}

}



//用非递归方法：队列 实现快速排序
void quick_sort_by_queue(int arr[], int low, int high)
{
	std::queue<node *> queue_;
	int pivotpos;

	if (low < high)
	{
		pivotpos = partition(arr, low, high);

		//初始划分的两对端点入栈
		if (low < pivotpos - 1)
			queue_.push(new node(low, pivotpos - 1));
		if (high > pivotpos)
			queue_.push(new node(pivotpos + 1, high));
	}

	while (!queue_.empty())
	{
		node * temp = queue_.front();
		low = temp->low;
		high = temp->high;
		queue_.pop();
		delete temp;

		pivotpos = partition(arr, low, high);

		if (low < pivotpos - 1)
			queue_.push(new node(low, pivotpos - 1));
		if (high > pivotpos + 1)
			queue_.push(new node(pivotpos + 1, high));
	}
}



int main()
{

	int max_num = 100;
	int arr_len = 20;//第一个元素不使用
	int arr_random[100];



	std::cout << "队列实现快速排序：" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	quick_sort_by_queue(arr_random, 1, arr_len - 1); 
	arr_print(arr_random, arr_len); 
	std::cout << std::endl;

	std::cout << "栈实现快速排序：" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num);
	quick_sort_by_stack(arr_random, 1, arr_len - 1);
	arr_print(arr_random, arr_len);
	std::cout << std::endl;

	return 0;
}