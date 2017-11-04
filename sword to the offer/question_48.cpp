//设计不能被继承的类

//把构造函数和析构函数设置为私有函数

class SealedClass
{
public:
	static SealedClass * GetInstance()
	{
		return new SealedClass();
	}
	static void DeleteInstance(SealedClass * instance)
	{
		delete instance;
	}
private:
	SealedClass() {}
	~SealedClass() {}
};

int main()
{
	SealedClass * s = SealedClass::GetInstance();
	SealedClass::DeleteInstance(s);
	return 0;
}