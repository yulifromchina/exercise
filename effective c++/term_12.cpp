//term12:
//1��дһ��copy����ʱ��ȷ����1���������е�local ������2)����base class���ʵ���copying����
//2��copy������copy assignment�������ظ��Ĵ��룬�����ظ��ķ�ʽ�ǣ��½�һ�����������ߵ���

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
	Date lastTransaction;//error:copy assignment��û�п����������
};



//bad
class PriorityCustomer :public Customer
{
public:
	PriorityCustomer & operator=(const PriorityCustomer&rhs)
	{
		logCall("PriorityCustomer copy assignment constructor");
		//bad: ����Ӧ�ü���base class�ĺ�����Customer::operator=(rhs);
		priority = rhs.priority;
		return *this;
	}
private:
	int priority;
};