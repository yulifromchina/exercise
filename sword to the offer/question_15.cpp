//�����еĵ�����K�����


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


//���������еĵ�����K�����
Node * findKthFromTail(Node * head, int k)
{
	if (head == NULL || k<=0)
		return NULL;
	
	Node * ptr = head;
	while (ptr && k)
	{
		ptr = ptr->next;
		--k;
	}
	if (k != 0)
		return NULL;
	Node * p1 = head;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		p1 = p1->next;
	}
	return p1;
}

int main()
{
	//test case 1:������С��k
	cout << "test case 1:" << endl;
	Node * head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	printList(head);
	Node * temp = findKthFromTail(head, 8);
	if (temp)
		cout << temp->value << endl;

	//test case 2:����Ϊ��
	cout << "test case 2:" << endl;
	Node * head2 = NULL;
	printList(findKthFromTail(head2, 5));

	//test case 3:k=0
	cout << "test case 3:" << endl;
	temp = findKthFromTail(head, 0);
	if (temp)
		cout << temp->value << endl;

	//tset case 4:��������
	cout << "test case 4:" << endl;
	temp = findKthFromTail(head, 3);
	if (temp)
		cout << temp->value << endl;

	return 0;
}