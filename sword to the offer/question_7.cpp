//用两个栈实现队列
//实现函数appendTail
//实现函数deleteHead

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
	//test case:往空的队列添加元素
	MyQueue<int> que;
	que.appendTail(1);

	//test case:往非空的队列添加元素
	que.appendTail(2);
	que.appendTail(3);

	//test case:往非空的队列删除元素
	int elem = que.deleteHead();
	cout << "出队列:" <<elem<< endl;

	//test case:连续删除元素直到队列为空
	elem = que.deleteHead();
	cout << "出队列:" << elem << endl;
	elem = que.deleteHead();
	cout << "出队列:" << elem << endl;

	//test case:往空的队列删除元素
	elem = que.deleteHead();
	cout << "出队列:" << elem << endl;

	return 0;
}



//入队函数，添加元素到stack1
template<typename T>
void MyQueue<T>::appendTail(const T & elem)
{
	stack1.push(elem);
}



//出队函数，返回出队的元素
template<typename T>
T MyQueue<T>::deleteHead()
{
	//如果没有元素
	if (stack1.empty() && stack2.empty())
	{
		cout << "empty!" << endl;
		return static_cast<T>(0);
	}
		


	T elem;
	//弹出stack2的栈顶
	if (!stack2.empty())
	{
		elem = stack2.top();
		stack2.pop();
	}
	else
	{
		//将stack1中的元素倒入stack2
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
