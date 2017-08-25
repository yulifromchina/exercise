//term 21: 必须返回一个新对象时，别返回reference


//bad
class Rational
{
public:
	Rational(int num = 0, int dec = 1);
private:
	int n, d;
	friend const Rational& operator* (const Rational &lhs, const Rational &rhs);
};


const Rational& operator* (const Rational &lhs, const Rational &rhs)
{
	Rational result(lhs.n * rhs.n, lhs.d*rhs.d);//error!result是local对象，返回后就被销毁了
	return result;
}


//bad ,too
const Rational& operator* (const Rational &lhs, const Rational &rhs)
{
	Rational * result = new Rational(lhs.n * rhs.n, lhs.d*rhs.d);//error!result是local对象，返回后就被销毁了
	return *result;//error! 无法delete导致资源泄露
}
Rational x, y, z, w;
w = x * y *z;//这里进行了两次new, 所以需要两次delete，但是没办法获取需要的指针


//bad too
const Rational& operator* (const Rational &lhs, const Rational &rhs)
{
	static Rational result;
	//...
	return result;
}


Rational a, b, c, d;
if ((a*b) == (c*d)) {}
//...
//error ：a*b, c*d返回的都是static类型，始终指向同一个对象，所以if判断永远为真



//good
inline const Rational operator*(const Rational &lhs, const Rational &rhs)
{
	return Rational(lhs.n * rhs.n, lhs.d*rhs.d);
}