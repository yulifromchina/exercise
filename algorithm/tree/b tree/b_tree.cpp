#include "b_tree.h"

/*
����һ��B��
tree�� BTree * ���Ϳ�ָ��
arr[]: Ҫ����Ĺؼ���
length: arr[]����
*/
void BTree_Create(BTree * tree, const KeyType arr[], int length)
{
	assert(tree);

	std::cout << "��ʼ����B�����ؼ���Ϊ��" << std::endl;
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
�����������ؼ���
���룺���ҿ�ʼ�Ľ��tree, �ؼ���key, ���ڷ��عؼ����ڽ��λ�õ�pos
���������ָ�����ָ�룬pos���ڷ��عؼ����ڽ���λ��
*/
BTNode * BTree_Search(BTree tree, KeyType key, int *pos)
{
	if (tree == NULL)
	{
		//std::cout << "��Ϊ�գ�" << std::endl;
		return tree;
	}
	return BTree_recursive_search(tree, key, pos);
}




/*
�����еݹ�Ѱ�ҹؼ��֣�
���룺���ҿ�ʼ�Ľ��tree, �ؼ���key, ���ڷ��عؼ����ڽ��λ�õ�pos
���������ָ�����ָ�룬pos���ڷ��عؼ����ڽ���λ��
*/
BTNode *BTree_recursive_search(BTree tree, KeyType key, int *pos)
{
	if (tree == NULL)
		return tree;

	int i = 0;
	while (i < tree->key_num && key > tree->key[i])
		++i;

	//�ڵ�ǰ����ҵ���key
	if (i < tree->key_num && key == tree->key[i])
	{
		*pos = i;
		return tree;
	}

	//��ǰ���û���ҵ�key

	//��ǰ�����Ҷ��������޷��ݹ��ѯ
	if (tree->is_leaf == true)
	{
		*pos = -1;
		return NULL;
	}

	//�ں��ӽ���в�ѯ
	return BTree_recursive_search(tree->p_child[i], key, pos);
}


/*
�����в���һ���ؼ���Key
���룺����ָ��tree, ������Ĺؼ���key
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
		std::cout << "����ؼ���: " << char(key) << " �ɹ�" << std::endl;
#endif // DEBUG	

		return;
	}

	/*�ݹ�ԭ��:���������Ľ�㣬���ؼ�����=ORDER-1*/
	/*�ݹ�ԭ��:���²���ʱ������ÿһ������㣬�����*/
	if (root->key_num == ORDER - 1)
	{
#ifdef DEBUG
		std::cout << "����ǰ������" << std::endl;
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
	std::cout << "����ؼ���: " << char(key) << " �ɹ�" << std::endl;
#endif // DEBUG

}



/*
����node���
���룺node���ĸ����parent, node�����parent�ĵڼ�������:pos , �����ѵĽ��node
������ޣ���node����Ϊ������㣬������һ���ؼ��ֵ������
*/
void BTree_split_child(BTNode * parent, int pos, BTNode * node)
{

#ifdef  DEBUG
	std::cout << "����ǰ�Ľ��:";
	for (int i = 0; i < node->key_num; i++)
		std::cout << node->key[i];
	std::cout << std::endl;
#endif //  DEBUG

	assert(parent && node);

	//�����½�㣬�洢node���ĺ�벿��
	BTNode * new_node = new BTNode();
	assert(new_node);

	
	//node����ǰBTree_D-1���ؼ��֣���BTree_D�ؼ�������������㣬BTrre_D֮��Ĺؼ��ֿ�����new_node
	//����node��벿�ֹؼ���
	for (int i = BTree_D; i < node->key_num; i++)
	{
		new_node->key[i - BTree_D] = node->key[i];
		node->key[i] = 0;
	}
	new_node->key_num = BTree_D - 1;
	node->key_num = node->key_num - (BTree_D-1);

	//���node����Ҷ��㣬��벿�ֵ�ָ��ҲҪ������new_node
	if (node->is_leaf == false)
	{
		for (int i = BTree_D; i < ORDER; i++)
		{
			new_node->p_child[i - BTree_D] = node->p_child[i];
			node->p_child[i] = NULL;
		}
	}

	new_node->is_leaf = node->is_leaf;

	//����������е�ָ��͹ؼ���
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
	std::cout << "���Ѻ�ĸ����:";
	for (int i = 0; i < parent->key_num; i++)
		std::cout << parent->key[i];
	std::cout << std::endl;
	std::cout << "���Ѻ�Ľ��:";
	for (int i = 0; i < node->key_num; i++)
		std::cout << node->key[i];
	std::cout << std::endl;
	std::cout << "���Ѳ������½��:";
	for (int i = 0; i < new_node->key_num; i++)
		std::cout << new_node->key[i];
	std::cout << std::endl;
#endif

}


/*
��һ�������Ľ���в���ؼ���key
����:������Ľ��node(��ؼ��ָ���С��ORDER-1), ������Ĺؼ���key
�������
*/
void BTree_insert_no_full(BTNode * node, int key)
{
	assert(node);

	//�����Ҷ�ӽ�㣬��ֱ�Ӳ���
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
	//���ڲ����,���ҵ�Ҫ����Ľ��λ��
	else
	{
		int i = node->key_num - 1;

		while (i >= 0 && key < node->key[i])
		{
			i--;
		}
		if (key > node->key[i])
			i++;
		
		//���������Ľ�����������ȷ���
		if (node->p_child[i]->key_num == ORDER - 1)
		{
			BTree_split_child(node, i, node->p_child[i]);

			//���������Ĺؼ��ִ��������������Ĺؼ��֣����ڹؼ��ֵ��Һ�����Ѱ��
			if (key > node->key[i])
				i++;
		}
		
		BTree_insert_no_full(node->p_child[i], key);
	}

}


/*
DFS��ӡ��
���룺tree ��ǰ���� 
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
�����ӡ��
���룺tree ��ǰ������ layer ��ǰ����
*/
void BTree_Print_Level(BTree tree, int layer)
{
	
	if (tree == NULL)
		return;

	std::cout << "��" << layer << "����: " ;
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
ɾ�����еĹؼ���
���룺����tree, ��ɾ���Ĺؼ���key
*/
void BTree_delete(BTree * tree, KeyType key)
{
	if (*tree == NULL)
		return;

	BTree_recursive_delete(tree, key);

}


/*
�ݹ�ɾ�����еĹؼ���
�ݹ�ɾ�������ԣ���̤��ؼ���С�ڵ���BTree_D-1�Ľ�㣻Ҫ̤��ǰһ�����ȴ��������Һ��ӽ裬�費����ϲ����Һ��Ӻ͸��׵�һ���ؼ���
���룺����tree, ��ɾ���Ĺؼ���key
*/
void BTree_recursive_delete(BTree * tree, KeyType key)
{
	if (*tree == NULL)
		return;

	BTNode * root = *tree;
	BTNode * node = root;

	int index = 0;
	//��ɾ���Ĺؼ����ڽ��node�У� ����node->p_child[index]��
	while (index < node->key_num && key > node->key[index])
		index++;


	//��ɾ���Ľ���ڵ�ǰnode��
	if (index < node->key_num && key == node->key[index])
	{
		//���node��Ҷ��㣬ֱ��ɾ���ؼ���
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


		//node���ڲ����
		BTNode * left_child, *right_child;
		KeyType predecessor, succesor;
		
		//��ɾ���ؼ��ֵ�ǰ����left_child�е����һ���ؼ��֣����Ƶ������
		if (node->p_child[index] && node->p_child[index]->key_num>BTree_D-1)
		{
			left_child = node->p_child[index];
			predecessor = left_child->key[left_child->key_num-1];
			node->key[index] = predecessor;

			BTree_recursive_delete(&left_child, predecessor);
		}
		//��ɾ���ؼ��ֵĺ��(right_child�еĵ�һ���ؼ���)���Ƶ������
		else if (node->p_child[index+1] && node->p_child[index+1]->key_num > BTree_D-1)
		{
			right_child = node->p_child[index + 1];
			succesor = right_child->key[0];
			node->key[index] = succesor;

			BTree_recursive_delete(&right_child, succesor);
		}
		//�ϲ���ɾ���ؼ��ֺ�left_child, right_child��һ�����
		//TIPS:Ϊʲô��Ϊnode->p_child[index]��node->p_child[index + 1]һ�������أ���B�������ԣ��ڲ�����У�����
		//���һ���ȹؼ��ֶ�1������node->key[index]���ڵĻ�������һ������
		else if(node->p_child[index] && node->p_child[index]->key_num==BTree_D - 1
			&& node->p_child[index + 1] && node->p_child[index + 1]->key_num == BTree_D - 1)
		{

			BTree_Merge(tree, node, index);

			BTree_recursive_delete(&node->p_child[index], key);
		}

	}

	//��ɾ���Ľ�㲻�ڵ�ǰnode��
	else
	{
		BTNode * child = node->p_child[index];
		BTNode * left_sibling = NULL, *right_sibling = NULL;
		if (child == NULL)
			return;

		//���child�Ĺؼ��ָ�������BTree_D-1,��B�����ؼ��ֵ���Сֵ�����ȴ���
		if (child->key_num == BTree_D - 1)
		{
			if (index - 1 >= 0)
				left_sibling = node->p_child[index - 1];
			if (index + 1 <= node->key_num)
				right_sibling = node->p_child[index + 1];

			
			//���ȴ����ֵܽ�
			if (left_sibling && left_sibling->key_num > BTree_D - 1)
			{
				//childԪ�����ƣ��ճ�λ��Ϊ0����key��p_child
				for (int i = child->key_num; i > 0; i--)
				{
					child->key[i] = child->key[i - 1];
					child->p_child[i + 1] = child->p_child[i];
				}
				child->p_child[1] = child->p_child[0];

				//���ֵܵ����һ������ �ƶ��� child�ĵ�һ�����ӣ������Ĺؼ������Ƶ�child�ĵ�һ���ؼ���
				child->p_child[0] = left_sibling->p_child[left_sibling->key_num];
				child->key[0] = node->key[index - 1];
				child->key_num++;

				//���ֵܵ����һ���ؼ������Ƶ������
				node->key[index - 1] = left_sibling->key[left_sibling->key_num - 1];

				//�������ֵܵĺ�������
				left_sibling->key[left_sibling->key_num - 1] = 0;
				left_sibling->p_child[left_sibling->key_num] = NULL;
				left_sibling->key_num--;
			}
			//�����ֵܽ�
			else if (right_sibling && right_sibling->key_num > BTree_D - 1)
			{
				//���ֵܵĵ�һ������ �ƶ��� child�����һ�����ӣ������ؼ�������
				child->key[child->key_num] = node->key[index];
				child->p_child[child->key_num + 1] = right_sibling->p_child[0];
				child->key_num++;

				//���ֵܵĵ�һ���ؼ������Ƶ������
				node->key[index] = right_sibling->key[0];


				//�������ֵܵĺ�������
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
			//�ϲ��ؼ��ֺ������ֵ�
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


		//child�Ĺؼ��ָ�������BTree_D-1�����Եݹ�ɾ��
		BTree_recursive_delete(&child, key);	
		
	}
}



/*
�ϲ���������node index+1���ĺ��ӽ��ϲ���index���ĺ��ӽ�㣬������index���Ĺؼ���
���룺parent :node�ĸ����   node:������ɾ���ؼ��ֵĽ��   index:Ҫɾ���Ĺؼ���Ϊnode->key[index]
*/
void BTree_Merge(BTree * parent, BTNode * node, int index)
{
	assert(parent && node && index >= 0 && index < node->key_num);

	KeyType key = node->key[index];
	BTNode * left_child = node->p_child[index];
	BTNode * right_child = node->p_child[index + 1];

	assert(left_child && right_child && left_child->key_num==BTree_D-1
	&&right_child->key_num==BTree_D-1);

	//��node��index���Ĺؼ���key���Ƶ�����left_child�У��Һ����еĵ�һ������ָ���ƶ���������ȥ
	left_child->key[left_child->key_num] = key;
	left_child->p_child[left_child->key_num + 1] = right_child->p_child[0];
	left_child->key_num++;

	//�Һ��ӹؼ��ֺ�ָ��ϲ���������
	for (int i = 0; i < right_child->key_num; i++)
	{
		left_child->key[left_child->key_num] = right_child->key[i];
		left_child->p_child[left_child->key_num + 1] = right_child->p_child[i + 1];
		left_child->key_num++;
	}

	//��node�����Ƶ�key�����Ԫ�غ���
	for (int i = index; i < node->key_num-1; i++)
	{
		node->key[i] = node->key[i + 1];
		node->p_child[i + 1] = node->p_child[i + 2];
	}

	node->key[node->key_num - 1] = 0;
	node->p_child[node->key_num] = NULL;
	node->key_num--;

	//���node���û��key�ˣ��ͰѸ�������Ϊ�ϲ�������ӽ��
	if (node->key_num == 0)
	{
		*parent = left_child;
		delete left_child;
		left_child = NULL;
	}

	delete right_child;
	right_child = NULL;
}



	

