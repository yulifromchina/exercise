//��ת����˳��
//���磬i am students.----> students. am i

//���ģ��ȷ�ת�������ӣ��ٷ�תÿ������

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


char * ReverseSentence(char * data)
{
	if (data == NULL)
		return NULL;

	char * begin = data;
	char * end = data;
	while (*end != '\0')
		++end;
	--end;

	//��ת��������
	Reverse(begin, end);

	//��ת�����е�ÿ������
	end = data;
	while (*begin != '\0')
	{
		//��*begin�ǿո�ʱ������������
		while (*begin == ' ')
		{
			++begin;
			++end;
		}
		while (*end != ' ' && *end !='\0')
			++end;

		Reverse(begin, --end);
		++end;
		begin = end;
	}
	return data;
}

int main()
{
	using namespace std;
	char data[] = "i am students.";
	char * result = ReverseSentence(data);
	cout << result << endl;
	char data1[] = "students";
	cout << ReverseSentence(data1) << endl;
	char data2[] = "";
	cout << ReverseSentence(data2) << endl;
	char data3[] = " ";
	cout << ReverseSentence(data3) << endl;
	char * data4 = NULL;
	if((result = ReverseSentence(data4))!=NULL)
	cout << result << endl;
	return 0;
}