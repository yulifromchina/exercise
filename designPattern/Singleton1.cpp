//双重判断的线程安全的懒汉式单例模式

#include <iostream>
#include <mutex>
using namespace std;


mutex sg;

class Singleton
{
public:
	//获取实例
	static Singleton * getInstance()
	{
		if (NULL == instance)
		{
			//加锁，使之线程安全
			//双重判断，使得要调用构造函数时才枷锁，避免频繁的锁争夺;如果加在第一处判断，容易造成线程阻塞
			sg.lock();
			if (NULL == instance)
			{
				instance = new Singleton();
			}
			sg.unlock();
		}
		return instance;
	}

	//内部类，作用是删除单例类对象
	class Garbage
	{
	public:
		~Garbage()
		{
			if (Singleton::instance != NULL)
			{
				cout << "析构单例对象的唯一实例" << endl;
				delete Singleton::instance;
			}
		}
	};
private:
	//计数器对象
	int count = 0;
	//静态实例
	static Singleton * instance;
	//私有构造函数
	Singleton()
	{
		++count;
		cout << "实例化了" << count << "个对象" << endl;
	}
	~Singleton()
	{
		cout << "Singleton析构函数执行" << endl;
	}
	//把拷贝构造函数和赋值运算符定义为delete来阻止拷贝和赋值
	Singleton(const Singleton & sg) = delete;
	Singleton & operator=(const Singleton&) = delete;


	//定义一个内部类静态成员，用于释放资源
	static Garbage garbage;
};


//初始化instance
Singleton * Singleton::instance = NULL;
//初始化garbage
Singleton::Garbage Singleton::garbage;

int main()
{
	Singleton * a = Singleton::getInstance();
	Singleton * b = Singleton::getInstance();
	if (a == b)
		cout << "单例模式创建成功" << endl;
	//Singleton c = *a;   //拷贝初始化无法通过编译
	//*a = *b;  //赋值无法通过编译
	return 0;
}