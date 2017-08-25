//term_18：让接口容易被正确使用，不容易被误用


//bad
class Date
{
public:
	Date(int month, int day, int year);
};
//可能会有误用
Date d(2,30,1995);
Date d(30, 2, 1995);


//better
struct Day {
	explicit Day(int d):val(d){}
	int val;
};


struct Month {
	explicit Month(int d) :val(d) {}
	int val;
};

struct Year {
	explicit Year(int d) :val(d) {}
	int val;
};


//more better:以函数替换对象
class Month
{
public:
	static Month Jan() { return Month(1); }
	static Month Feb() { return Month(2); }
	//...
	static Month Dec() { return Month(12); }
private:
	explicit Month(int m);
};

Date d(Month::Mar(), Day(30), Year(1995));


//返回一个shared_ptr类型来避免cross-dll问题（在一个dll new的对象，不能在另一个dll手工释放）
std::shared_ptr<Investment> createInvestment()
{
	return std::shared_ptr<Investment>(new Stock);//
}
