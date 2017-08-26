//term 41:了解隐式接口和编译期多态



/***************************eg 1***********************************/
class Widget
{
public:
	Widget();
	virtual ~Widget();
	virtual std::size_t size() const;
	virtual void normalize();
	void swap(Widget & other);
};

//Widget接口是一个显示接口，因为Widget在源码中可见
//显示接口又函数的签名式构成：函数名称，参数类型，返回类型
void doProcess(Widget & w)
{
	if (w.size() > 0 && w != someNastyWidget)
	{
		Widget temp(w);
		temp.normalize();
		temp.swap(w);
	}
}

/***************************eg 2***********************************/
//隐式接口
//可以看出T的隐式接口的约束：必须提供size成员函数，支持operator!=等
template <typename T>
void doProcess(T &w)
{
	if (w.size() > 0 && w != someNastyWidget)
	{
		Widget temp(w);
		temp.normalize();
		temp.swap(w);
	}
}
