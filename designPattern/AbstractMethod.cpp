/*
抽象工厂模式
*/

#include<iostream>
using namespace std;
//单核
class SingleCore
{
public:
	virtual void Show() = 0;
};
//单核A
class SingleCoreA:public SingleCore
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


//多核
class MultiCore
{
public:
	virtual void Show() = 0;
};
//多核A
class MultiCoreA :public MultiCore
{
public:
	void Show() { cout << "MultiCore A" << endl; }
};
//多核B
class MultiCoreB :public MultiCore
{
public:
	void Show() { cout << "MultiCore B" << endl; }
};

//工厂基类
class Factory
{
public:
	virtual	SingleCore * CreateSingleCore() = 0;
	virtual MultiCore * CreateMultiCore() = 0;
};
//工厂A，专门生产A型号的处理器
class FactoryA :public Factory
{
public:
	SingleCore * CreateSingleCore() { return new SingleCoreA(); }
	MultiCore * CreateMultiCore() { return new MultiCoreA(); }
};
//工厂B，专门生产B型号的处理器
class FactoryB :public Factory
{
public:
	SingleCore * CreateSingleCore() { return new SingleCoreB(); }
	MultiCore * CreateMultiCore() { return new MultiCoreB(); }
};

int main()
{
	SingleCore * sg_obj = (new FactoryA())->CreateSingleCore();
	MultiCore * mc_obj = (new FactoryB())->CreateMultiCore();
	sg_obj->Show();
	mc_obj->Show();
	sg_obj = (new FactoryB())->CreateSingleCore();
	mc_obj = (new FactoryB())->CreateMultiCore();
	sg_obj->Show();
	mc_obj->Show();
	return 0;
}