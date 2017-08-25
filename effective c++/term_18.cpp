//term_18���ýӿ����ױ���ȷʹ�ã������ױ�����


//bad
class Date
{
public:
	Date(int month, int day, int year);
};
//���ܻ�������
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


//more better:�Ժ����滻����
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


//����һ��shared_ptr����������cross-dll���⣨��һ��dll new�Ķ��󣬲�������һ��dll�ֹ��ͷţ�
std::shared_ptr<Investment> createInvestment()
{
	return std::shared_ptr<Investment>(new Stock);//
}
