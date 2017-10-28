//���ַ�����һ��ֻ����һ�ε��ַ�

//�����㷨�������ַ�������hash��洢ÿ���ַ����ֵĴ���
//�ٴα����ַ������ҵ���һ��hashֵΪ1��Ԫ��

#include <iostream>

using namespace std;

char FirstNotRepeat(char * str)
{
	if (str == NULL)
		return '\0';

	int table[256] = { 0 };
	char * ptr = str;
	while (*ptr != '\0')
	{
		++table[*ptr];
		++ptr;
	}

	ptr = str;
	while (*ptr != '\0')
	{
		if (table[*ptr] == 1)
			return *ptr;
		++ptr;
	}
	return '\0';
}

int main()
{
	char * s1 = "abababcdd";
	cout << FirstNotRepeat(s1) << endl;
	char * s2 = "abab";
	cout << FirstNotRepeat(s2) << endl;
	char * s3 = "abc";
	cout << FirstNotRepeat(s3) << endl;
	char * s4 = NULL;
	cout << FirstNotRepeat(s4) << endl;
	return 0;
}