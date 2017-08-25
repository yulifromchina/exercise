//term 20: 宁以pass-by-reference-to-const替换pass-by-value
//内置类型、函数、STL除外


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
//这个函数会导致1次Student对象的copy构造函数，一次Person对象的copy构造函数，4次string的copy构造函数
//以及相应的6次析构函数

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


//bad 调用的是base的display
void printName(Window w)
{
	w.display();
}

//better 调用的是derived的display
void printName(const Window & w)
{
	w.display();
}