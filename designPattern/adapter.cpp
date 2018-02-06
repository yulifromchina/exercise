#include <iostream>
using namespace std;

//˫�˶��У�����к�ջ��������ϵ
class Deque
{
public:
	void push_back() { cout << "push_back" << endl; }
	void push_front() { cout << "push_front" << endl; }
	void pop_back() { cout << "pop_back" << endl; }
	void pop_front() { cout << "pop_front" << endl; }
};

//˳������������к�ջ�Ǽ̳й�ϵ
class Sequence
{
public:
	virtual void push() = 0;
	virtual void pop() = 0;
};

//����
class Queue:public Sequence
{
public:
	void push() { _deque.push_back(); }
	void pop() { _deque.pop_front(); }
private:
	Deque _deque;
};

//ջ
class Stack :public Sequence
{
public:
	void push() { _deque.push_back(); }
	void pop() { _deque.pop_back(); }
private:
	Deque _deque;
};

int main()
{
	Sequence * sq1 = new Stack();
	Sequence * sq2 = new Queue();
	sq1->push(); sq1->pop();
	sq2->push(); sq2->pop();
	return 0;
}