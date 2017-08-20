#include "thread_binary_tree.h"

//前序创建二叉树
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



//中序遍历进行线索化
void in_threading(BTree root)
{

	if (root == NULL)
		return;
	in_threading(root->lchild);

	//没有左子树
	if (root->lchild == NULL)
	{
		root->ltag = Thread;
		root->lchild = pre;
	}

	//没有右子树
	if (pre->rchild == NULL)
	{
		pre->rtag = Thread;
		pre->rchild = root;
	}

	pre = root;

	in_threading(root->rchild);
}

//建立头结点，中序线索化二叉树
void inorder_thread_head(BTree * head, BTree root)
{
	(*head) = new BNode;
	assert(*head);

	//如果root不为空，(*head)->rchild最后将指向root的最后一个结点
	(*head)->rchild = *head;
	(*head)->rtag = Link;



	if (root == NULL)
	{
		//如果root为空，头结点的左孩子也指向自己
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





//中序遍历线索二叉树表示的二叉树
void inorder_travel(BTree root)
{
	if (root == NULL)
		return;

	BNode * node = root->lchild;//指向根结点
	while (node != root)
	{
		while (node->ltag == Link)//向左进入到中序遍历的第一个结点
		{
			node = node->lchild;
		}
		std::cout << node->data << "  ";

		while (node->rtag == Thread && node->rchild != root)//右结点是线索
		{
			node = node->rchild;
			std::cout << node->data << "  ";
		}

		node = node->rchild;
	}

}

//在中序线索二叉树里找到指定结点在后序的前驱结点的算法
//在后序序列中：
//1)若结点P有右孩子，则右孩子是其前驱
//2)若结点P有左孩子而无右孩子，则左孩子是其前驱
//3)若结点P均无左右孩子，设中序左线索指向某祖先结点f,若f有左孩子，则左孩子是P在后序遍历中的前驱
//4)若结点P均无左右孩子，设中序左线索指向某祖先结点f,若f无左孩子，则顺着前驱找到双亲，一直找到双亲有左子女
//5)特殊情况：P是中序遍历的第一个结点，则P在中序和后序遍历中均无前驱
BNode * in_post_pre(BNode * root, BNode * p)
{
	BNode * node;
	if (p->rtag == 0)
		node = p->rchild;
	else if (p->ltag == 0)
		node = p->lchild;
	else if (node->lchild == NULL)//情况5
		return NULL;
	else
	{
		//如果前驱没有左孩子，继续向上找
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