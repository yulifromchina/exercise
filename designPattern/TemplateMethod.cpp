#include <iostream>
using namespace std;

//简历，基类
class Resume
{
public:
	virtual void SetPersonalInfo() {}
	virtual void SetEducation() {}
	virtual void SetWorkExp() {}
	void FillResume()
	{
		SetPersonalInfo();
		SetEducation();
		SetWorkExp();
	}
};

//应聘者A填写
class ResumeA :public Resume
{
public:
	void SetPersonalInfo() { cout << "A's personal Info" << endl; }
	void SetEducation() { cout << "A's Education Info" << endl; }
	void SetWorkExp() { cout << "A's WorkExp Info" << endl; }
};
//应聘者B填写
class ResumeB :public Resume
{
public:
	void SetPersonalInfo() { cout << "B's personal Info" << endl; }
	void SetEducation() { cout << "B's Education Info" << endl; }
	void SetWorkExp() { cout << "B's WorkExp Info" << endl; }
};


int main()
{
	Resume * r1;
	r1 = new ResumeA;
	//PS:加括号和不加括号的区别：
	//1.定义了构造函数，则加括号和不加都会调用构造函数
	//2,未定义构造函数，则加括号使用默认构造函数，不加则只分配内存，不初始化
	r1->FillResume();
	r1 = new ResumeB;
	r1->FillResume();
	delete r1;
	return 0;
}