#include <iostream>
using namespace std;

//����ӿ�
class ReplaceAlgorithm
{
public:
	virtual void Replace() = 0;
};

//���־�����滻�㷨
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


//ʹ��ģ��
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