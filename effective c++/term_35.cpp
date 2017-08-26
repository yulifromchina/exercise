//term 35: ����virtual����֮���ѡ��

/************************eg 1**************************/
//һ���̳���ϵ��base class ��򵥵�����

class GameCenter
{
public:
	virtual int healthValue();//����Ϊimpure virtual����ʱ����ָ������ȱʡ�㷨
};

//way1 :����non-virtual interface�ַ�ʵ��template methodģʽ
//��ƣ�����healthValue()Ϊpublic������������Ϊnon-virtual,������һ��private virtual����ʵ�ʵĹ���
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


//way2:����Function Pointerʵ��strategyģʽ
//������HealthValue�ĺ��������ⲿ��������
class GameCenter
{
public:
	GameCenter(HealthCalcFun fun = default_HealthFun) :healthFun(fun);//���캯�������Ǽ��㺯��
	int healthValue() const
	{
		return healthFunc(*this);
	}
private:
	HealthCalcFun healthFuc;//���㺯��
};