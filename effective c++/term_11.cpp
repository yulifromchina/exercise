//����11����operator�д������Ҹ�ֵ


class Bitmap{};
class Widget
{
private:
	Widget & operator=(const Widget&);
	Bitmap * bp;
};




//bad
Widget & Widget::operator=(const Widget& rhs)
{
	delete bp;
	bp = new Bitmap(*rhs.bp);  //�����Ҹ�ֵʱ��ָ��ָ����һ����ɾ���Ķ���
	return *this;
}

//way1:�Ƚ���Դ�����Ŀ�����ĵ�ַ
Widget & Widget::operator=(const Widget& rhs)
{
	if (this == &rhs) return *this;
	delete bp;
	bp = new Bitmap(*rhs.bp);  //�����Ҹ�ֵʱ��ָ��ָ����һ����ɾ���Ķ���
	return *this;
}


//way2:�����ܵ������˳��
Widget & Widget::operator=(const Widget& rhs)
{
	Bitmap *Org = bp;
	bp = new Bitmap(*rhs.bp);//����ʱ�ȱ�ɾ��bp
	delete Org;
	return *this;
}

//way3:copy and swap
Widget & Widget::operator=(const Widget& rhs)
{
	Widget temp(rhs);
	swap(temp);//��*this�͸��Ƶ����ݽ���
	return *this;
}