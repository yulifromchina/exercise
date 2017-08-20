#include "thread_binary_tree.h"

//ǰ�򴴽�������
void create_tree(BTree * root)
{
	char ch;
	std::cin >> ch;
	if (ch == '#')
	{
		*root = NULL;
		return;
	}

	else
	{
		(*root) = new BNode;
		assert(*root);
		(*root)->data = ch;

		create_tree(&((*root)->lchild));
		create_tree(&((*root)->rchild));
	}

}



//�����������������
void in_threading(BTree root)
{

	if (root == NULL)
		return;
	in_threading(root->lchild);

	//û��������
	if (root->lchild == NULL)
	{
		root->ltag = Thread;
		root->lchild = pre;
	}

	//û��������
	if (pre->rchild == NULL)
	{
		pre->rtag = Thread;
		pre->rchild = root;
	}

	pre = root;

	in_threading(root->rchild);
}

//����ͷ��㣬����������������
void inorder_thread_head(BTree * head, BTree root)
{
	(*head) = new BNode;
	assert(*head);

	//���root��Ϊ�գ�(*head)->rchild���ָ��root�����һ�����
	(*head)->rchild = *head;
	(*head)->rtag = Link;



	if (root == NULL)
	{
		//���rootΪ�գ�ͷ��������Ҳָ���Լ�
		(*head)->lchild = *head;
		(*head)->ltag = Link;
	}
	else
	{
		pre = *head;
		(*head)->lchild = root;
		(*head)->ltag = Link;
		in_threading(root);
		pre->rchild = *head;
		pre->rtag = Thread;
		(*head)->rchild = pre;
	}
}





//�������������������ʾ�Ķ�����
void inorder_travel(BTree root)
{
	if (root == NULL)
		return;

	BNode * node = root->lchild;//ָ������
	while (node != root)
	{
		while (node->ltag == Link)//������뵽��������ĵ�һ�����
		{
			node = node->lchild;
		}
		std::cout << node->data << "  ";

		while (node->rtag == Thread && node->rchild != root)//�ҽ��������
		{
			node = node->rchild;
			std::cout << node->data << "  ";
		}

		node = node->rchild;
	}

}

//�������������������ҵ�ָ������ں����ǰ�������㷨
//�ں��������У�
//1)�����P���Һ��ӣ����Һ�������ǰ��
//2)�����P�����Ӷ����Һ��ӣ�����������ǰ��
//3)�����P�������Һ��ӣ�������������ָ��ĳ���Ƚ��f,��f�����ӣ���������P�ں�������е�ǰ��
//4)�����P�������Һ��ӣ�������������ָ��ĳ���Ƚ��f,��f�����ӣ���˳��ǰ���ҵ�˫�ף�һֱ�ҵ�˫��������Ů
//5)���������P����������ĵ�һ����㣬��P������ͺ�������о���ǰ��
BNode * in_post_pre(BNode * root, BNode * p)
{
	BNode * node;
	if (p->rtag == 0)
		node = p->rchild;
	else if (p->ltag == 0)
		node = p->lchild;
	else if (node->lchild == NULL)//���5
		return NULL;
	else
	{
		//���ǰ��û�����ӣ�����������
		p = p->lchild;
		while (p->ltag == 1 && p->lchild == NULL)
		{
			p = p->lchild;
		}
		if (p->ltag == 0 && p->lchild != NULL)
			node = p->lchild;
		else
			node = NULL;

	}
	return node;
}