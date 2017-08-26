//term 26:尽量延后变量定义式的出现时间

/****************************eg1***********************************/

#include <string>
//bad
std::string encryPassword(const std::string& password)
{
	using namespace std;
	string encrypted;//如果抛出了异常，对象完全没使用
	if (password.length() < MinimumPasswordLength)
	{
		throw logic_error("password is too short!");
	}

	return encrypted;
}

//bad，too
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


//bad，too
std::string encryPassword(const std::string& password)
{
	using namespace std;

	if (password.length() < MinimumPasswordLength)
	{
		throw logic_error("password is too short!");
	}
	
	//...
	string encrypted;
	encrypted = password; //先调用了默认构造函数，再进行了赋值
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
	string encrypted(password);//定义并初始化
	return encrypted;
}


/****************************eg2***********************************/
//定义在循环外：1个构造函数+1个析构函数+n个赋值操作
//bad : w的覆盖范围更大，对程序理解造成冲击
//如果明确知道赋值成本比构造和析构低，采用这种方式
Widget w;
for (int i = 0; i < n; ++i)
{
	w = 取决于i的某个值;
}


//定义在循环内:n个构造函数+n个析构函数
//better
//n 比较大时，适合采用这种方式
for (int i = 0; i < n; ++i)
{
	Widget w = 取决于i的某个值;
}