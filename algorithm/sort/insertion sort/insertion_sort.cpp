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


//�������� ֮ ֱ�Ӳ�������

void insertion_sort(int arr[], int n)
{
	int i, j;
	for (i = 2; i < n; i++)//arr[i]��Ϊ�Ѿ��ź���
	{
		if (arr[i] < arr[i - 1])//�����ǰһ��Ԫ��С��˵����Ҫ����ǰԪ�ز���ǰ��ĳ��λ��
		{
			arr[0] = arr[i];
			for (j = i - 1; arr[0] < arr[j]; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = arr[0];

			//��ʹ���ڱ���
			/*int temp = arr[i];
			for (j = i - 1; temp < arr[j] && j>= 1; j--)
			{
			arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;*/
		}
	}

	arr_print(arr, n);
}


int main()
{

	int max_num = 100;
	int arr_len = 20;//��һ��Ԫ�ز�ʹ��
	int arr_random[100];

	std::cout << "ֱ�Ӳ�������" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	insertion_sort(arr_random, arr_len);
	std::cout << std::endl;




	return 0;
}