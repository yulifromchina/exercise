//输入一个数s, 打印所有和为s的连续正数数列(至少含有2个数)

//例如输入s为15
//则打印：1,2,3,4,5 和4,5,6和7,8

#include <iostream>

using namespace std;

//打印从small到big的数字组成的序列
void PrintSeq(int small, int big)
{
	cout << "seq:(";
	for (int i = small; i <= big; ++i)
		cout << i << " ";
	cout << ")" << endl;
}



void GetSequence(int s)
{
	//数字最小是三
	if (s <= 2)
		return;
	int small = 1, big = 2;
	int middle = (s +1) / 2;
	int cur_sum = small + big;

	while(small < middle) //此时big < (middle+1)/2
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