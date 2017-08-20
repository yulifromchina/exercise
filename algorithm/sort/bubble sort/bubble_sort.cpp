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

void swap(int * a1, int * a2)
{
	if (*a1 == *a2)
		return;
	*a1 = *a1 ^ *a2;
	*a2 = *a1 ^ *a2;
	*a1 = *a1 ^ *a2;
}


//�������� ֮ ð������

void bubble_sort(int arr[], int n)
{
	int i, j, flag;
	for (i = 1; i < n - 1; i++)
	{
		flag = false;
		//ÿ��ð��һ����СԪ�ص�����
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

//˫��ð������

void bubble_sort_bidirection(int arr[], int n)
{
	int i, j, flag;
	for (i = 1; i < n - 1; i++)
	{
		flag = false;
		//ÿ��ð��һ����СԪ�ص�����
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
		//ÿ���³�һ�����Ԫ�ص�����
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


//������������
//��дʱ�临�Ӷ�ΪO(n)���㷨�����ɺ졢�ס���������ɫ��������ɵ��������У�ʹ���鰴�졢�ס�����˳���ź�

typedef enum { RED, WHITE, BLUE } color;

void flag_arrage(int arr[], int n)
{
	int front, end, cur;
	for (int i = 1; i < n; i++)
		arr[i] %= 3;
	arr_print(arr, n);

	//front��ǰ��Ԫ��ȫ��Ϊ��ɫ��end�Ժ��Ԫ��ȫ��Ϊ��ɫ��kΪ��ǰ����ָ��
	front = 1, end = n - 1, cur = 1;
	while (cur <= end)
	{
		switch (arr[cur])
		{
			//��ǰ����Ϊ��ɫ�����ǰ���Ԫ�ؽ���
		case RED:
			swap(&arr[front], &arr[cur]);
			++front; ++cur;
			break;

			//��ǰ��ɫΪ��ɫ����ʱ������
		case WHITE:
			++cur;
			break;

			//��ǰ����Ϊ��ɫ����ͺ����Ԫ�ؽ���
		case BLUE:
			swap(&arr[end], &arr[cur]);
			--end; //���ﲻ����k++������Ϊ������ǰ���arr[k]����Ҫ���д���
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
	int arr_len = 20;//��һ��Ԫ�ز�ʹ��
	int arr_random[100];

	std::cout << "ð������" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	bubble_sort(arr_random, arr_len); 
	std::cout << std::endl;

	std::cout << "˫��ð������" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num);
	bubble_sort_bidirection(arr_random, arr_len);
	std::cout << std::endl;

	std::cout << "�����������⣺" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num);
	flag_arrage(arr_random, arr_len);
	std::cout << std::endl;

	return 0;
}