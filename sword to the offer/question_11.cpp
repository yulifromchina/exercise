//实现数值的整数次方

#include <iostream>
#include <cmath>


//判断两个双精度浮点数是否相等
bool equal(double d1, double d2)
{
	if (abs(d1 - d2)<0.000001)
		return true;
	else
		return false;
}


//幂指数为正数的情况下，计算幂
double powerWithPositiveExponent(double base, int exponent)
{
	if (exponent == 1)
		return base;

	//减少计算次数
	double result = powerWithPositiveExponent(base , exponent>>1);
	result *= result;

	//计算次数为奇数时，补上一次
	if (exponent & 0x1)
		result *= base;
	return result;
}


//实现整数次幂
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