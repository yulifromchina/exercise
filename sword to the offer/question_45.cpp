//ԲȦʣ�µ��������
//��Ŀ��0,1...n-1��n�������ų�һ��ԲȦ�������ֿ�ʼÿ�δ����ԲȦɾ����m�����֣���ԲȦ��ʣ�µ�����


//���ģ����ƹ�ʽ��f(n,m) = 0,n=1ʱ��
//f(n,m) = [f(n-1,m)+m]%n ,n >1ʱ
#include <iostream>

int GetLast(int n, int m)
{
	if (m <= 0 || n<1)
		return -1;

	int last = 0;
	for (int i = 2; i <= n; ++i)
	{
		last = (last + m) % i;
	}
	return last;
}

int main()
{
	using namespace std;
	cout << GetLast(13,3) << endl;
}