//����ջ�����ݽṹ���ڸ�������ʵ��һ���ܵõ�ջ����СԪ�ص�min����
//push, pop, min��ʱ�临�ӶȾ�ΪO(1)

#include <iostream>
#include <stack>
#include <cassert>

template <typename T>
class MyStack
{
public:
	MyStack<T>() {}
	~MyStack<T>() {}
	void Push(const T value);
	void Pop();
	T Min();


private:
	std::stack<T> m_data;
	std::stack<T> m_min;
};


template<typename T>
void MyStack<T>::Push(const T value)
{
	m_data.push(value);
	if (m_min.empty() || m_min.top() >= value)
		m_min.push(value);
	else
		m_min.push(m_min.top());
}


template<typename T>
void MyStack<T>::Pop()
{
	if (m_min.empty() || m_data.empty())
		return;
	m_data.pop();
	m_min.pop();
}

template<typename T>
T MyStack<T>::Min()
{
	if (m_min.empty())
		return -1;
	return m_min.top();
}

int main()
{
	using namespace std;

	//ѹ��ջ�����ֱ�֮ǰ����Сֵ��
	MyStack<int> mystack;
	mystack.Push(1);
	mystack.Push(2);
	cout << mystack.Min() << endl;

	//����ջ��Ԫ�ز�����С������
	mystack.Pop();
	cout << mystack.Min() << endl;

	//ѹ��ջ�����ֱ�֮ǰ����СֵС
	MyStack<int> mystack1;
	mystack1.Push(3);
	mystack1.Push(2);
	cout << mystack1.Min() << endl;

	//����ջ��Ԫ������С������
	mystack1.Pop();
	cout << mystack1.Min() << endl;

	return 0;
}
