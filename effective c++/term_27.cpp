//term 27:��������ת�Ͷ���


//c++�ṩ4����ʽת��
//const_cast<T>(expression)��������ĳ��������Ƴ�
//dynamic_cast<T>(expression)���ڼ̳���ϵ�а�ȫ����ת��
//reinterpret_cast<T>(expression)��ִ�еͼ�ת�ͣ�����һ������תΪint
//static_cast<T>(expression):ǿ����ʽת��������non-constת��Ϊconst��doubleת��Ϊint


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
//����ø����onresize����
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