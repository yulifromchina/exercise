//禁止编译器生成默认函数

//way1:
class HomeForSale
{
public:
	//...
private:
	//以下函数定义在private，且只声明不定义
	HomeForSale(const HomeForSale&t);
	HomeForSale& operator=(const HomeForSale&);

};


//way2
class Uncopyable
{
protected:
	Uncopyable() {}
	~Uncopyable() {}
private:
	Uncopyable() { const Uncopyable& };
	Uncopyable& operator=(const Uncopyable&);
};

class HomeForSale:public Uncopyable
{
	//编译器调用基类的函数，而基类只声明不定义
};