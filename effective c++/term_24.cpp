//term 24:�����ҪΪĳ�������Ĳ�����������ת������ô�������������non-member����




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
result = oneEight*2;//�ᷢ����ʽ����ת����2-->Rational����
result = 2 * oneEight;//����2��û����Ӧ�ĳ�Ա����operator*


//better:����Ϊnon-member����
//������Խ���public�ӿ���ɲ������򲻱ض���Ϊfriend����
const Rational operator*(const Rational & rhs, const Rational & lhs)
{
	return Rational(lhs.numberator * rhs.numberator, lhs.denominator * rhs.denominator);
}