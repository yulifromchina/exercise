//在构造和析构期间，不要调用virtual函数，因为这类调用从不下降至derived class


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
//会先调用Transaction的构造函数和析构函数，由于Transaction的析构函数是虚函数，找不到定义，编译器会报错

//better
class Transaction
{
public:
	Transaction();
	void logTransaction();//不定义为虚函数
};