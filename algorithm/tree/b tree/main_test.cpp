#include "b_tree.h"



//test case 1: BTree_Create²Ù×÷
void test_btree_1()
{
	std::cout <<"------------------------------------------------------------------"<< std::endl;
	std::cout << "test_btree_1_begin:" << std::endl;

	KeyType array[] = {
		'C', 'N', 'G', 'A', 'H', 'E', 'K', 'Q','M', 'F', 
		'W', 'L', 'T', 'Z', 'D', 'P', 'R', 'X', 'Y', 'S'
	};
	BTree tree = NULL;
	BTree_Create(&tree, array, sizeof(array) / sizeof(array[0]));
	BTree_Print(tree);
	std::cout << std::endl;
	BTree_Print_Level(tree, 1);

	std::cout << "test_btree_1_end" << std::endl;
	std::cout << "------------------------------------------------------------------" << std::endl;
}


//test case 2:BTree_Insert²Ù×÷
void test_btree_2()
{
	std::cout << "------------------------------------------------------------------" << std::endl;
	std::cout << "test_btree_2_begin" << std::endl;
	BTree tree = NULL;

	BTree_Insert(&tree, 'C');

	BTree_Insert(&tree, 'N');

	BTree_Insert(&tree, 'G');

	BTree_Insert(&tree, 'A');

	BTree_Insert(&tree, 'H');

	BTree_Insert(&tree, 'E');

	BTree_Insert(&tree, 'K');

	BTree_Insert(&tree, 'Q');

	BTree_Insert(&tree, 'M');

	BTree_Insert(&tree, 'F');

	BTree_Insert(&tree, 'W');

	BTree_Insert(&tree, 'L');

	BTree_Insert(&tree, 'T');

	BTree_Insert(&tree, 'Z');

	BTree_Insert(&tree, 'D');

	BTree_Insert(&tree, 'P');

	BTree_Insert(&tree, 'R');

	BTree_Insert(&tree, 'X');

	BTree_Insert(&tree, 'Y');

	BTree_Insert(&tree, 'S');

	BTree_Print(tree);
	std::cout << std::endl;
	BTree_Print_Level(tree, 1);

	std::cout << "test_btree_2_end" << std::endl;
	std::cout << "------------------------------------------------------------------" << std::endl;
}


//test case 3:BTree_delete²Ù×÷
void test_btree_3()
{
	std::cout << "------------------------------------------------------------------" << std::endl;
	std::cout << "test_btree_3_begin" << std::endl;
	KeyType array[] = {
		'C', 'N', 'G', 'A', 'H', 'E', 'K', 'Q','M', 'F',
		'W', 'L', 'T', 'Z', 'D', 'P', 'R', 'X', 'Y', 'S'
	};
	BTree tree = NULL;
	BTree_Create(&tree, array, sizeof(array) / sizeof(array[0]));
	BTree_Print(tree);
	std::cout << std::endl;
	BTree_Print_Level(tree, 1);

	std::cout << "É¾³ý¹Ø¼ü×ÖH" << std::endl;
	BTree_delete(&tree, 'H');

	std::cout << "É¾³ý¹Ø¼ü×ÖK" << std::endl;
	BTree_delete(&tree, 'K');

	std::cout << "É¾³ý¹Ø¼ü×ÖL" << std::endl;
	BTree_delete(&tree, 'L');

	std::cout << "É¾³ý¹Ø¼ü×ÖM" << std::endl;
	BTree_delete(&tree, 'M');

	std::cout << "É¾³ý¹Ø¼ü×ÖT" << std::endl;
	BTree_delete(&tree, 'T');

	std::cout << "É¾³ý¹Ø¼ü×ÖZ" << std::endl;
	BTree_delete(&tree, 'Z');

	std::cout << "É¾³ý¹Ø¼ü×ÖE" << std::endl;
	BTree_delete(&tree, 'E');

	BTree_Print(tree);
	std::cout << std::endl;
	BTree_Print_Level(tree, 1);

	std::cout << "test_btree_3_end" << std::endl;
	std::cout << "------------------------------------------------------------------" << std::endl;
}
int main()
{
	//test_btree_1();
	test_btree_2();
	test_btree_3();
	return 0;
}