//条款11：在operator中处理自我赋值


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
	bp = new Bitmap(*rhs.bp);  //当自我赋值时，指针指向了一个被删除的对象
	return *this;
}

//way1:比较来源对象和目标对象的地址
Widget & Widget::operator=(const Widget& rhs)
{
	if (this == &rhs) return *this;
	delete bp;
	bp = new Bitmap(*rhs.bp);  //当自我赋值时，指针指向了一个被删除的对象
	return *this;
}


//way2:精心周到的语句顺序
Widget & Widget::operator=(const Widget& rhs)
{
	Bitmap *Org = bp;
	bp = new Bitmap(*rhs.bp);//复制时先别删除bp
	delete Org;
	return *this;
}

//way3:copy and swap
Widget & Widget::operator=(const Widget& rhs)
{
	Widget temp(rhs);
	swap(temp);//将*this和复制的数据交换
	return *this;
}