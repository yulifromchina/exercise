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


int get_special_bit(int dig, int m)
{
	for (int i = 0; i < m - 1; i++)
		dig /= 10;
	dig %= 10;
	return dig;
}


void insertion_sort_adapt_to_radix_sort(int arr[], int n, int m)
{
	int i, j;
	for (i = 2; i < n; i++)//arr[i]��Ϊ�Ѿ��ź���
	{
		if (get_special_bit(arr[i], m) < get_special_bit(arr[i - 1], m))//�����ǰһ��Ԫ��С��˵����Ҫ����ǰԪ�ز���ǰ��ĳ��λ��
		{
			arr[0] = arr[i];
			for (j = i - 1; get_special_bit(arr[0], m) < get_special_bit(arr[j], m); j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = arr[0];
		}
	}

}

//��ȡ����λ��
int get_max_bits(int arr[], int n)
{
	if (n <= 2) return -1;
	int max = arr[1];
	for (int i = 2; i < n; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	int count = 0;
	while (max > 0)
	{
		max /= 10;
		count++;
	}
	return count;
}

//����bλ����
void sort_by_bits(int arr[], int n, int m)
{
	int * temp = new int[n];
	for (int i = 1; i < n; i++)
	{
		temp[i] = arr[i];

	}
	//ʹ���޸Ĺ��Ĳ�������
	insertion_sort_adapt_to_radix_sort(temp, n, m);

	for (int i = 1; i < n; i++)
	{
		arr[i] = temp[i];
	}
	delete temp;
}

//��������
void radix_sort(int arr[], int n)
{
	int m = get_max_bits(arr, n);
	//�������mλ(���λΪm�����λΪ1)������m��
	for (int i = 1; i <= m; i++)
		sort_by_bits(arr, n, i);

	arr_print(arr, n);
}


int main()
{

	int max_num = 100;
	int arr_len = 20;//��һ��Ԫ�ز�ʹ��
	int arr_random[100];

	std::cout << "��������" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	radix_sort(arr_random, arr_len); 
	std::cout << std::endl;


	return 0;
}