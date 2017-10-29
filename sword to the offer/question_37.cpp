//��������ĵ�һ���������
//�������������ҳ����ǵĵ�һ���������

//�㷨���ģ�
//1,������������õ�����
//2,��������������X����XΪ��ֵ
//3,�����ٱ������ҵ��ĵ�һ����ͬ������ ��һ���������

//ʱ�临�Ӷ�O(m+n)
//�ռ临�Ӷ�O(1)

#include <iostream>

using namespace std;

//��������
struct ListNode
{
	int key;
	struct ListNode * next;
	ListNode(int value) :key(value), next(NULL) {}
};


//��ȡ������
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



//�ҳ����������
ListNode * GetCommonNode(ListNode * list1, ListNode * list2)
{
	if (list1 == NULL || list2 == NULL)
		return NULL;

	int len1 = GetListLen(list1);
	int len2 = GetListLen(list2);

	ListNode * index_list1 = list1;
	ListNode * index_list2 = list2;

	//��ָ������������ָ�������ƶ�diff����㣬ʹ�ÿ�ʼ�Ƚ�ʱ����������һ����
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
		return index_list1;  //�����˶�ָ��NULL���������û�й������

}

int main()
{
	ListNode * list1 = new ListNode(1);
	ListNode * list1_node = new ListNode(2);
	ListNode * list2 = new ListNode(11);
	ListNode * common = new ListNode(3);
	
	list1->next = list1_node;
	list1_node->next = common;
	//û�й������	
	cout << "except NULL, there should appare 1 " << (GetCommonNode(list1, list2)==NULL) << endl;

	//������������
	list2->next = common;
	cout << "except 3, actually: " << GetCommonNode(list1, list2)->key << endl;
	
	//����������м�
	ListNode * common_node = new ListNode(4);
	common->next = common_node;
	cout << "except 3, actually: " << GetCommonNode(list1, list2)->key << endl;

	//һ������Ϊ��
	cout << "except NULL, there should appare 1 " << (GetCommonNode(list1, NULL) == NULL) << endl;

	return 0;
}