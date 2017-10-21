//定义栈的数据结构，在该类型中实现一个能得到栈的最小元素的min函数
//push, pop, min的时间复杂度均为O(1)

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

	//压入栈的数字比之前的最小值大
	MyStack<int> mystack;
	mystack.Push(1);
	mystack.Push(2);
	cout << mystack.Min() << endl;

	//弹出栈的元素不是最小的数字
	mystack.Pop();
	cout << mystack.Min() << endl;

	//压入栈的数字比之前的最小值小
	MyStack<int> mystack1;
	mystack1.Push(3);
	mystack1.Push(2);
	cout << mystack1.Min() << endl;

	//弹出栈的元素是最小的数字
	mystack1.Pop();
	cout << mystack1.Min() << endl;

	return 0;
}
