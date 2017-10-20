//��ת����

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

Node * reverseList(Node * head)
{
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	Node * pre = head;
	Node * cur = head->next;
	Node * temp = NULL;
	while (cur)
	{
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	head->next = NULL;
	return pre;
}

int main()
{
	//test case 1:����Ϊ��
	Node * head = NULL;
	reverseList(head);
	printList(head);

	//test case 2:����ֻ��1�����
	Node * head1 = new Node(1);
	reverseList(head1);
	printList(head1);

	//test case 3:�����ж�����
	head1->next = new Node(2);
	head1->next->next = new Node(3);
	head1->next->next->next = new Node(4);
	head1->next->next->next->next = new Node(5);
	printList(head1);
	Node *result = reverseList(head1);
	printList(result);

	return 0;
}