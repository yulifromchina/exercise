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


//�������� ֮ ϣ������
void shell_sort(int arr[], int n)
{
	int dk, i, j;
	for (dk = n / 2; dk >= 1; dk--)//������n/2�𽥼���1
	{
		//����Ϊֱ�Ӳ�������ÿ��ĵ�һ����Ĭ���ź�������i��dk+1��ʼ
		for (i = dk + 1; i < n; ++i)
		{
			//�����ǰһ��Ԫ��С��˵����Ҫ����ǰԪ�ز���ǰ��ĳ��λ��
			if (arr[i - dk] > arr[i])
			{
				arr[0] = arr[i];
				for (j = i - dk; arr[0] < arr[j]; j -= dk)
				{
					arr[j + dk] = arr[j];
				}
				arr[j + dk] = arr[0];
			}
		}
	}

	arr_print(arr, n);
}


int main()
{

	int max_num = 100;
	int arr_len = 20;//��һ��Ԫ�ز�ʹ��
	int arr_random[100];


	std::cout << "ϣ������" << std::endl;
	get_random_sequence(arr_random, arr_len, max_num); 
	shell_sort(arr_random, arr_len); 
	std::cout << std::endl;


	return 0;
}