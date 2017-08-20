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

//С����




//���µ����ѣ���С��Ԫ������
void adjust_down_2(int arr[], int k, int n)
{
	arr[0] = arr[k];
	for (int i = 2 * k; i < n; i *= 2)
	{
		if (i + 1 < n && arr[i] > arr[i + 1])
			++i;//iΪ���Һ����У���С���ӵ�����

		if (arr[0] <= arr[i])//���Ⱥ���С
			break;
		else
		{
			swap(&arr[k], &arr[i]);//����Ԫ�أ���С������
			k = i;//����������
		}
	}

}

//����С����
void build_min_heap(int arr[], int n)
{
	//�����һ�������������
	for (int i = n / 2; i > 0; --i)
	{
		adjust_down_2(arr, i, n);
	}
}


//С��������С�����źõ�������
void heap_sort_2(int arr[], int n)
{
	build_min_heap(arr, n);
	for (int i = n - 1; i > 1; --i)
	{
		//�Ѷ��������Ԫ�غ͵�һ��Ԫ�ؽ������ź����Ԫ���Ѿ����ѣ������룩
		swap(&arr[i], &arr[1]);

		//���µ�����
		adjust_down_2(arr, 1, i - 1);
	}

	arr_print(arr, n);
}


//�ж�һ�����������Ƿ���С����
bool is_min_heap(int arr[], int n)
{
	if (n % 2 != 0)//arr[0]�����Ԫ�أ����nΪ����ʱ����һ��������֧
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
	int arr_len = 20;//��һ��Ԫ�ز�ʹ��
	int arr_random[100];

	std::cout << "С��������" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	heap_sort_2(arr_random, arr_len); 
	std::cout << std::endl;

	bool f1 = is_min_heap(arr_random, arr_len);
	if (f1) std::cout << "��С����" << std::endl << std::endl;
	else std::cout << "����С����" << std::endl << std::endl;


	return 0;
}