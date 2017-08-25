//term_15:在资源管理类中，提供对原始资源的访问


//background
std::tr1::shared_ptr<Investment> pInv(createInvestment());
int dayHeld(const Investment * pi);
int day = dayHeld(pInv);   //error: 需要取得原始指针


//way1:提供显示转换函数，以Font为例，原始指针为FontHandle类型：
class Font
{
public:
	FontHandle get() const { return f; };
};


//way2:提供隐式转换
class Font
{
public:
	operator FontHandle() const
	{
		return f;
	}
};