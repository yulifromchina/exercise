#include <iostream>
using namespace std;

//����������
class Resume
{
public:
	virtual void SetPersonalInfo() {}
	virtual void SetEducation() {}
	virtual void SetWorkExp() {}
	void FillResume()
	{
		SetPersonalInfo();
		SetEducation();
		SetWorkExp();
	}
};

//ӦƸ��A��д
class ResumeA :public Resume
{
public:
	void SetPersonalInfo() { cout << "A's personal Info" << endl; }
	void SetEducation() { cout << "A's Education Info" << endl; }
	void SetWorkExp() { cout << "A's WorkExp Info" << endl; }
};
//ӦƸ��B��д
class ResumeB :public Resume
{
public:
	void SetPersonalInfo() { cout << "B's personal Info" << endl; }
	void SetEducation() { cout << "B's Education Info" << endl; }
	void SetWorkExp() { cout << "B's WorkExp Info" << endl; }
};


int main()
{
	Resume * r1;
	r1 = new ResumeA;
	//PS:�����źͲ������ŵ�����
	//1.�����˹��캯����������źͲ��Ӷ�����ù��캯��
	//2,δ���幹�캯�����������ʹ��Ĭ�Ϲ��캯����������ֻ�����ڴ棬����ʼ��
	r1->FillResume();
	r1 = new ResumeB;
	r1->FillResume();
	delete r1;
	return 0;
}