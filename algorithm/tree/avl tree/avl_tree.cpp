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
		//����������һ�õ�������
		T = new AvlNode();
		assert(T);
		T->Element = x;
		return T;
	}
	else if (x < T->Element)
	{
		T->Left = Insert(x, T->Left);
		//��������Ĳ�ƽ��Ľ��
		//�߶Ȳ�ƽ��ʱ���ý������������߶Ȳ�Ϊ2
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
		//��ִ����Delete��������Ҫ�жϵ�ǰ����ƽ�����ӣ�����ɾ���ǵݹ���еģ�
		//����ÿ������ƽ������Ϊ2��������������㣬һֱ������
		//
		//���ɾ�����������Ĳ�ƽ��
		if (2 == Height(T->Right) - Height(T->Left))
		{
			//���Կ�����RL��������
			if (T->Right->Left && (Height(T->Right->Left) > Height(T->Right->Right)))
				DoubleRotateRL(T);
			else
				//���Կ�����RR��������
				SingleRotateL(T);
		}
	}
	else if (x > T->Element)
	{
		T->Right = Delete(x, T->Right);
		//���ɾ�����������Ĳ�ƽ��
		if (2 == Height(T->Left) - Height(T->Right))
		{
			//���Կ�����LR��������
			if (T->Left->Right && (Height(T->Left->Right) > Height(T->Left->Left)))
				DoubleRotateLR(T);
			else
				//���Կ�����LL��������
				SingleRotateR(T);
		}
	}
	else
	{
		//��ǰ���Ϊ��ɾ���Ľ��

		//��ǰ��������Һ���
		if (T->Left &&T->Right)
		{
			//�����̴��ڣ��Ѻ�̽���ֵ��ֵ����ǰ���
			Position temp = FindSuccessor(T);
			if (temp != NULL)
			{
				T->Element = temp->Element;
				//����������ɾ��
				T->Right = Delete(temp->Element, T->Right);
				if (2 == Height(T->Left) - Height(T->Right))
				{
					if (T->Left->Right && (Height(T->Left->Right) > Height(T->Left->Left)))
						DoubleRotateLR(T);
					else
						SingleRotateR(T);
				}
			}
			//�����̲����ڣ���ʹ��ǰ��
			else
			{
				T->Element = temp->Element;
				temp = FindPrecursor(T);
				//����������ɾ��
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
			//��ǰ���û������
			if (T->Left == NULL)
			{
				T = T->Right;
			}
			//��ǰ���û���Һ���
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

	//�������������Ľ��
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

	//������������С�Ľ��
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
��תǰ��
                    k2
				/       \
			   k1      subtree z
			/     \
     subtree x    subtree y

LL���뵽subtree x�к�R��ת��
��ת��

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

	//k1Ϊ�µĸ����
	return k1;
}


/*
��תǰ��
						k2
					/		\
			subtree x	      k1
							/   \
					subtree y	subtree z

RR���뵽subtree z��L��ת��
��ת��
						k1
					/		\
				  k2		subtree z
				/	\
		subtree x	subtree y

*/


//��SingleRotateWithR�Գ�
Position SingleRotateL(Position k2)
{
	Position k1;

	k1 = k2->Right;
	k2->Right = k1->Left;
	k1->Left = k2;

	k2->Height = Max(Height(k2->Left), Height(k2->Right)) + 1;
	k1->Height = Max(Height(k1->Left), Height(k1->Right)) + 1;

	//k1Ϊ�µĸ����
	return  k1;
}


/*
��תǰ��
							k3
						/		\
					k1			 \
				/		\		  \
		subtree x	  subtree y		subtree y
							
				

LR�����subtree y �󣬿��԰�subtree y������һ������������������
���Ϊ������ʽ��
							k3
						/		\
					k1			 \
				/		\		  \
			subtree a	  k2	subtree d
						/    \
				subtree b	subtree c


����LR��ת��

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


//��DoubleRotateLR�Գ�
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