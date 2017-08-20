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
	std::default_random_engine e(time(0));//���棬��������unsigned�������
	std::uniform_int_distribution<unsigned> u(0, max);//����[0,max]�ھ��ȷֲ�����
													  //arr[0]��ʹ��
	for (int i = 1; i < n; i++)
	{
		arr[i] = u(e);
	}
	std::cout << "������У�" << std::endl;
	arr_print(arr, n);
}


//�÷ǵݹ鷽����ջ ʵ�ֿ�������

struct node
{
	int low;
	int high;
	node(int low_, int high_) :low(low_), high(high_) {}
};

using node = struct node;

//�����λԪ��Ϊ��Ŧֵ
int partition(int arr[], int low, int high)
{
	int pivot = arr[low];//��pivot���ֵ�������յ�λ����
	while (low < high)
	{
		while (low<high && arr[high] >= pivot) --high;//high����ǰ��
		arr[low] = arr[high];
		while (low < high && arr[low] <= pivot) ++low;//low���Ϻ���
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

		//��ʼ���ֵ����Զ˵���ջ
		if (low < pivotpos - 1)
			stack_.push(new node(low, pivotpos - 1));
		if (high > pivotpos)
			stack_.push(new node(pivotpos + 1, high));
	}

	while (!stack_.empty())
	{
		//��ջһ�Ի��ֵĶ˵�
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



//�÷ǵݹ鷽�������� ʵ�ֿ�������
void quick_sort_by_queue(int arr[], int low, int high)
{
	std::queue<node *> queue_;
	int pivotpos;

	if (low < high)
	{
		pivotpos = partition(arr, low, high);

		//��ʼ���ֵ����Զ˵���ջ
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
	int arr_len = 20;//��һ��Ԫ�ز�ʹ��
	int arr_random[100];



	std::cout << "����ʵ�ֿ�������" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	quick_sort_by_queue(arr_random, 1, arr_len - 1); 
	arr_print(arr_random, arr_len); 
	std::cout << std::endl;

	std::cout << "ջʵ�ֿ�������" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num);
	quick_sort_by_stack(arr_random, 1, arr_len - 1);
	arr_print(arr_random, arr_len);
	std::cout << std::endl;

	return 0;
}