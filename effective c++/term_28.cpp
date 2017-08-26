//term 28:避免返回handles指向对象内部成分


//bad
class Rectangle
{
public:
	Point& upperleft() const { return PData->ulhc; }
	//返回一个内部数据的引用，但数据可能被获取方修改
};


//better
class Rectangle
{
public:
	const Point& upperleft() const { return PData->ulhc; }
	//不能被外部修改了，但是如果这个对象销毁了，可能导致外部指针悬空
};