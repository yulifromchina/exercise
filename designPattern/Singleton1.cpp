//˫���жϵ��̰߳�ȫ������ʽ����ģʽ

#include <iostream>
#include <mutex>
using namespace std;


mutex sg;

class Singleton
{
public:
	//��ȡʵ��
	static Singleton * getInstance()
	{
		if (NULL == instance)
		{
			//������ʹ֮�̰߳�ȫ
			//˫���жϣ�ʹ��Ҫ���ù��캯��ʱ�ż���������Ƶ����������;������ڵ�һ���жϣ���������߳�����
			sg.lock();
			if (NULL == instance)
			{
				instance = new Singleton();
			}
			sg.unlock();
		}
		return instance;
	}

	//�ڲ��࣬������ɾ�����������
	class Garbage
	{
	public:
		~Garbage()
		{
			if (Singleton::instance != NULL)
			{
				cout << "�������������Ψһʵ��" << endl;
				delete Singleton::instance;
			}
		}
	};
private:
	//����������
	int count = 0;
	//��̬ʵ��
	static Singleton * instance;
	//˽�й��캯��
	Singleton()
	{
		++count;
		cout << "ʵ������" << count << "������" << endl;
	}
	~Singleton()
	{
		cout << "Singleton��������ִ��" << endl;
	}
	//�ѿ������캯���͸�ֵ���������Ϊdelete����ֹ�����͸�ֵ
	Singleton(const Singleton & sg) = delete;
	Singleton & operator=(const Singleton&) = delete;


	//����һ���ڲ��ྲ̬��Ա�������ͷ���Դ
	static Garbage garbage;
};


//��ʼ��instance
Singleton * Singleton::instance = NULL;
//��ʼ��garbage
Singleton::Garbage Singleton::garbage;

int main()
{
	Singleton * a = Singleton::getInstance();
	Singleton * b = Singleton::getInstance();
	if (a == b)
		cout << "����ģʽ�����ɹ�" << endl;
	//Singleton c = *a;   //������ʼ���޷�ͨ������
	//*a = *b;  //��ֵ�޷�ͨ������
	return 0;
}