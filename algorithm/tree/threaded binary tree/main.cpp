#include "thread_binary_tree.h"
 
BNode * pre = NULL;

int main(int argc, char ** argv[])
{
	BTree t;
	BTree head;
	std::cout << "������ǰ������������ݣ�" << std::endl;
	//eg: 1 2 3 # # 4 # # 5 6 # # 7 # #
	create_tree(&t);
	inorder_thread_head(&head, t);
	std::cout << "�������������������ݣ�" << std::endl;
	inorder_travel(head);


	//���������3 4 2 6 7 5 1
	BNode * p = t->lchild;//2
	std::cout <<"ǰ����"<<in_post_pre(t, p)->data;//4
	p = t->rchild;//5
	std::cout << "ǰ����" << in_post_pre(t, p)->data;//7
	return 0;
}