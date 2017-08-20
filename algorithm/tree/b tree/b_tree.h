#define BTree_D 3 //ceil(ORDER/2)
#define ORDER 6  //�ڲ�������ORDER������������ceil(ORDER/2)��������������ٹؼ��ָ�����Ӧ-1
//�������⣺
//����ֻ�ʺ�ΪORDERΪż���������ORDERΪ����ʱ�����ѽ��ʱ������


#include <iostream>
#include <cassert>
#include <queue>

//#define DEBUG 1  //DEBUG����

/********************************����B���Ľ��*********************************************/
using KeyType = char;
struct BTNode
{
	int key_num;
	KeyType key[ORDER-1];
	BTNode * p_child[ORDER];
	bool is_leaf;

	BTNode()
	{
		key_num = 0;
		for (int i = 0; i < ORDER - 1; i++)
		{
			key[i] = 0;
			p_child[i] = NULL;
		}
		p_child[ORDER - 1] = NULL;
		is_leaf = true;
	}
};

using BTree = BTNode *;



/********************************����B��*********************************************/


/*
����һ��B��
tree�� BTree * ���Ϳ�ָ��
arr[]: Ҫ����Ĺؼ���
length: arr[]����
*/
void BTree_Create(BTree * tree, const KeyType arr[], int length);


/********************************����B���ؼ���*********************************************/


/*
�����������ؼ���
���룺���ҿ�ʼ�Ľ��tree, �ؼ���key, ���ڷ��عؼ����ڽ��λ�õ�pos
���������ָ�����ָ�룬pos���ڷ��عؼ����ڽ���λ��
*/
BTNode * BTree_Search(BTree tree, KeyType key, int *pos);



/*
�����еݹ�Ѱ�ҹؼ��֣�
���룺���ҿ�ʼ�Ľ��tree, �ؼ���key, ���ڷ��عؼ����ڽ��λ�õ�pos
���������ָ�����ָ�룬pos���ڷ��عؼ����ڽ���λ��
*/
BTNode *BTree_recursive_search(BTree tree, KeyType key, int *pos);



/********************************����B���ؼ���*********************************************/

/*
�����в���һ���ؼ���Key
���룺����ָ��tree, ������Ĺؼ���key
*/
void BTree_Insert(BTree * tree, int key);



/*
��һ�������Ľ���в���ؼ���key
����:������Ľ��node(��ؼ��ָ���С��ORDER-1), ������Ĺؼ���key
�������
*/
void BTree_insert_no_full(BTNode * node, int key);


/********************************ƽ�����*********************************************/


/*
����node���
���룺node���ĸ����parent, node�����parent�ĵڼ�������:pos , �����ѵĽ��node
������ޣ���node����Ϊ������㣬������һ���ؼ��ֵ������
*/
void BTree_split_child(BTNode * parent, int pos, BTNode * node);



/*
�ϲ���������node index+1���ĺ��ӽ��ϲ���index���ĺ��ӽ�㣬������index���Ĺؼ���
���룺tree :node�ĸ����   node:������ɾ���ؼ��ֵĽ��   index:Ҫɾ���Ĺؼ���Ϊnode->key[index]
*/
void BTree_Merge(BTree * tree, BTNode * node, int index);


/********************************��ӡ*********************************************/

/*
DFS��ӡ��
���룺tree ��ǰ����
*/
void BTree_Print(BTNode * root); 

/*
�����ӡ��
���룺tree ��ǰ������ layer ��ǰ����
*/
void BTree_Print_Level(BTree tree, int layer);


/********************************ɾ��*********************************************/

/*
ɾ�����еĹؼ���
���룺����tree, ��ɾ���Ĺؼ���key
*/
void BTree_delete(BTree * tree, KeyType key);


/*
�ݹ�ɾ�����еĹؼ���
���룺����tree, ��ɾ���Ĺؼ���key
*/
void BTree_recursive_delete(BTree * tree, KeyType key);