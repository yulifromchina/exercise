/*
简单工厂模式
*/
#include <iostream>
using namespace std;

enum CTYPE{COREA, COREB};
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
//唯一的工厂，在内部判断生产什么型号的处理器
class Factory
{
public:
	SingleCore * CreateCore(enum CTYPE ctype)//返回基类指针
	{
		if (ctype == COREA)
			return new SingleCoreA();
		else if (ctype == COREB)
			return new SingleCoreB();
		else
			return NULL;
	}
};

int main()
{
	//把需要生产的型号告诉唯一的工厂，让工厂生产
	CTYPE core = COREA;
	SingleCore * core_obj = (new Factory())->CreateCore(core);
	core_obj->Show();
	return 0;
}