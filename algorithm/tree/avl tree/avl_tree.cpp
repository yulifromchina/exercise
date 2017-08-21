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
			if (x < T->Left->Element)//Problem: LL->Solution:R
				T = SingleRotateR(T);
			else  //Problem: LR->Solution: LR
				T = DoubleRotateLR(T);
		}
	}
	else if (x > T->Element)
	{
		T->Right = Insert(x, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (x > T->Right->Element)//Problem: RR->Solution:L
				T = SingleRotateL(T);
			else//Problem: RL->Solution:RL
				T = DoubleRotateRL(T);
		}
	}
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

AvlTree Delete(ElementType x, AvlTree T)
{
	if (T == NULL)
		return T;
	if (x < T->Element)
	{
		T->Left = Delete(x, T->Left);
		//在执行了Delete操作后，需要判断当前结点的平衡因子；由于删除是递归进行的，
		//所以每次遇到平衡因子为2的情况，则调整结点，一直到树根
		//
		//如果删除导致了树的不平衡
		if (2 == Height(T->Right) - Height(T->Left))
		{
			//可以看成是RL插入的情况
			if (T->Right->Left && (Height(T->Right->Left) > Height(T->Right->Right)))
				DoubleRotateRL(T);
			else
				//可以看出是RR插入的情况
				SingleRotateL(T);
		}
	}
	else if (x > T->Element)
	{
		T->Right = Delete(x, T->Right);
		//如果删除导致了树的不平衡
		if (2 == Height(T->Left) - Height(T->Right))
		{
			//可以看成是LR插入的情况
			if (T->Left->Right && (Height(T->Left->Right) > Height(T->Left->Left)))
				DoubleRotateLR(T);
			else
				//可以看出是LL插入的情况
				SingleRotateR(T);
		}
	}
	else
	{
		//当前结点为待删除的结点

		//当前结点有左右孩子
		if (T->Left &&T->Right)
		{
			//如果后继存在，把后继结点的值赋值给当前结点
			Position temp = FindSuccessor(T);
			if (temp != NULL)
			{
				T->Element = temp->Element;
				//在右子树中删除
				T->Right = Delete(temp->Element, T->Right);
				if (2 == Height(T->Left) - Height(T->Right))
				{
					if (T->Left->Right && (Height(T->Left->Right) > Height(T->Left->Left)))
						DoubleRotateLR(T);
					else
						SingleRotateR(T);
				}
			}
			//如果后继不存在，则使用前驱
			else
			{
				T->Element = temp->Element;
				temp = FindPrecursor(T);
				//在左子树中删除
				T->Left = Delete(temp->Element, T->Left);
				if (2 == Height(T->Right) - Height(T->Left))
				{
					if (T->Right->Left && (Height(T->Right->Left) > Height(T->Right->Right)))
						DoubleRotateRL(T);
					else
						SingleRotateL(T);
				}
			}
		}
		else
		{
			AvlTree temp = T;
			//当前结点没有左孩子
			if (T->Left == NULL)
			{
				T = T->Right;
			}
			//当前结点没有右孩子
			else if (T->Right == NULL)
			{
				T = T->Left;
			}
			delete temp;
			temp = NULL;
		}
	}
	if(T!=NULL)
		T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

Position FindPrecursor(Position T)
{
	if (T == NULL)
		return T;
	Position cur = T->Left;

	//找左子树中最大的结点
	if (cur != NULL)
	{
		while (cur->Right != NULL)
			cur = cur->Right;
	}
	return cur;

}

Position FindSuccessor(Position T)
{
	if (T == NULL)
		return T;
	Position cur = T->Right;

	//找右子树中最小的结点
	if (cur != NULL)
	{
		while (cur->Left != NULL)
			cur = cur->Left;
	}
	return cur;
}

void Free(AvlTree T)
{
	if (T == NULL)
		return;
	if (T->Left)
		Free(T->Left);
	if (T->Right)
		Free(T->Right);
	delete T;
	T = NULL;
}

bool IsAvl(AvlTree T)
{
	if (T == NULL)
		return true ;
	bool r1 = false;
	bool r2 = false;
	bool r3 = false;
	int dh = Height(T->Left) - Height(T->Right);
	if (dh <= 1 && dh >= -1)
		r1 = true;

	r2 = IsAvl(T->Left);
	r3 = IsAvl(T->Right);
	return r1 && r2 && r3;
}

void IsAvlTree(AvlTree T)
{
	if (IsAvl(T))
		std::cout << "This is avl tree." << std::endl;
	else
		std::cout << "not avl tree" << std::endl;
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
	std::cout << std::endl;
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

Position SingleRotateR(Position k2)
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


//和SingleRotateWithR对称
Position SingleRotateL(Position k2)
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
Position DoubleRotateLR(Position k3)
{
	k3->Left = SingleRotateL(k3->Left);
	return SingleRotateR(k3);
}


//和DoubleRotateLR对称
Position DoubleRotateRL(Position k3)
{
	k3->Right = SingleRotateR(k3->Right);
	return SingleRotateL(k3);
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
	IsAvlTree(T);
	T = Delete(7, T);
	PrintTree(T);
	IsAvlTree(T);

	
	Free(T);
	return 0;
}