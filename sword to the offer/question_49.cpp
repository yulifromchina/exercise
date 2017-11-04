//ʵ��atoi

#include <iostream>

enum Status {valid=0, invalid};
int status = valid;

long long StrToIntCore(const char * digit, bool minus)
{
	long long num = 0;
	while (*digit != '\0')
	{
		if (*digit >= '0' && *digit <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*digit - '0');

			//������У��ò���������
			//���������,32bit��
			//����������0x7fffffff
			//��С�ĸ��� 0x80000000  ������Ǹ��ģ�ʣ�µ���������
			if ((!minus && num > 0x7FFFFFFF) || (minus && (signed int)num < 0x80000000))
			{
				num = 0;
				break;
			}
			++digit;
		}
		else
		{
			//�зǷ��ַ�
			num = 0;
			break;
		}
	}
	if (*digit == '\0')
		status = valid;

	return num;
}


int StrToInt(const char * str)
{
	status = invalid;
	long long num = 0;

	if (str != NULL && *str != '\0')
	{
		bool minus = false;
		if (*str == '+')
			++str;
		else if (*str == '-')
		{
			++str;
			minus = true;
		}

		if (*str != '\0')
			num = StrToIntCore(str, minus);
	}
	return (int)num;
}


int main()
{
	using namespace std;

	char * str1 = "+123";
	cout << StrToInt(str1) << endl;
	char * str2 = "-123";
	cout << StrToInt(str2) << endl;
	char * str3 = "0";
	cout << StrToInt(str3) << endl;
	char * str4 = "-32768";
	cout << StrToInt(str4) << endl;
	char * str5 = "32767";
	cout << StrToInt(str5) << endl;
	char * str6 = NULL;
	cout << StrToInt(str6) << endl;
	char * str7 = "abc123";
	cout << StrToInt(str7) << endl;
	char * str8 = "";
	cout << StrToInt(str8) << endl;

	return 0;
}