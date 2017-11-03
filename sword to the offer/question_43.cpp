//n�����ӵĵ���
//��n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs,����n����ӡ���е�s���ܳ��ֵ�ֵ�ĸ���

//���ģ���̬�滮
//����k-1�����ӣ�������һ�����ӣ��������Ͷ���ĵ���ֻ����1��2,3,4,5,6
//����k�����Ӻ�nΪ�����,�ֱ��Ӧk-1������Ͷ����n-6,n-5,n-4,n-3,n-2,n-1
//f(k,n) = f(k-1,n-1)+f(k-1,n-2)+f(k-1,n-3)+f(k-1,n-4)+f(k-1,n-5)+f(k-1,n-6)
//f(1,1)=f(1,2)=f(1,3)=f(1,4)=f(1,5)=f(1,6)=1

#include <iostream>


//����n������Ͷ����Ϊs�Ŀ����������
int CountNumber(int n, int s)
{
	//n�����ӵ�Ͷ��������n~6*n֮��
	if (s < n || s>6 * n)
		return 0;


	//ֻ��һ�����ӣ���Ͷ����sֻ��һ�ֿ���
	if (n == 1)
		return 1;
	
	return CountNumber(n - 1, s - 1) + CountNumber(n - 1, s - 2) + CountNumber(n - 1, s - 3) + CountNumber(n - 1, s - 4) + CountNumber(n - 1, s - 5) + CountNumber(n - 1, s - 6);
}


//�������
void CalculatePossibility(int n)
{
	for (int i = n; i <= 6 * n; ++i)
	{
		int number = CountNumber(n, i);
		std::cout << n << " ������Ͷ���� " << i << " �ĸ���Ϊ��" << number << " / " << pow(6, n) << std::endl;
	}
}


int main()
{
	using namespace std;
	CalculatePossibility(3);
	return 0;
}