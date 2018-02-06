#include <iostream>
using namespace std;

//抽象接口
class ReplaceAlgorithm
{
public:
	virtual void Replace() = 0;
};

//三种具体的替换算法
class LRT :public ReplaceAlgorithm
{
public:
	void Replace() { cout << "least recently used replace algorithm" << endl; }
};
class FIFO :public ReplaceAlgorithm
{
public:
	void Replace() { cout << "first in first out replace algorithm" << endl; }
};
class Random :public ReplaceAlgorithm
{
public:
	void Replace() { cout << "random replace algorithm" << endl; }
};


//使用模板
template<class RA>
class Cache
{
private:
	RA ra;
public:
	Cache() {}
	~Cache() {}
	void Replace() { ra.Replace(); }
};

int main()
{
	Cache<Random> cache;
	cache.Replace();
	return 0;
}