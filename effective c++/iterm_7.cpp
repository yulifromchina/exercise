//条款7
//base class应声明virtual函数
//不做base class则不应该声明，因为对象体积会增大


//bad
class TimeKeeper
{
public:
	TimeKeeper();
	~TimeKeeper();
};

class AtomicClock :public TimeKeeper {};
class WaterClock:public TimeKeeper{};
class WristClock :public TimeKeeper {};

TimeKeeper * getTimeKeeper();//工厂函数，返回TimeKeeper的派生类
TimeKeeper *ptk = getTimeKeeper();
delete ptk;//错误！由于基类的析构函数是non-virtual，析构时派生类的部分没有被释放掉


//better
class TimeKeeper
{
public:
	TimeKeeper();
	virtual ~TimeKeeper();//定义为虚函数
};
