//�ڹ���������ڼ䣬��Ҫ����virtual��������Ϊ������ôӲ��½���derived class


//bad
class Transaction
{
public:
	Transaction();
	virtual void logTransaction() const = 0;
};

Transaction::Transaction()
{
	logTransaction();
}

class BuyTransaction
{
public:
	virtual void logTransaction() const;
};

class SellTransaction
{
public:
	virtual void logTransaction() const;
};

BuyTransaction b;
//���ȵ���Transaction�Ĺ��캯������������������Transaction�������������麯�����Ҳ������壬�������ᱨ��

//better
class Transaction
{
public:
	Transaction();
	void logTransaction();//������Ϊ�麯��
};