//不用加减乘除做加法

#include <iostream>

int Add(int num1, int num2)
{
	int sum, carry;
	do
	{
		sum = num1 ^ num2;  // step1: 不考虑进位，对每一位相加；0+0=0,1+1=0,1+0=1,这与异或结果是一样的
		carry = (num1 & num2) << 1;//step2: 只有1+1时会有进位；与两个数先做与运算，再左移一位是一样的
		num1 = sum;
		num2 = carry;
	} while (num2!=0);//当不产生进位时停止

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