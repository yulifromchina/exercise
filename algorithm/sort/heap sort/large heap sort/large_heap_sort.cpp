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

//���µ�����
void adjust_down(int arr[], int k, int n)
{
	arr[0] = arr[k];
	for (int i = 2 * k; i <= n; i *= 2)
	{
		if (i + 1 <= n && arr[i] < arr[i + 1])
			i++;//iΪ���Һ����У��ϴ�ĺ��ӵ��±�

		if (arr[0] >= arr[i])
			break;//���Ⱥ��Ӵ�
		else
		{
			arr[k] = arr[i];
			//Ҳ����ֱ�ӽ���Ԫ�أ�
			//swap(&arr[k], &arr[i]);
			k = i;
		}
	}
	arr[k] = arr[0];

}

//���������
void build_max_heap(int arr[], int n)
{
	//�����һ�������������
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

//���ϵ�����
//void adjust_up();


//�������� ֮ ������, ������źõ��ǽ���
void heap_sort(int arr[], int n)
{
	build_max_heap(arr, n);
	for (int i = n - 1; i > 1; --i)
	{
		//�Ѷ��������Ԫ�غ͵�һ��Ԫ�ؽ������ź����Ԫ���Ѿ����ѣ������룩
		swap(&arr[i], &arr[1]);

		//���µ�����
		adjust_down(arr, 1, i - 1);
		//adjust_down_recursion(arr, 1, i-1);
	}

	arr_print(arr, n);
}



int main()
{

	int max_num = 100;
	int arr_len = 20;//��һ��Ԫ�ز�ʹ��
	int arr_random[100];

	std::cout << "���������" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	heap_sort(arr_random, arr_len); 
	std::cout << std::endl;


	return 0;
}