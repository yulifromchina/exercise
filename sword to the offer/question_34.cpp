//����
//ֻ��������2,3,5�����ֳ�Ϊ����������6,8�ǳ�����14���ǣ���Ϊ��������7.
//�󰴴�С�����˳��ĵ�1500������

//�㷨���ģ�����һ���������ź���ĳ������У���һ������һ����ǰ��ĳ������*2��*3��*5�ĵ���
//����Ҫ��������ǰ������г���������2,3,5
//���磬��*2���ԣ�����һ���ٽ���������������֮ǰ�ĳ���*2,�����С�ڵ�ǰ��������
//���������֮��ĳ���*2,��������ڵ�ǰ��������
//����ֻ�ü�¼�����������λ�ã�ÿ�������µ��������󣬸������λ��

#include <iostream>

using namespace std;


//ȡ�������е���Сֵ
int Min(int a, int b, int c)
{
	int min_num = a > b ? b : a;
	return min_num > c ? c : min_num;
}


//ȡ�õ�indexλ�ĳ���
int GetUgly(int index)
{
	int * ugly_arr = new int[index]();
	if (ugly_arr == NULL)
		throw new exception("Allocate Error");

	ugly_arr[0] = 1;//1�ǵ�һ������
	int * mul2_index = ugly_arr;
	int * mul3_index = ugly_arr;
	int * mul5_index = ugly_arr;
	int next_ugly = 1;

	while (next_ugly < index)
	{
		int temp = Min(*mul2_index * 2, *mul3_index*3, *mul5_index*5);
		ugly_arr[next_ugly] = temp;

		while (*mul2_index * 2 <= temp) ++mul2_index;
		while (*mul3_index * 3 <= temp) ++mul3_index;
		while (*mul5_index * 5 <= temp) ++mul5_index;

		++next_ugly;
	}

	int result = ugly_arr[next_ugly - 1];
	delete[] ugly_arr;
	return result;

}

int main()
{
	cout << GetUgly(1500) << endl;
	return 0;
}