#include "avl_tree.h"

struct AvlNode
{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
	struct AvlNode()
	{
		Element = -1;
		Left = NULL;
		Right = NULL;
		Height = 0;
	}
};



AvlTree Insert(ElementType x, AvlTree T)
{
	if (T == NULL)
	{
		//创建并返回一棵单结点的树
		T = new AvlNode();
		assert(T);
		T->Element = x;
		return T;
	}
	else if (x < T->Element)
	{
		T->Left = Insert(x, T->Left);
		//调整最深的不平衡的结点
		//高度不平衡时，该结点的两棵子树高度差为2
		if (Height(T->Left) - Height(T->Right) == 2)
		{
			if (x < T->Left->Element)//LL->R
				T = SingleRotateWithLeft(T);
			else  //LR->RL
				T = DoubleRotateWithLeft(T);
		}
	}
	else if (x > T->Element)
	{
		T->Right = Insert(x, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (x > T->Right->Element)//RR->L
				T = SingleRotateWithRight(T);
			else//RL->LR
				T = DoubleRotateWithRight(T);
		}
	}
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

AvlTree Delete(ElementType x, AvlTree T)
{
	return AvlTree();
}

void PrintTree(AvlTree T)
{
	if (T == NULL)
		return;

	int pre_height = T->Height;
	std::queue<Position> queue_;
	Position cur = NULL;
	queue_.push(T);
	while (!queue_.empty())
	{
		cur = queue_.front();
		queue_.pop();

		std::cout << cur->Element << "("<<cur->Height<<") ";
		
		if (cur->Left)
			queue_.push(cur->Left);
		if (cur->Right)
			queue_.push(cur->Right);
	}

}

int Height(Position P)
{
	if (P == NULL)
		return -1;
	else
	{
		return P->Height;
	}
		
}

int Max(int a, int b)
{
	return ((a>b)?a:b);
}




/*
旋转前：
                    k2
				/       \
			   k1      subtree z
			/     \
     subtree x    subtree y

LL插入到subtree x中后，R旋转；
旋转后：

					k1
				/       \
		subtree x        k2
					 /       \
				subtree y	 subtree z
*/

Position SingleRotateWithLeft(Position k2)
{
	Position k1;

	k1 = k2->Left;
	k2->Left = k1->Right;
	k1->Right = k2;

	k2->Height = Max(Height(k2->Left), Height(k2->Right)) + 1;
	k1->Height = Max(Height(k1->Left), Height(k1->Right)) + 1;

	//k1为新的根结点
	return k1;
}


/*
旋转前：
						k2
					/		\
			subtree x	      k1
							/   \
					subtree y	subtree z

RR插入到subtree z后，L旋转；
旋转后：
						k1
					/		\
				  k2		subtree z
				/	\
		subtree x	subtree y

*/


//和SingleRotateWithLeft对称
Position SingleRotateWithRight(Position k2)
{
	Position k1;

	k1 = k2->Right;
	k2->Right = k1->Left;
	k1->Left = k2;

	k2->Height = Max(Height(k2->Left), Height(k2->Right)) + 1;
	k1->Height = Max(Height(k1->Left), Height(k1->Right)) + 1;

	//k1为新的根结点
	return  k1;
}


/*
旋转前：
							k3
						/		\
					k1			 \
				/		\		  \
		subtree x	  subtree y		subtree y
							
				

LR插入后subtree y 后，可以把subtree y看成右一个根结点和两棵子树；
则变为如下形式：
							k3
						/		\
					k1			 \
				/		\		  \
			subtree a	  k2	subtree d
						/    \
				subtree b	subtree c


进行LR旋转后：

							 k2
						/		   \
				    k1				   k3
				/		\		  /			\
		subtree A   subtree B   subtree C   subtree D
*/
Position DoubleRotateWithLeft(Position k3)
{
	k3->Left = SingleRotateWithRight(k3->Left);
	return SingleRotateWithLeft(k3);
}


//和DoubleRotateWithLeft对称
Position DoubleRotateWithRight(Position k3)
{
	k3->Right = SingleRotateWithLeft(k3->Right);
	return SingleRotateWithRight(k3);
}


int main()
{
	AvlTree T = NULL;
	T = Insert(3, T); 
	T= Insert(2, T); 
	T = Insert(1, T); 
	T = Insert(4, T);
	T = Insert(5, T); 
	T = Insert(6, T); 
	T = Insert(7, T); 
	T = Insert(16, T);
	T = Insert(15, T);
	T = Insert(14, T); 
	T = Insert(13, T); 
	T = Insert(12, T);
	T = Insert(11, T); 
	T = Insert(10, T); 
	T = Insert(8, T); 
	T = Insert(9, T);
	PrintTree(T);
	return 0;
}