//������ջʵ�ֶ���
//ʵ�ֺ���appendTail
//ʵ�ֺ���deleteHead

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class MyQueue
{
public:
	MyQueue() {}
	~MyQueue() {}
	void appendTail(const T & elem);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};



int main()
{
	//test case:���յĶ������Ԫ��
	MyQueue<int> que;
	que.appendTail(1);

	//test case:���ǿյĶ������Ԫ��
	que.appendTail(2);
	que.appendTail(3);

	//test case:���ǿյĶ���ɾ��Ԫ��
	int elem = que.deleteHead();
	cout << "������:" <<elem<< endl;

	//test case:����ɾ��Ԫ��ֱ������Ϊ��
	elem = que.deleteHead();
	cout << "������:" << elem << endl;
	elem = que.deleteHead();
	cout << "������:" << elem << endl;

	//test case:���յĶ���ɾ��Ԫ��
	elem = que.deleteHead();
	cout << "������:" << elem << endl;

	return 0;
}



//��Ӻ��������Ԫ�ص�stack1
template<typename T>
void MyQueue<T>::appendTail(const T & elem)
{
	stack1.push(elem);
}



//���Ӻ��������س��ӵ�Ԫ��
template<typename T>
T MyQueue<T>::deleteHead()
{
	//���û��Ԫ��
	if (stack1.empty() && stack2.empty())
	{
		cout << "empty!" << endl;
		return static_cast<T>(0);
	}
		


	T elem;
	//����stack2��ջ��
	if (!stack2.empty())
	{
		elem = stack2.top();
		stack2.pop();
	}
	else
	{
		//��stack1�е�Ԫ�ص���stack2
		while (!stack1.empty())
		{
			T temp = stack1.top();
			stack1.pop();
			stack2.push(temp);
		}
		elem = stack2.top();
		stack2.pop();
	}
	return elem;
}
