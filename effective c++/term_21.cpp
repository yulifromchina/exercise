//term 21: ���뷵��һ���¶���ʱ���𷵻�reference


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
	Rational result(lhs.n * rhs.n, lhs.d*rhs.d);//error!result��local���󣬷��غ�ͱ�������
	return result;
}


//bad ,too
const Rational& operator* (const Rational &lhs, const Rational &rhs)
{
	Rational * result = new Rational(lhs.n * rhs.n, lhs.d*rhs.d);//error!result��local���󣬷��غ�ͱ�������
	return *result;//error! �޷�delete������Դй¶
}
Rational x, y, z, w;
w = x * y *z;//�������������new, ������Ҫ����delete������û�취��ȡ��Ҫ��ָ��


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
//error ��a*b, c*d���صĶ���static���ͣ�ʼ��ָ��ͬһ����������if�ж���ԶΪ��



//good
inline const Rational operator*(const Rational &lhs, const Rational &rhs)
{
	return Rational(lhs.n * rhs.n, lhs.d*rhs.d);
}