//��1+2+3+...+n
//����ʹ�ó˳�����for, while, if, else, switch, case�ȹؼ����Լ������ж����(A>B?A:B)

#include <iostream>

using namespace std;

//���ù��캯�����ȴ���һ�����ͣ��ٴ���n�����͵�ʵ���������ۼ���صĴ���ŵ���̬������

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