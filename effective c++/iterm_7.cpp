//����7
//base classӦ����virtual����
//����base class��Ӧ����������Ϊ�������������


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

TimeKeeper * getTimeKeeper();//��������������TimeKeeper��������
TimeKeeper *ptk = getTimeKeeper();
delete ptk;//�������ڻ��������������non-virtual������ʱ������Ĳ���û�б��ͷŵ�


//better
class TimeKeeper
{
public:
	TimeKeeper();
	virtual ~TimeKeeper();//����Ϊ�麯��
};
