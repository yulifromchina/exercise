//term 35: 考虑virtual函数之外的选择

/************************eg 1**************************/
//一个继承体系的base class 最简单的做法

class GameCenter
{
public:
	virtual int healthValue();//定义为impure virtual，按时健康指数会有缺省算法
};

//way1 :借由non-virtual interface手法实现template method模式
//设计：保留healthValue()为public函数，但设置为non-virtual,并调用一个private virtual进行实际的工作
class GameCenter
{
public:
	int healthValue() const
	{
		int retVal = doHealthValue();
		return retVal;
	}
private:
	virtual int doHealthValue() const
	{

	}
};


//way2:借由Function Pointer实现strategy模式
//将计算HealthValue的函数交由外部函数计算
class GameCenter
{
public:
	GameCenter(HealthCalcFun fun = default_HealthFun) :healthFun(fun);//构造函数参数是计算函数
	int healthValue() const
	{
		return healthFunc(*this);
	}
private:
	HealthCalcFun healthFuc;//计算函数
};