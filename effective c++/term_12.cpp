//term12:
//1、写一个copy函数时，确保：1）复制所有的local 变量；2)调用base class中适当的copying函数
//2、copy函数和copy assignment函数有重复的代码，消除重复的方式是，新建一个函数供二者调用

#include <string>

//bad:
void logCall(const std::string & funName);
class Date {};
class Customer
{
public:
	Customer(const Customer & rhs)
	{
		logCall("Customer copy constructor");
	}
	Customer& operator=(const Customer & rhs)
	{
		logCall("Customer copy assignment constructor");
		name = rhs.name;
		return *this;
	}
private:
	std::string name;
	Date lastTransaction;//error:copy assignment中没有拷贝这个变量
};



//bad
class PriorityCustomer :public Customer
{
public:
	PriorityCustomer & operator=(const PriorityCustomer&rhs)
	{
		logCall("PriorityCustomer copy assignment constructor");
		//bad: 这里应该加上base class的函数：Customer::operator=(rhs);
		priority = rhs.priority;
		return *this;
	}
private:
	int priority;
};