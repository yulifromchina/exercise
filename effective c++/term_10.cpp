//��operator=����һ��reference to * this
//���Э�����������ø�ֵ�������

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
