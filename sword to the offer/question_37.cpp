//两个链表的第一个公共结点
//输入两个链表，找出它们的第一个公共结点

//算法核心：
//1,遍历两个链表得到长度
//2,更长的链表先走X步，X为差值
//3,接着再遍历，找到的第一个相同结点就是 第一个公共结点

//时间复杂度O(m+n)
//空间复杂度O(1)

#include <iostream>

using namespace std;

//单链表结点
struct ListNode
{
	int key;
	struct ListNode * next;
	ListNode(int value) :key(value), next(NULL) {}
};


//获取链表长度
int GetListLen(ListNode * list)
{
	if (list == NULL)
		return 0;

	ListNode * cur = list;
	int len = 0;
	while (cur)
	{
		++len;
		cur = cur->next;
	}
	return len;
}



//找出链表公共结点
ListNode * GetCommonNode(ListNode * list1, ListNode * list2)
{
	if (list1 == NULL || list2 == NULL)
		return NULL;

	int len1 = GetListLen(list1);
	int len2 = GetListLen(list2);

	ListNode * index_list1 = list1;
	ListNode * index_list2 = list2;

	//将指向更长的链表的指针先行移动diff个结点，使得开始比较时，两个链表一样长
	if (len1 > len2)
	{
		int diff = len1 - len2;
		while (diff)
		{
			index_list1 = index_list1->next;
			--diff;
		}
	}
	else if (len1 < len2)
	{
		int diff = len2 - len1;
		while (diff)
		{
			index_list2 = index_list2->next;
			--diff;
		}
	}

	while (index_list1 && index_list2 && index_list1 != index_list2)
	{
		index_list1 = index_list1->next;
		index_list2 = index_list2->next;
	}

	if (index_list1 == index_list2)
		return index_list1;  //包含了都指向NULL的情况，即没有公共结点

}

int main()
{
	ListNode * list1 = new ListNode(1);
	ListNode * list1_node = new ListNode(2);
	ListNode * list2 = new ListNode(11);
	ListNode * common = new ListNode(3);
	
	list1->next = list1_node;
	list1_node->next = common;
	//没有公共结点	
	cout << "except NULL, there should appare 1 " << (GetCommonNode(list1, list2)==NULL) << endl;

	//公共结点在最后
	list2->next = common;
	cout << "except 3, actually: " << GetCommonNode(list1, list2)->key << endl;
	
	//公共结点在中间
	ListNode * common_node = new ListNode(4);
	common->next = common_node;
	cout << "except 3, actually: " << GetCommonNode(list1, list2)->key << endl;

	//一个链表为空
	cout << "except NULL, there should appare 1 " << (GetCommonNode(list1, NULL) == NULL) << endl;

	return 0;
}