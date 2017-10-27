//����һ���ַ�������ӡ�����ַ����У������ַ�������
//��������abc����ӡabc, acb,  bac,  bca,  cab��cba

#include <iostream>
#include <vector>

using namespace std;

void PermutationHelper(vector<char>input, int index)
{

	if (index == input.size() - 1)
	{
		for (const auto & it : input)
			cout << it;
		cout << endl;
		return;
	}
	

	vector<char>::iterator begin = input.begin();
	advance(begin, index);
	vector<char>::iterator cur = begin;
	for (; cur != input.end(); ++cur)
	{
		char temp = *begin;
		*begin = *cur;
		*cur = temp;

		PermutationHelper(input, index + 1);

		temp = *begin;
		*begin = *cur;
		*cur = temp;
	}

}

void Permutation(vector<char>input)
{
	if (input.empty())
		return;
	PermutationHelper(input, 0);
}

int main()
{
	vector<char> input = { 'a','b','c','d' };
	Permutation(input);
	vector<char> input2 = { 'g' };
	Permutation(input2);

	return 0;
}