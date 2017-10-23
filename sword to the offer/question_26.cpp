//复杂链表的复制
//在复杂链表中，每个结点除了有一个next指针指向下一个结点外，还有一个指针指向链表的任意结点或者NULL

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

//第一步：复制链表
//原始链表：A->B->C->D...
//复制后:A->A'->B->B'->C->C'->D->D'...
void CloneNodes(ComplexNode * head)
{
	ComplexNode * node = head;
	while (node)
	{
		//每次复制一个结点
		ComplexNode * cloned_node = new ComplexNode(node->value);
		cloned_node->next = node->next;

		//将新结点插入在赋值的结点后面
		node->next = cloned_node;
		node = cloned_node->next;
	}
}


//第二步，让复制后的结点的random指针指向自身链表的正确位置
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


//第三步，把长链表拆成两个链表
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


//复制复杂链表
ComplexNode * Clone(ComplexNode * head)
{
	CloneNodes(head);
	ConnectRandomNodes(head);
	return ReconnectNodes(head);
}


//打印链表
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