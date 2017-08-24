//令operator=返回一个reference to * this
//这个协议适用于所用赋值相关运算

class Widget
{
public:
	Widget & operator=(const Widget& rhs)
	{
		return *this;
	}
	Widget & operator+=(const Widget& rhs)
	{
		return *this;
	}
};
