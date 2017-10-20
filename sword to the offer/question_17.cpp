//�ϲ��������������

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


//�ϲ����������
Node * merge(Node * head1, Node *head2)
{
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return NULL;

	Node * result = NULL;

	if (head1->value < head2->value)
	{
		result = head1;
		result->next = merge(head1->next, head2);
	}
	else
	{
		result = head2;
		result->next = merge(head1, head2->next);
	}
	return result;
}

int main()
{
	Node * head1 = new Node(1);
	head1->next = new Node(3);
	head1->next->next = new Node(5);

	Node * head2 = new Node(1);
	head2->next = new Node(2);
	head2->next = new Node(6);

	Node *result = merge(head1, head2);
	printList(result);
	return 0;
}