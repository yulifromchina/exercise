//���üӼ��˳����ӷ�

#include <iostream>

int Add(int num1, int num2)
{
	int sum, carry;
	do
	{
		sum = num1 ^ num2;  // step1: �����ǽ�λ����ÿһλ��ӣ�0+0=0,1+1=0,1+0=1,�����������һ����
		carry = (num1 & num2) << 1;//step2: ֻ��1+1ʱ���н�λ�������������������㣬������һλ��һ����
		num1 = sum;
		num2 = carry;
	} while (num2!=0);//����������λʱֹͣ

	return num1;
}

int main()
{
	using namespace std;
	cout << Add(0, 0) << endl;
	cout << Add(1, 1) << endl;
	cout << Add(1, -3) << endl;
	return 0;
}