#define BTree_D 3 //ceil(ORDER/2)
#define ORDER 6  //内部结点最多ORDER个子树，最少ceil(ORDER/2)个子树；最多最少关键字个数相应-1
//遗留问题：
//代码只适合为ORDER为偶数的情况；ORDER为奇数时，分裂结点时有问题


#include <iostream>
#include <cassert>
#include <queue>

//#define DEBUG 1  //DEBUG开关

/********************************定义B树的结点*********************************************/
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



/********************************创建B树*********************************************/


/*
创建一棵B树
tree： BTree * 类型空指针
arr[]: 要插入的关键字
length: arr[]长度
*/
void BTree_Create(BTree * tree, const KeyType arr[], int length);


/********************************搜索B树关键字*********************************************/


/*
在树中搜索关键字
输入：查找开始的结点tree, 关键字key, 用于返回关键字在结点位置的pos
输出：返回指向结点的指针，pos用于返回关键字在结点的位置
*/
BTNode * BTree_Search(BTree tree, KeyType key, int *pos);



/*
在树中递归寻找关键字：
输入：查找开始的结点tree, 关键字key, 用于返回关键字在结点位置的pos
输出：返回指向结点的指针，pos用于返回关键字在结点的位置
*/
BTNode *BTree_recursive_search(BTree tree, KeyType key, int *pos);



/********************************插入B树关键字*********************************************/

/*
在树中插入一个关键字Key
输入：树根指针tree, 待插入的关键字key
*/
void BTree_Insert(BTree * tree, int key);



/*
在一个不满的结点中插入关键字key
输入:待插入的结点node(其关键字个数小于ORDER-1), 待插入的关键字key
输出：无
*/
void BTree_insert_no_full(BTNode * node, int key);


/********************************平衡操作*********************************************/


/*
分裂node结点
输入：node结点的父结点parent, node结点是parent的第几个孩子:pos , 待分裂的结点node
输出：无，把node结点分为两个结点，并上升一个关键字到父结点
*/
void BTree_split_child(BTNode * parent, int pos, BTNode * node);



/*
合并操作：将node index+1处的孩子结点合并到index处的孩子结点，并下移index处的关键字
输入：tree :node的父结点   node:包含待删除关键字的结点   index:要删除的关键字为node->key[index]
*/
void BTree_Merge(BTree * tree, BTNode * node, int index);


/********************************打印*********************************************/

/*
DFS打印树
输入：tree 当前树根
*/
void BTree_Print(BTNode * root); 

/*
按层打印树
输入：tree 当前树根， layer 当前层数
*/
void BTree_Print_Level(BTree tree, int layer);


/********************************删除*********************************************/

/*
删除树中的关键字
输入：树根tree, 待删除的关键字key
*/
void BTree_delete(BTree * tree, KeyType key);


/*
递归删除树中的关键字
输入：树根tree, 待删除的关键字key
*/
void BTree_recursive_delete(BTree * tree, KeyType key);