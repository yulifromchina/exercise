//��ӡ1��n������
//��������
#include <iostream>

using namespace std;

//��ӡ����
void printNum(int * num, int len)
{
	int * ptr = num, i = 0;
	while (*ptr == 0)
	{
		++ptr;
		++i;
	}
	for (; i < len; ++i)
		cout << num[i];
	cout << endl;
}


//�����ӷ���ÿ�μ�1
bool Increment(int * num, int len)
{
	bool isOverFlow = false;
	
	num[len - 1]++;
	for (int i = len - 1; i >= 0; --i)
	{
		if (num[i] == 10)
		{
			//���λ���Ͻ�λ>=10,˵��֮ǰ�Ѿ�������99..99
			if (i == 0)
			{
				isOverFlow = true;
				break;
			}
			else
			{
				num[i] -= 10;
				++num[i - 1];
			}
		}
	}
	return isOverFlow;
}


//��ӡ��������1��n
void printToMaxN(int n)
{
	if (n < 0)
		return;

	int * num = new int[n]();
	if (num == NULL)
		exit(EXIT_FAILURE);

	while (!Increment(num, n))
		printNum(num,n);

	delete[] num;
	num = NULL;
}

int main()
{
	int n;
	cin >> n;
	printToMaxN(n);
	return 0;
}