//term 33: �������ڼ̳ж���������

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
	virtual void mf1();//������Base�е�mf1()��mf3()
	void mf3();
	void mf4();

	using Base::mf1();//��Base��mf1��mf3��Derived�пɼ�
	using Base::mf3();
};