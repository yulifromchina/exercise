//term14:����Դ�������У�С��copying��Ϊ


//background
void lock(Mutex * pm);
void unlock(Mutex * pm);

class Lock
{
public:
	explicit Mutex(Mutex * pm) :mutexPtr(pm)
	{
		lock(mutexPtr);
	}
	~Mutex() { unlock(mutexPtr); }
private:
	Mutex * mutexPtr;
};


//�����ڸ��Ʋ���ʱ���ᷢ��ʲô
Lock m11(&m);
Lock m12(m11);


//������4�ֿ��ܣ�����ǰ���ֳ���
//1:��ֹ����
class Lock : private Uncopyable
{

};

//2:�Եײ���Դʹ�����ü�����
class Lock
{
public:
	explicit Lock(Mutex * pm) :mutexPtr(pm, unlock)//���������������ü���Ϊ0ʱ���Զ�����ɾ����
	{
		lock(mutexPtr);
	}
private:
	std::shared_ptr<Mutex> mutexPtr;
};


//3:��ȿ��������Ƶײ���Դ

//4:ת�Ƶײ���Դ��ӵ��Ȩ������auto_ptr���е�׼��