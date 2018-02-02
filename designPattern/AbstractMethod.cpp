/*
���󹤳�ģʽ
*/

#include<iostream>
using namespace std;
//����
class SingleCore
{
public:
	virtual void Show() = 0;
};
//����A
class SingleCoreA:public SingleCore
{
public:
	void Show() { cout << "SingleCore A" << endl; }
};
//����B
class SingleCoreB :public SingleCore
{
public:
	void Show() { cout << "SingleCore B" << endl; }
};


//���
class MultiCore
{
public:
	virtual void Show() = 0;
};
//���A
class MultiCoreA :public MultiCore
{
public:
	void Show() { cout << "MultiCore A" << endl; }
};
//���B
class MultiCoreB :public MultiCore
{
public:
	void Show() { cout << "MultiCore B" << endl; }
};

//��������
class Factory
{
public:
	virtual	SingleCore * CreateSingleCore() = 0;
	virtual MultiCore * CreateMultiCore() = 0;
};
//����A��ר������A�ͺŵĴ�����
class FactoryA :public Factory
{
public:
	SingleCore * CreateSingleCore() { return new SingleCoreA(); }
	MultiCore * CreateMultiCore() { return new MultiCoreA(); }
};
//����B��ר������B�ͺŵĴ�����
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