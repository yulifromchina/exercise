//��ֹ����������Ĭ�Ϻ���

//way1:
class HomeForSale
{
public:
	//...
private:
	//���º���������private����ֻ����������
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
	//���������û���ĺ�����������ֻ����������
};