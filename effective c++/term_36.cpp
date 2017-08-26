//term 36:绝不重新定义继承而来的non-virtual函数

//bad:
class B
{
public:
	void mf();
};
class D :public B
{
public:
	void mf();
};

B x;
B *pB = &x;//基类指针指向派生类对象，调用的是virutal函数的话，取决于所指的派生类对象(动态绑定)
D *pD = &x;
pB->mf();//调用non-virtual,则取决于指针---调用的是B::mf();
pD->mf();//调用的是D::mf();