//term 20: ����pass-by-reference-to-const�滻pass-by-value
//�������͡�������STL����


/*****************************eg 1*******************************/
//bad
#include <string>
class Person
{
public:
	Person();
	~Person();
private:
	std::string name;
	std::string address;
};

class Student :public Person
{
public:
	Student();
	~Student();
private:
	std::string schoolName;
	std::string schoolAddress;
};

bool validateStudent(Student s);
//��������ᵼ��1��Student�����copy���캯����һ��Person�����copy���캯����4��string��copy���캯��
//�Լ���Ӧ��6����������

//better
bool validateStudent(const Student &s);


/*****************************eg 2*******************************/
class Window
{
public:
	std::string name() const;
	virtual void display() const;
};

class WindowWithScorllBar:public Window
{
public:
	virtual void display() const;
};


//bad ���õ���base��display
void printName(Window w)
{
	w.display();
}

//better ���õ���derived��display
void printName(const Window & w)
{
	w.display();
}