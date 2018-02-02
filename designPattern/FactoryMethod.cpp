/*
工厂方法模式
*/
#include <iostream>
using namespace std;

//单核基类
class SingleCore
{
public:
	virtual void Show() = 0;
};
//单核A
class SingleCoreA :public SingleCore
{
public:
	void Show() { cout << "SingleCore A" << endl; }
};
//单核B
class SingleCoreB :public SingleCore
{
public:
	void Show() { cout << "SingleCore B" << endl; }
};

//工厂基类
class Factory
{
public:
	virtual SingleCore * CreateSingleCore() = 0;
};
//生产A核的工厂
class FactoryA:public Factory
{
public:
	virtual SingleCore * CreateSingleCore()
	{
		return new SingleCoreA();
	}
};
//生产B核的工厂
class FactoryB :public Factory
{
public:
	virtual SingleCore * CreateSingleCore()
	{
		return new SingleCoreB();
	}
};


int main()
{
	//需要生产哪个核，就调用哪个核的工厂
	SingleCore * coreA = (new FactoryA())->CreateSingleCore();
	coreA->Show();
	SingleCore * coreB = (new FactoryB())->CreateSingleCore();
	coreB->Show();
	return 0;
}
