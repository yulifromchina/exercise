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


//前序创建二叉树
void create_tree(BTree * root);

//中序遍历进行线索化
void in_threading(BTree root);

//建立头结点，中序线索化二叉树
void inorder_thread_head(BTree * head, BTree root);

//中序遍历线索二叉树表示的二叉树
void inorder_travel(BTree root);

//在中序线索二叉树里找到指定结点在后序的前驱结点的算法
BNode * in_post_pre(BNode * root, BNode * p);
