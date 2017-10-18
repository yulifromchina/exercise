//ʵ����ֵ�������η�

#include <iostream>
#include <cmath>


//�ж�����˫���ȸ������Ƿ����
bool equal(double d1, double d2)
{
	if (abs(d1 - d2)<0.000001)
		return true;
	else
		return false;
}


//��ָ��Ϊ����������£�������
double powerWithPositiveExponent(double base, int exponent)
{
	if (exponent == 1)
		return base;

	//���ټ������
	double result = powerWithPositiveExponent(base , exponent>>1);
	result *= result;

	//�������Ϊ����ʱ������һ��
	if (exponent & 0x1)
		result *= base;
	return result;
}


//ʵ����������
double myPower(double base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (equal(base, 0.0))
		return 0.0;

	int isNegative = 0;
	if (exponent < 0)
	{
		isNegative = 1;
		exponent = -exponent;
	}
	double result = powerWithPositiveExponent(base, exponent);
	if (isNegative)
		result = 1.0 / result;

	return result;
}


int main()
{
	using namespace std;
	cout << pow(0.0, 0) << " " << myPower(0.0, 0) << endl;
	cout << pow(0, 3) << " " << myPower(0, 3) << endl;
	cout << pow(3, 0) << " " << myPower(3, 0) << endl;
	cout << pow(3, 2) << " " << myPower(3,2) << endl;
	cout << pow(3, -2) << " " << myPower(3, -2) << endl;

	return 0;
}