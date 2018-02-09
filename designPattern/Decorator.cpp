#include <iostream>
using namespace std;

//公共抽象类
class Phone
{
public:
	Phone() {}
	virtual void ShowDecorate() {}
	virtual	~Phone() {}
	//基类的虚构函数应该指明为虚函数
	//否则当基类指针指向派生类对象时，delete 该对象无法调用派生类的虚构函数
};

//具体的手机类
class iPhone :public Phone
{
private:
	string m_name;
public:
	iPhone(string name) :m_name(name) {}
	~iPhone() {};
	void ShowDecorate() {}
};

class NokiaPhone :public Phone
{
private:
	string m_name;
public:
	NokiaPhone(string name) :m_name(name) {}
	~NokiaPhone() {};
	void ShowDecorate() {}
};

//装饰类
class Decorator :public Phone
{
private:
	Phone * m_phone;
public:
	Decorator(Phone* phone) :m_phone(phone) {}
	void ShowDecorate() { m_phone->ShowDecorate(); }
};

//具体的装饰类:装饰器与它所装饰的接口一致，因此它对使用该组件的客户透明
class DecoratorA :public Decorator
{
private:
	void AddDecorate() { cout << "增加挂件" << endl; }
public:
	DecoratorA(Phone * phone) :Decorator(phone) {}
	void ShowDecorate() { Decorator::ShowDecorate(); AddDecorate(); }
};

class DecoratorB :public Decorator
{
private:
	void AddDecorate() { cout << "屏幕贴膜" << endl; }
public:
	DecoratorB(Phone * phone) :Decorator(phone) {}
	void ShowDecorate() { Decorator::ShowDecorate(); AddDecorate(); }
};

int main()
{
	Phone * iphone = new iPhone("iphone5");
	Phone * dpa = new DecoratorA(iphone);
	Phone * dpb = new DecoratorB(iphone);
	dpa->ShowDecorate();
	dpb->ShowDecorate();
	delete dpa;
	delete dpb;
	delete iphone;
	return 0;
}