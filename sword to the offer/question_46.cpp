//求1+2+3+...+n
//不能使用乘除法，for, while, if, else, switch, case等关键字以及条件判断语句(A>B?A:B)

#include <iostream>

using namespace std;

//利用构造函数，先创建一个类型，再创建n个类型的实例；将与累加相关的代码放到静态变量中

class Temp
{
public:
	Temp() { ++N; Sum += N; }
	static void Reset() { N = 0; Sum = 0; }
	static unsigned int GetSum() { return Sum; }
private:
	static unsigned int N;
	static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_Solution1(unsigned int n)
{
	if (n <= 0)
		return -1;
	Temp::Reset();

	Temp * a = new Temp[n];
	delete[] a;
	a = NULL;

	return Temp::GetSum();
}

int main()
{
	using namespace std;
	cout << Sum_Solution1(1) << endl;
	cout << Sum_Solution1(2) << endl;
	cout << Sum_Solution1(3) << endl;
	cout << Sum_Solution1(4) << endl;
	cout << Sum_Solution1(5) << endl;
	return 0;
}