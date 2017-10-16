//链表

#include <iostream>
#include <stack>

using namespace std;


//单个结点的定义
struct ListNode
{
	int value;
	ListNode* next;
};

//往链表的末尾添加一个结点
void addNode(ListNode ** head, int value)
{
	ListNode * new_node = new ListNode;
	new_node->next = NULL;
	new_node->value = value;

	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	ListNode * ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new_node;
}

//删除某个结点
void deleteNode(ListNode ** head, int value)
{
	if (*head == NULL)
		return;

	if ((*head)->value == value)
	{
		ListNode * temp = *head;
		*head = (*head)->next;
		delete temp;
	}

	ListNode * ptr = *head;
	while (ptr->next != NULL && ptr->next->value != value)
	{
		ptr = ptr->next;
	}

	if (ptr->next == NULL)
		return;
	else
	{
		ListNode * temp = ptr->next;
		ptr->next = ptr->next->next;
		delete temp;

	}
}

//顺序打印链表
void printList(ListNode * head)
{
	while (head != NULL)
	{
		cout << head->value << "->";
		head = head->next;
	}
	cout << "NULL" << endl;
	
}

//使用栈反向打印链表
void reversePrintListByStack(ListNode * head)
{
	if (head == NULL)
		return;

	stack<int> _stack;
	while (head != NULL)
	{
		_stack.push(head->value);
		head = head->next;
	}

	while (!_stack.empty())
	{
		cout << _stack.top() << "->";
		_stack.pop();
	}

	cout << "NULL" << endl;	
}

//使用递归反向打印链表
//当链表非常长的时候，会导致函数调用层级很深，从而可能导致函数调用栈溢出
//所以使用栈鲁棒性好些
void reversePrintRecursion(ListNode * head)
{
	if (head == NULL)
	{
		return;		
	}
	reversePrintRecursion(head->next);
	cout << " "<<head->value;
}

int main()
{
	ListNode * list1 = NULL;

	addNode(&list1, 1);
	addNode(&list1, 2);
	addNode(&list1, 3);
	addNode(&list1, 4);
	addNode(&list1, 5);
	addNode(&list1, 6);
	addNode(&list1, 7);
	addNode(&list1, 8);
	addNode(&list1, 9);
	addNode(&list1, 10);
	printList(list1);

	cout << "reverse print by stack:";
	reversePrintListByStack(list1);

	cout << "reverse print by recursion:";
	reversePrintRecursion(list1);
	cout << endl;

	cout << "delete first node:";
	deleteNode(&list1, 1);
	printList(list1);


	cout << "delete last node:";
	deleteNode(&list1, 10);
	printList(list1);

	cout << "delete middle node:";
	deleteNode(&list1, 5);
	printList(list1);

	cout << "delete invalid node:";
	deleteNode(&list1, 50);
	printList(list1);

	return 0;
}