//在字符串第一个只出现一次的字符

//核心算法：遍历字符串，用hash表存储每个字符出现的次数
//再次遍历字符串，找到第一个hash值为1的元素

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