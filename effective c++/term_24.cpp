//term 24:如果需要为某个函数的参数进行类型转换，那么这个函数必须是non-member类型




class Rational
{
public:
	Rational(int numberator = 0, int denominator = 1);
	int numberator() const;
	int denominator() const;

	//bad
	const Rational operator*(const Rational &rhs) const;
};


//Problem1
Rational oneEight(1,8);
Rational oneHalf(1,2);
Rational result = oneEight * oneHalf;
result = oneEight*2;//会发生隐式类型转换，2-->Rational对象
result = 2 * oneEight;//错误，2并没有相应的成员函数operator*


//better:定义为non-member函数
//如果可以借由public接口完成操作，则不必定义为friend函数
const Rational operator*(const Rational & rhs, const Rational & lhs)
{
	return Rational(lhs.numberator * rhs.numberator, lhs.denominator * rhs.denominator);
}