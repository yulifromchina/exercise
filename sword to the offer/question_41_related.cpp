//����һ����s, ��ӡ���к�Ϊs��������������(���ٺ���2����)

//��������sΪ15
//���ӡ��1,2,3,4,5 ��4,5,6��7,8

#include <iostream>

using namespace std;

//��ӡ��small��big��������ɵ�����
void PrintSeq(int small, int big)
{
	cout << "seq:(";
	for (int i = small; i <= big; ++i)
		cout << i << " ";
	cout << ")" << endl;
}



void GetSequence(int s)
{
	//������С����
	if (s <= 2)
		return;
	int small = 1, big = 2;
	int middle = (s +1) / 2;
	int cur_sum = small + big;

	while(small < middle) //��ʱbig < (middle+1)/2
	{
		if (cur_sum == s)
		{
			PrintSeq(small, big);
		}

		while (small < middle && cur_sum > s)
		{
			cur_sum -= small;
			++small;
			if(cur_sum == s)
				PrintSeq(small, big);
		}
		++big;
		cur_sum += big;
	}	
}


int main()
{
	GetSequence(15);
	return 0;
}