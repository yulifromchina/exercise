//��O��1����ʱ����ɾ�������ָ��Ԫ��

#include <iostream>

using namespace std;


//������
struct Node
{
	int value;
	struct Node * next;
	Node(int _value) :value(_value), next(NULL)
	{

	}
};



//��ͷ��β��ӡ����
void printList(Node * head)
{
	while (head != NULL)
	{
		cout << head->value << "->";
		head = head->next;
	}
	cout << "NULL" << endl;
}


//��ӽ��
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


//ɾ�����
void deleteNode(Node ** head, Node * toDelete)
{
	if (*head == NULL || toDelete == NULL)
		return;

	//����ɾ����ͷ���
	if((*head)== toDelete)
	{
		*head = (*head)->next;
		delete toDelete;
	}
	//����ɾ����βԪ��
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
	//ɾ���м�Ԫ��
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
	//test:ɾ����������
	cout << "test case 1:" << endl;
	Node * head = NULL;
	deleteNode(&head, NULL);

	//test:ɾ��ֻ��һ��Ԫ�ص�������
	cout << "test case 2:" << endl;
	addNode(&head, 1);
	printList(head);
	deleteNode(&head, head);
	printList(head);

	//test:ɾ������ͷ���
	cout << "test case 3:" << endl;
	addNode(&head, 1);
	addNode(&head, 2);
	addNode(&head, 3);
	addNode(&head, 4);
	addNode(&head, 5);
	printList(head);
	deleteNode(&head, head);
	printList(head);

	//test:ɾ������β���
	cout << "test case 4:" << endl;
	Node * tail = head->next->next->next;
	deleteNode(&head, tail);
	printList(head);

	//test:ɾ�������м�Ԫ��
	cout << "test case 5:" << endl;
	deleteNode(&head, head->next);
	printList(head);
	
	//test:ɾ�������ڵĽ��
	cout << "test case 6:" << endl;
	Node * temp = new Node(11);
	Node * temp2 = new Node(12);
	temp->next = temp2;
	deleteNode(&head, temp);
	printList(head);

	return 0;
}