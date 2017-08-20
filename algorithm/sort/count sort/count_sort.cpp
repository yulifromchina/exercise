#include <iostream>
#include <ctime>
#include <random>
#include <cassert>

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

//��������
//������ʵ��
void count_sort_1(int arr[], int n)
{
	//��Ž��������
	int * C = new int[n]();
	assert(C != NULL);

	//�м�����
	//���ҳ�arr��������
	int max = 1;
	for (int i = 2; i < n; i++)
	{
		if (arr[max] < arr[i])
			max = i;
	}
	int * B = new int[arr[max] + 1]();
	assert(B != NULL);

	//��arr��Ԫ�س��ֵĸ���ͳ�Ƶ�B��
	for (int i = 1; i < n; i++)
		B[arr[i]] += 1;
	//B��ÿ��Ԫ��=ǰ��Ԫ�صĺ�+��ǰԪ��
	for (int i = 2; i < arr[max] + 1; i++)
	{
		B[i] += B[i - 1];
	}

	//�����м�����B����arr��Ԫ������C��
	for (int i = n - 1; i > 0; --i)
	{
		int index = B[arr[i]];
		C[index] = arr[i];
		B[arr[i]]--;
	}
	//���ѽ�����Ƶ�arr��
	for (int i = 1; i < n; i++)
	{
		arr[i] = C[i];
	}

	delete C;
	delete B;

	arr_print(arr, n);
}


int main()
{

	int max_num = 100;
	int arr_len = 20;//��һ��Ԫ�ز�ʹ��
	int arr_random[100];

	std::cout << "��������" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	count_sort_1(arr_random, arr_len); 
	std::cout << std::endl;


	return 0;
}