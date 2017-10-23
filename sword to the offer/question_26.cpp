//��������ĸ���
//�ڸ��������У�ÿ����������һ��nextָ��ָ����һ������⣬����һ��ָ��ָ����������������NULL

#include <iostream>

struct ComplexNode
{
	int value;
	ComplexNode * next;
	ComplexNode * random;
	ComplexNode(int _value) :value(_value)
	{
		next = NULL;
		random = NULL;
	}
};

//��һ������������
//ԭʼ����A->B->C->D...
//���ƺ�:A->A'->B->B'->C->C'->D->D'...
void CloneNodes(ComplexNode * head)
{
	ComplexNode * node = head;
	while (node)
	{
		//ÿ�θ���һ�����
		ComplexNode * cloned_node = new ComplexNode(node->value);
		cloned_node->next = node->next;

		//���½������ڸ�ֵ�Ľ�����
		node->next = cloned_node;
		node = cloned_node->next;
	}
}


//�ڶ������ø��ƺ�Ľ���randomָ��ָ�������������ȷλ��
void ConnectRandomNodes(ComplexNode * head)
{
	ComplexNode * node = head;
	while (node)
	{
		ComplexNode * cloned_node = node->next;
		if (node->random)
			cloned_node->random = node->random->next;
		node = cloned_node->next;
	}
}


//���������ѳ���������������
ComplexNode * ReconnectNodes(ComplexNode * head)
{
	if (head == NULL || head->next==NULL)
		return NULL;

	ComplexNode * cloned_node = head->next;
	ComplexNode * cloned_head = head->next;

	while (cloned_node->next)
	{
		cloned_node->next = cloned_node->next->next;
		cloned_node = cloned_node->next;
	}

	return cloned_head;
}


//���Ƹ�������
ComplexNode * Clone(ComplexNode * head)
{
	CloneNodes(head);
	ConnectRandomNodes(head);
	return ReconnectNodes(head);
}


//��ӡ����
void PrintList(ComplexNode * head)
{
	ComplexNode * node = head;
	while (node)
	{
		std::cout << node->value << " ";
		node = node->next;
	}
	std::cout << std::endl;
}



int main()
{
	ComplexNode * head = new ComplexNode(1);
	head->next = new ComplexNode(2);
	head->next->next = new ComplexNode(3);
	head->next->next->next = new ComplexNode(4);
	PrintList(head);

	ComplexNode * cloned_head = Clone(head);
	PrintList(cloned_head);
	return 0;
}