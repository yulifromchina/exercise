/*
��������ģʽ
*/
#include <iostream>
using namespace std;

//���˻���
class SingleCore
{
public:
	virtual void Show() = 0;
};
//����A
class SingleCoreA :public SingleCore
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

//��������
class Factory
{
public:
	virtual SingleCore * CreateSingleCore() = 0;
};
//����A�˵Ĺ���
class FactoryA:public Factory
{
public:
	virtual SingleCore * CreateSingleCore()
	{
		return new SingleCoreA();
	}
};
//����B�˵Ĺ���
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
	//��Ҫ�����ĸ��ˣ��͵����ĸ��˵Ĺ���
	SingleCore * coreA = (new FactoryA())->CreateSingleCore();
	coreA->Show();
	SingleCore * coreB = (new FactoryB())->CreateSingleCore();
	coreB->Show();
	return 0;
}
