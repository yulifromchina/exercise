//ʵ���ַ���������
//����"abcdefg"��2�����ؽ��"cdefgab"

//���ģ��ֱ�תǰ2���ͺ�����ַ�������������巭תһ��

#include <iostream>

//��ת����ָ��֮�������
void Reverse(char * begin, char * end)
{
	if (begin == NULL || end == NULL)
		return;

	while (begin < end)
	{
		char temp = *begin;
		*begin = *end;
		*end = temp;

		++begin;
		--end;
	}
}



char * LeftRotate(char * sentence, int n)
{
	if (sentence == NULL || n <= 0)
		return sentence;

	char * begin = sentence;
	char * end = sentence;
	int count = 0;
	while (*end != '\0')
	{
		++end;
		++count;
	}
	if (--count < n)
		return sentence;


	//��תǰn���ַ�
	char * end1 = sentence;
	int temp = n-1;
	while (temp)
	{
		++end1;
		--temp;
	}
	Reverse(begin, end1);

	//��תʣ�µ��ַ�
	begin = end1+1;
	Reverse(begin, --end);

	//////�����巭תһ��
	begin = sentence;
	Reverse(begin, end);

	return sentence;
}


int main()
{
	using namespace std;
	cout << "test case 1:" << endl;
	char data[] = "abcdefg";
	char * result = LeftRotate(data,2);
	if (result)
		cout << result << endl;

	cout << "test case 2:" << endl;
	char data1[] = "abcdefg";
	result = LeftRotate(data1, 0);
	if (result)
		cout << result << endl;

	cout << "test case 3:" << endl;
	char data2[] = "abcdefg";
	result = LeftRotate(data2, 1);
	if (result)
		cout << result << endl;

	cout << "test case 4:" << endl;
	char data3[] = "abcdefg";
	result = LeftRotate(data3, 7);
	if (result)
		cout << result << endl;

	cout << "test case 5:" << endl;
	char data4[] = "abcdefg";
	result = LeftRotate(data4, 6);
	if (result)
		cout << result << endl;

	cout << "test case 6:" << endl;
	char data5[] = "abcdefg";
	result = LeftRotate(data5, 8);
	if (result)
		cout << result << endl;

	cout << "test case 7:" << endl;
	char * data6 = NULL;
	result = LeftRotate(data6, 8);
	if (result)
		cout << result << endl;

	return 0;
}