//term14:在资源管理类中，小心copying行为


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


//当存在复制操作时，会发生什么
Lock m11(&m);
Lock m12(m11);


//有以下4种可能，其中前两种常用
//1:禁止复制
class Lock : private Uncopyable
{

};

//2:对底层资源使用引用计数法
class Lock
{
public:
	explicit Lock(Mutex * pm) :mutexPtr(pm, unlock)//析构函数会在引用计数为0时，自动调用删除器
	{
		lock(mutexPtr);
	}
private:
	std::shared_ptr<Mutex> mutexPtr;
};


//3:深度拷贝，复制底层资源

//4:转移底部资源的拥有权，例如auto_ptr奉行的准则