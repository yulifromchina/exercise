//term_15:����Դ�������У��ṩ��ԭʼ��Դ�ķ���


//background
std::tr1::shared_ptr<Investment> pInv(createInvestment());
int dayHeld(const Investment * pi);
int day = dayHeld(pInv);   //error: ��Ҫȡ��ԭʼָ��


//way1:�ṩ��ʾת����������FontΪ����ԭʼָ��ΪFontHandle���ͣ�
class Font
{
public:
	FontHandle get() const { return f; };
};


//way2:�ṩ��ʽת��
class Font
{
public:
	operator FontHandle() const
	{
		return f;
	}
};