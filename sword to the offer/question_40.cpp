//������ֻ����һ�ε�����
//����������ֻ������һ�Σ����������2��

#include <iostream>


//���ش��ҵ��󣬵�һ�γ���1��λ��
int FindFirstBitIsOne(int value)
{
	int index = 0;
	while (index < sizeof(int) * 8)
	{
		if (value & 0x1)
			return index;
		++index;
	}
	return -1;
}


//�ж�ָ��λ�����Ƿ���1
bool IsBitOne(int value, int index)
{
	while (index)
	{
		value >>= 1;
		--index;
	}
	return 0x1 & value;
}




bool GetAppearTwice(int * arr, int len, int & result1, int & result2)
{
	if (arr == NULL || len < 2)
		return false;

	//tempΪ����ֻ������һ�ε����ֵ������
	int temp = arr[0];
	for (int i = 1; i < len; ++i)
		temp ^= arr[i];

	if (temp == 0)
		return false;

	//���Ը��������ĳһλ��Ϊ1Ϊ������������ֳ�����
	//�����������ֻ������һ�ε����֣��ط�����������������
	//����2^5=010^101=111,��������һλ������

	int index_first_one_bit = FindFirstBitIsOne(temp);
	if (index_first_one_bit == -1)
		return false;

	result1 = 0; result2 = 0;//�������в������0������¿����������������ֻ������һ�ε�������0�����޷��ж�

	for (int i = 0; i < len; ++i)
	{
		if (IsBitOne(arr[i], index_first_one_bit))
		{
			result1 ^= arr[i];
		}
		else
		{
			result2 ^= arr[i];
		}
	}
	if (result1 != 0 & result2 != 0)
		return true;

	return false;
}


int main()
{
	using namespace std;
	int arr[] = {1,2,3,4,5,1,2,5};
	int result1, result2;
	if (GetAppearTwice(arr, sizeof(arr)/sizeof(arr[0]), result1, result2))
		cout << "number :" << result1 << ",another number :" << result2 << endl;
	
	return 0;
}