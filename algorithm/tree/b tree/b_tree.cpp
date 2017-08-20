#include "b_tree.h"

/*
创建一棵B树
tree： BTree * 类型空指针
arr[]: 要插入的关键字
length: arr[]长度
*/
void BTree_Create(BTree * tree, const KeyType arr[], int length)
{
	assert(tree);

	std::cout << "开始创建B树，关键字为：" << std::endl;
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;


	for (int i = 0; i < length; i++)
	{
		int pos = -1;
		BTree_Search(*tree, arr[i], &pos);
		if (pos == -1)
			BTree_Insert(tree, arr[i]);

	}

}


/*
在树中搜索关键字
输入：查找开始的结点tree, 关键字key, 用于返回关键字在结点位置的pos
输出：返回指向结点的指针，pos用于返回关键字在结点的位置
*/
BTNode * BTree_Search(BTree tree, KeyType key, int *pos)
{
	if (tree == NULL)
	{
		//std::cout << "树为空！" << std::endl;
		return tree;
	}
	return BTree_recursive_search(tree, key, pos);
}




/*
在树中递归寻找关键字：
输入：查找开始的结点tree, 关键字key, 用于返回关键字在结点位置的pos
输出：返回指向结点的指针，pos用于返回关键字在结点的位置
*/
BTNode *BTree_recursive_search(BTree tree, KeyType key, int *pos)
{
	if (tree == NULL)
		return tree;

	int i = 0;
	while (i < tree->key_num && key > tree->key[i])
		++i;

	//在当前结点找到了key
	if (i < tree->key_num && key == tree->key[i])
	{
		*pos = i;
		return tree;
	}

	//当前结点没有找到key

	//当前结点是叶结点所以无法递归查询
	if (tree->is_leaf == true)
	{
		*pos = -1;
		return NULL;
	}

	//在孩子结点中查询
	return BTree_recursive_search(tree->p_child[i], key, pos);
}


/*
在树中插入一个关键字Key
输入：树根指针tree, 待插入的关键字key
*/
void BTree_Insert(BTree * tree, int key)
{
	BTNode * root = *tree;
	if (root == NULL)
	{
		root = new BTNode(); 
		assert(root);

		root->is_leaf = true;
		root->key[0] = key;
		root->key_num = 1;

		*tree = root;
#ifdef DEBUG
		std::cout << "插入关键字: " << char(key) << " 成功" << std::endl;
#endif // DEBUG	

		return;
	}

	/*递归原则:不进入满的结点，即关键字树=ORDER-1*/
	/*递归原则:往下查找时，遇到每一个满结点，则分裂*/
	if (root->key_num == ORDER - 1)
	{
#ifdef DEBUG
		std::cout << "分裂前的树：" << std::endl;
		BTree_Print_Level(*tree, 1);
#endif // DEBUG
		BTNode * node = new BTNode();
		*tree = node;
		node->is_leaf = false;
		node->key_num = 0;
		node->p_child[0] = root;

		BTree_split_child(node,  0, root);

		BTree_insert_no_full(node, key);
		
	}
	else
	{
		BTree_insert_no_full(root, key);
	}

#ifdef DEBUG
	std::cout << "插入关键字: " << char(key) << " 成功" << std::endl;
#endif // DEBUG

}



/*
分裂node结点
输入：node结点的父结点parent, node结点是parent的第几个孩子:pos , 待分裂的结点node
输出：无，把node结点分为两个结点，并上升一个关键字到父结点
*/
void BTree_split_child(BTNode * parent, int pos, BTNode * node)
{

#ifdef  DEBUG
	std::cout << "分裂前的结点:";
	for (int i = 0; i < node->key_num; i++)
		std::cout << node->key[i];
	std::cout << std::endl;
#endif //  DEBUG

	assert(parent && node);

	//创建新结点，存储node结点的后半部分
	BTNode * new_node = new BTNode();
	assert(new_node);

	
	//node保留前BTree_D-1个关键字，第BTree_D关键字上升到父结点，BTrre_D之后的关键字拷贝给new_node
	//拷贝node后半部分关键字
	for (int i = BTree_D; i < node->key_num; i++)
	{
		new_node->key[i - BTree_D] = node->key[i];
		node->key[i] = 0;
	}
	new_node->key_num = BTree_D - 1;
	node->key_num = node->key_num - (BTree_D-1);

	//如果node不是叶结点，后半部分的指针也要拷贝给new_node
	if (node->is_leaf == false)
	{
		for (int i = BTree_D; i < ORDER; i++)
		{
			new_node->p_child[i - BTree_D] = node->p_child[i];
			node->p_child[i] = NULL;
		}
	}

	new_node->is_leaf = node->is_leaf;

	//调整父结点中的指针和关键字
	for (int i = parent->key_num; i > pos; i--)
	{
		parent->p_child[i + 1] = parent->p_child[i];
	}
	parent->p_child[pos + 1] = new_node;
	for (int i = parent->key_num - 1; i >= pos; i--)
	{
		parent->key[i + 1] = parent->key[i];
	}
	parent->key[pos] = node->key[BTree_D - 1];
	node->key[BTree_D - 1] = 0;
	parent->key_num++;
	node->key_num--;

	parent->is_leaf = false;

#ifdef DEBUG
	std::cout << "分裂后的父结点:";
	for (int i = 0; i < parent->key_num; i++)
		std::cout << parent->key[i];
	std::cout << std::endl;
	std::cout << "分裂后的结点:";
	for (int i = 0; i < node->key_num; i++)
		std::cout << node->key[i];
	std::cout << std::endl;
	std::cout << "分裂产生的新结点:";
	for (int i = 0; i < new_node->key_num; i++)
		std::cout << new_node->key[i];
	std::cout << std::endl;
#endif

}


/*
在一个不满的结点中插入关键字key
输入:待插入的结点node(其关键字个数小于ORDER-1), 待插入的关键字key
输出：无
*/
void BTree_insert_no_full(BTNode * node, int key)
{
	assert(node);

	//如果是叶子结点，则直接插入
	if (node->is_leaf == true)
	{
		int i = node->key_num - 1;
		while (i >= 0 && key < node->key[i])
		{
			node->key[i + 1] = node->key[i];
			i--;
		}
			
		node->key[i + 1] = key;
		node->key_num++;

	}
	//是内部结点,则找到要插入的结点位置
	else
	{
		int i = node->key_num - 1;

		while (i >= 0 && key < node->key[i])
		{
			i--;
		}
		if (key > node->key[i])
			i++;
		
		//如果待插入的结点已满，则先分裂
		if (node->p_child[i]->key_num == ORDER - 1)
		{
			BTree_split_child(node, i, node->p_child[i]);

			//如果待插入的关键字大于上升到父结点的关键字，则在关键字的右孩子中寻找
			if (key > node->key[i])
				i++;
		}
		
		BTree_insert_no_full(node->p_child[i], key);
	}

}


/*
DFS打印树
输入：tree 当前树根 
*/
void BTree_Print(BTNode * root)
{
	if (root == NULL)
		return;

	for (int i = 0; i < root->key_num; i++)
	{
		if (root->p_child[i] != NULL)
			BTree_Print(root->p_child[i]);
		std::cout << root->key[i] << " ";
	}
	if(root->p_child[root->key_num]!=NULL)
		BTree_Print(root->p_child[root->key_num]);
}




/*
按层打印树
输入：tree 当前树根， layer 当前层数
*/
void BTree_Print_Level(BTree tree, int layer)
{
	
	if (tree == NULL)
		return;

	std::cout << "第" << layer << "层结点: " ;
	for (int i = 0; i < tree->key_num; i++)
	{
		std::cout << tree->key[i] << " ";
	}
	std::cout << std::endl;
	layer++;
	for (int i = 0; i <= tree->key_num; i++)
	{
		if (tree->p_child[i])
			BTree_Print_Level(tree->p_child[i], layer);
	}
}


/*
删除树中的关键字
输入：树根tree, 待删除的关键字key
*/
void BTree_delete(BTree * tree, KeyType key)
{
	if (*tree == NULL)
		return;

	BTree_recursive_delete(tree, key);

}


/*
递归删除树中的关键字
递归删除的特性：不踏入关键字小于等于BTree_D-1的结点；要踏入前一定会先处理，问左右孩子借，借不到则合并左右孩子和父亲的一个关键字
输入：树根tree, 待删除的关键字key
*/
void BTree_recursive_delete(BTree * tree, KeyType key)
{
	if (*tree == NULL)
		return;

	BTNode * root = *tree;
	BTNode * node = root;

	int index = 0;
	//待删除的关键字在结点node中， 或者node->p_child[index]中
	while (index < node->key_num && key > node->key[index])
		index++;


	//待删除的结点在当前node中
	if (index < node->key_num && key == node->key[index])
	{
		//如果node是叶结点，直接删除关键字
		if (node->is_leaf == true)
		{
			for (int i = index; i < node->key_num-1; i++)
			{
				node->key[i] = node->key[i + 1];
			}
			node->key[node->key_num] = 0;
			node->key_num--;

			if (node->key_num == 0)
			{
				delete node;
				node = NULL;
			}
			return;
		}


		//node是内部结点
		BTNode * left_child, *right_child;
		KeyType predecessor, succesor;
		
		//待删除关键字的前驱（left_child中的最后一个关键字）上移到父结点
		if (node->p_child[index] && node->p_child[index]->key_num>BTree_D-1)
		{
			left_child = node->p_child[index];
			predecessor = left_child->key[left_child->key_num-1];
			node->key[index] = predecessor;

			BTree_recursive_delete(&left_child, predecessor);
		}
		//待删除关键字的后继(right_child中的第一个关键字)上移到父结点
		else if (node->p_child[index+1] && node->p_child[index+1]->key_num > BTree_D-1)
		{
			right_child = node->p_child[index + 1];
			succesor = right_child->key[0];
			node->key[index] = succesor;

			BTree_recursive_delete(&right_child, succesor);
		}
		//合并待删除关键字和left_child, right_child成一个结点
		//TIPS:为什么认为node->p_child[index]和node->p_child[index + 1]一定存在呢？由B树的特性，内部结点中，孩子
		//结点一定比关键字多1，所以node->key[index]存在的话，上述一定存在
		else if(node->p_child[index] && node->p_child[index]->key_num==BTree_D - 1
			&& node->p_child[index + 1] && node->p_child[index + 1]->key_num == BTree_D - 1)
		{

			BTree_Merge(tree, node, index);

			BTree_recursive_delete(&node->p_child[index], key);
		}

	}

	//待删除的结点不在当前node中
	else
	{
		BTNode * child = node->p_child[index];
		BTNode * left_sibling = NULL, *right_sibling = NULL;
		if (child == NULL)
			return;

		//如果child的关键字个数等于BTree_D-1,即B树结点关键字的最小值，则先处理
		if (child->key_num == BTree_D - 1)
		{
			if (index - 1 >= 0)
				left_sibling = node->p_child[index - 1];
			if (index + 1 <= node->key_num)
				right_sibling = node->p_child[index + 1];

			
			//优先从左兄弟借
			if (left_sibling && left_sibling->key_num > BTree_D - 1)
			{
				//child元素右移，空出位置为0处的key和p_child
				for (int i = child->key_num; i > 0; i--)
				{
					child->key[i] = child->key[i - 1];
					child->p_child[i + 1] = child->p_child[i];
				}
				child->p_child[1] = child->p_child[0];

				//左兄弟的最后一个孩子 移动到 child的第一个孩子；父结点的关键字下移到child的第一个关键字
				child->p_child[0] = left_sibling->p_child[left_sibling->key_num];
				child->key[0] = node->key[index - 1];
				child->key_num++;

				//左兄弟的最后一个关键字上移到父结点
				node->key[index - 1] = left_sibling->key[left_sibling->key_num - 1];

				//处理左兄弟的后续事宜
				left_sibling->key[left_sibling->key_num - 1] = 0;
				left_sibling->p_child[left_sibling->key_num] = NULL;
				left_sibling->key_num--;
			}
			//从右兄弟借
			else if (right_sibling && right_sibling->key_num > BTree_D - 1)
			{
				//右兄弟的第一个孩子 移动到 child的最后一个孩子；父结点关键字下移
				child->key[child->key_num] = node->key[index];
				child->p_child[child->key_num + 1] = right_sibling->p_child[0];
				child->key_num++;

				//右兄弟的第一个关键字上移到父结点
				node->key[index] = right_sibling->key[0];


				//处理右兄弟的后续事宜
				for (int i = 0; i < right_sibling->key_num-1; i++)
				{
					right_sibling->key[i] = right_sibling->key[i + 1];
					right_sibling->p_child[i] = right_sibling->p_child[i + 1];
				}
				right_sibling->p_child[right_sibling->key_num - 1] = right_sibling->p_child[right_sibling->key_num];

				right_sibling->key[right_sibling->key_num - 1] = 0;
				right_sibling->p_child[right_sibling->key_num] = NULL;
				right_sibling->key_num--;
			}
			//合并关键字和左右兄弟
			else
			{
				if (left_sibling &&left_sibling->key_num == BTree_D - 1)
				{
					BTree_Merge(tree, node, index-1);
					child = node->p_child[index - 1];
				}
				else if (right_sibling && right_sibling->key_num == BTree_D - 1)
				{
					BTree_Merge(tree, node, index);
				}
			}
		}


		//child的关键字个数大于BTree_D-1，可以递归删除
		BTree_recursive_delete(&child, key);	
		
	}
}



/*
合并操作：将node index+1处的孩子结点合并到index处的孩子结点，并下移index处的关键字
输入：parent :node的父结点   node:包含待删除关键字的结点   index:要删除的关键字为node->key[index]
*/
void BTree_Merge(BTree * parent, BTNode * node, int index)
{
	assert(parent && node && index >= 0 && index < node->key_num);

	KeyType key = node->key[index];
	BTNode * left_child = node->p_child[index];
	BTNode * right_child = node->p_child[index + 1];

	assert(left_child && right_child && left_child->key_num==BTree_D-1
	&&right_child->key_num==BTree_D-1);

	//将node中index处的关键字key下移到左孩子left_child中；右孩子中的第一个孩子指针移动到左孩子中去
	left_child->key[left_child->key_num] = key;
	left_child->p_child[left_child->key_num + 1] = right_child->p_child[0];
	left_child->key_num++;

	//右孩子关键字和指针合并到左孩子中
	for (int i = 0; i < right_child->key_num; i++)
	{
		left_child->key[left_child->key_num] = right_child->key[i];
		left_child->p_child[left_child->key_num + 1] = right_child->p_child[i + 1];
		left_child->key_num++;
	}

	//在node中下移的key后面的元素后移
	for (int i = index; i < node->key_num-1; i++)
	{
		node->key[i] = node->key[i + 1];
		node->p_child[i + 1] = node->p_child[i + 2];
	}

	node->key[node->key_num - 1] = 0;
	node->p_child[node->key_num] = NULL;
	node->key_num--;

	//如果node结点没有key了，就把父结点调整为合并后的左孩子结点
	if (node->key_num == 0)
	{
		*parent = left_child;
		delete left_child;
		left_child = NULL;
	}

	delete right_child;
	right_child = NULL;
}



	

