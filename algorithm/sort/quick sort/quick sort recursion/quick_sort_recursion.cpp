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


//�������� ֮ ��������


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


//��Ŧֵ���ѡ��
int partition_wiht_random_pivot(int arr[], int low, int high)
{
	int random_index = low + rand() % (high - low + 1);
	swap(&arr[random_index], &arr[low]);

	int pivot = arr[low];
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


void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		//int pivotpos = partition(arr, low, high);//arr[pivotpos]λ���Ѿ��ź���

		int pivotpos = partition_wiht_random_pivot(arr, low, high);
		quick_sort(arr, low, pivotpos - 1);//��pivotposǰ���Ԫ�أ��ֱ�ݹ���п���
		quick_sort(arr, pivotpos + 1, high);
	}
}



int main()
{

	int max_num = 100;
	int arr_len = 20;//��һ��Ԫ�ز�ʹ��
	int arr_random[100];



	std::cout << "��������" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	quick_sort(arr_random, 1, arr_len - 1); 
	arr_print(arr_random, arr_len); 
	std::cout << std::endl;

	return 0;
}