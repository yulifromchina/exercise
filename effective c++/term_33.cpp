//term 33: 避免遮掩继承而来的问题

class Base
{
private:
	int x;
public:
	virtual void mf1() = 0;
	virtual void mf1(int);
	virtual void mf2();
	void mf3();
	void mf3(double);
};

class Derived :public Base
{
public:
	virtual void mf1();//会遮掩Base中的mf1()和mf3()
	void mf3();
	void mf4();

	using Base::mf1();//让Base的mf1和mf3在Derived中可见
	using Base::mf3();
};