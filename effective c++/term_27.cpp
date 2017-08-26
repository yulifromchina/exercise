//term 27:尽量少做转型动作


//c++提供4种新式转型
//const_cast<T>(expression)：将对象的常量特性移除
//dynamic_cast<T>(expression)：在继承体系中安全向下转型
//reinterpret_cast<T>(expression)：执行低级转型，例如一个对象转为int
//static_cast<T>(expression):强迫隐式转换，例如non-const转化为const，double转换为int


/***************************eg1***************************/
class Widget
{
public:
	explicit Widget(int size);
};

void doSomething(const Widget &w);
doSomething(Widget(15));//ok
doSomething(static_cast<Widget>(15));//more better


/***************************eg2***************************/
//想调用父类的onresize函数
class Window
{
public:
	virtual void onresize();
};
class SpecialWindow :public Window
{
public:
	virtual void onresize()
	{
		static_cast<Window>(*this).onresize();//error
	}
};

//current
class SpecialWindow :public Window
{
public:
	virtual void onresize()
	{
		Window::onresize();
	}
};