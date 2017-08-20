#pragma once

#include <iostream>
#include <cassert>


typedef enum { Link, Thread } PointerTag;

typedef struct BNode
{
	char data;
	struct BNode *lchild;
	struct BNode * rchild;
	PointerTag ltag;
	PointerTag rtag;

	struct BNode()
	{
		lchild = NULL;
		rchild = NULL;
		ltag = Link;
		rtag = Link;
	};
}BNode, *BTree;

extern BNode * pre;


//ǰ�򴴽�������
void create_tree(BTree * root);

//�����������������
void in_threading(BTree root);

//����ͷ��㣬����������������
void inorder_thread_head(BTree * head, BTree root);

//�������������������ʾ�Ķ�����
void inorder_travel(BTree root);

//�������������������ҵ�ָ������ں����ǰ�������㷨
BNode * in_post_pre(BNode * root, BNode * p);
