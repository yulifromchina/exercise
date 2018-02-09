#include <iostream>
using namespace std;

//����������
class Phone
{
public:
	Phone() {}
	virtual void ShowDecorate() {}
	virtual	~Phone() {}
	//������鹹����Ӧ��ָ��Ϊ�麯��
	//���򵱻���ָ��ָ�����������ʱ��delete �ö����޷�������������鹹����
};

//������ֻ���
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

//װ����
class Decorator :public Phone
{
private:
	Phone * m_phone;
public:
	Decorator(Phone* phone) :m_phone(phone) {}
	void ShowDecorate() { m_phone->ShowDecorate(); }
};

//�����װ����:װ����������װ�εĽӿ�һ�£��������ʹ�ø�����Ŀͻ�͸��
class DecoratorA :public Decorator
{
private:
	void AddDecorate() { cout << "���ӹҼ�" << endl; }
public:
	DecoratorA(Phone * phone) :Decorator(phone) {}
	void ShowDecorate() { Decorator::ShowDecorate(); AddDecorate(); }
};

class DecoratorB :public Decorator
{
private:
	void AddDecorate() { cout << "��Ļ��Ĥ" << endl; }
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