//在O（1）的时间内删除链表的指定元素

#include <iostream>

using namespace std;


//链表结点
struct Node
{
	int value;
	struct Node * next;
	Node(int _value) :value(_value), next(NULL)
	{

	}
};



//从头到尾打印链表
void printList(Node * head)
{
	while (head != NULL)
	{
		cout << head->value << "->";
		head = head->next;
	}
	cout << "NULL" << endl;
}


//添加结点
void addNode(Node ** head, int value)
{
	if (*head == NULL)
		*head = new Node(value);
	else
	{
		Node * ptr = *head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new Node(value);
	}
}


//删除结点
void deleteNode(Node ** head, Node * toDelete)
{
	if (*head == NULL || toDelete == NULL)
		return;

	//假设删除表头结点
	if((*head)== toDelete)
	{
		*head = (*head)->next;
		delete toDelete;
	}
	//假设删除表尾元素
	else if (toDelete->next == NULL)
	{
		Node * ptr = *head;
		while (ptr->next && ptr->next != toDelete)
			ptr = ptr->next;
		if (ptr->next == NULL)
			return;
		ptr->next = NULL;
		delete toDelete;
	}
	//删除中间元素
	else
	{
		toDelete->value = toDelete->next->value;
		Node * temp = toDelete->next;
		toDelete->next = temp->next;
		delete temp;
	}
}

int main()
{
	//test:删除空链表结点
	cout << "test case 1:" << endl;
	Node * head = NULL;
	deleteNode(&head, NULL);

	//test:删除只有一个元素的链表结点
	cout << "test case 2:" << endl;
	addNode(&head, 1);
	printList(head);
	deleteNode(&head, head);
	printList(head);

	//test:删除链表头结点
	cout << "test case 3:" << endl;
	addNode(&head, 1);
	addNode(&head, 2);
	addNode(&head, 3);
	addNode(&head, 4);
	addNode(&head, 5);
	printList(head);
	deleteNode(&head, head);
	printList(head);

	//test:删除链表尾结点
	cout << "test case 4:" << endl;
	Node * tail = head->next->next->next;
	deleteNode(&head, tail);
	printList(head);

	//test:删除链表中间元素
	cout << "test case 5:" << endl;
	deleteNode(&head, head->next);
	printList(head);
	
	//test:删除不存在的结点
	cout << "test case 6:" << endl;
	Node * temp = new Node(11);
	Node * temp2 = new Node(12);
	temp->next = temp2;
	deleteNode(&head, temp);
	printList(head);

	return 0;
}