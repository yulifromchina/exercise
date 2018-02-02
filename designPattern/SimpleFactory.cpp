/*
�򵥹���ģʽ
*/
#include <iostream>
using namespace std;

enum CTYPE{COREA, COREB};
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
//Ψһ�Ĺ��������ڲ��ж�����ʲô�ͺŵĴ�����
class Factory
{
public:
	SingleCore * CreateCore(enum CTYPE ctype)//���ػ���ָ��
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
	//����Ҫ�������ͺŸ���Ψһ�Ĺ������ù�������
	CTYPE core = COREA;
	SingleCore * core_obj = (new Factory())->CreateCore(core);
	core_obj->Show();
	return 0;
}