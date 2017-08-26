//term 26:�����Ӻ��������ʽ�ĳ���ʱ��

/****************************eg1***********************************/

#include <string>
//bad
std::string encryPassword(const std::string& password)
{
	using namespace std;
	string encrypted;//����׳����쳣��������ȫûʹ��
	if (password.length() < MinimumPasswordLength)
	{
		throw logic_error("password is too short!");
	}

	return encrypted;
}

//bad��too
std::string encryPassword(const std::string& password)
{
	using namespace std;
	
	if (password.length() < MinimumPasswordLength)
	{
		throw logic_error("password is too short!");
	}
	string encrypted;
	//...
	return encrypted;
}


//bad��too
std::string encryPassword(const std::string& password)
{
	using namespace std;

	if (password.length() < MinimumPasswordLength)
	{
		throw logic_error("password is too short!");
	}
	
	//...
	string encrypted;
	encrypted = password; //�ȵ�����Ĭ�Ϲ��캯�����ٽ����˸�ֵ
	return encrypted;
}


//better
std::string encryPassword(const std::string& password)
{
	using namespace std;

	if (password.length() < MinimumPasswordLength)
	{
		throw logic_error("password is too short!");
	}

	//...
	string encrypted(password);//���岢��ʼ��
	return encrypted;
}


/****************************eg2***********************************/
//������ѭ���⣺1�����캯��+1����������+n����ֵ����
//bad : w�ĸ��Ƿ�Χ���󣬶Գ��������ɳ��
//�����ȷ֪����ֵ�ɱ��ȹ���������ͣ��������ַ�ʽ
Widget w;
for (int i = 0; i < n; ++i)
{
	w = ȡ����i��ĳ��ֵ;
}


//������ѭ����:n�����캯��+n����������
//better
//n �Ƚϴ�ʱ���ʺϲ������ַ�ʽ
for (int i = 0; i < n; ++i)
{
	Widget w = ȡ����i��ĳ��ֵ;
}