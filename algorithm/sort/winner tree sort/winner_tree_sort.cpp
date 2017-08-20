//胜者树
//又叫锦标赛排序
//时间复杂度为O(n * logn)
//空间复杂度为O(n-1)
//是拿空间换时间的算法

#include <iostream>
#include <ctime>
#include <random>
#include <cassert>

#define WINNER_TREE_MAX 65535
//#define WINNER_TREE_DEBUG 1

//胜者树的结点
struct tree_node
{
	int nData;
	int id;
	tree_node(int d, int i) :nData(d), id(i) {}
	tree_node() {}
};

void arr_print(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}



void get_random_sequence(int arr[], int n, int  max)
{
	std::default_random_engine e(time(0));//引擎，用于生成unsigned随机整数
	std::uniform_int_distribution<unsigned> u(0, max);//生成[0,max]内均匀分布的数
													  //arr[0]不使用
	for (int i = 1; i < n; i++)
	{
		arr[i] = u(e);
	}
	std::cout << "随机序列：" << std::endl;
	arr_print(arr, n);
}



//根据待排序的数组，初始建立胜者树
tree_node *  build_winner_tree(int arr[], int arr_len, int & winner_tree_len)
{
	//构建满二叉树，叶结点要是2的n次方，不够的要补
	int nNode = 1;
	while (nNode < arr_len)
		nNode <<= 1;

	winner_tree_len = 2 * nNode - 1;
	tree_node * trees = new tree_node[winner_tree_len]();
	memset(trees, 0, winner_tree_len * sizeof(tree_node));
	assert(trees);

	//trees中，下标为0-(nNode-2)的结点存放中间结点
	//下标为(nNode-1)-(winner_tree_len-1)的结点存放叶子结点
	for (int i = nNode - 1; i < winner_tree_len; i++)
	{
		int index = i - (nNode - 1);
		if (index < arr_len)
			trees[i] = tree_node(arr[index], index);
		else
			trees[i] = tree_node(WINNER_TREE_MAX, -1); //对于补充的数据，初始化为最大
	}

#ifdef WINNER_TREE_DEBUG
	print_winner_tree(trees, winner_tree_len);
#endif

	//根据叶子结点向上生成父结点
	for (int i = nNode - 2; i >= 0; i--)
	{
		if (trees[2 * i + 1].nData < trees[2 * i + 2].nData)
			trees[i] = trees[2 * i + 1];
		else
			trees[i] = trees[2 * i + 2];
	}

#ifdef WINNER_TREE_DEBUG
	print_winner_tree(trees, winner_tree_len);
#endif
	return trees;
}



//打印胜者树
void print_winner_tree(tree_node * trees, int winner_tree_len)
{
	std::cout << "胜者树：" << std::endl;
	assert(trees && winner_tree_len > 0);
	for (int i = 0; i < winner_tree_len; i++)
	{
		std::cout << trees[i].nData << " ";
	}
	std::cout << std::endl;
}


//释放内存
void clear_tree(tree_node * trees)
{
	delete trees;
	trees = NULL;

}


//向上调整胜者树
void  adjust_winner_tree(tree_node * trees, int id_in_tree)
{
	//调整到根结点就结束
	while (id_in_tree != 0)
	{
		//奇数/偶数结点，其兄弟结点下标不同，单独讨论
		int brother_id_in_tree;
		if (id_in_tree % 2 == 0)
		{
			brother_id_in_tree = id_in_tree - 1;
		}
		else
		{
			brother_id_in_tree = id_in_tree + 1;
		}

		//更新父结点
		trees[(id_in_tree - 1) / 2] = (trees[id_in_tree].nData < trees[brother_id_in_tree].nData) ?
			trees[id_in_tree] : trees[brother_id_in_tree];

		id_in_tree = (id_in_tree - 1) / 2;
	}

}


//胜者树排序
void winner_tree_sort(tree_node * trees, int winner_tree_len)
{
	//data数组临时存储结果，打印后释放
	int data_len = winner_tree_len / 2 + 1;
	int * data = new int[data_len]();
	memset(data, 0, data_len * sizeof(int));
	assert(data);


	//每输出根结点后，把对应的叶节点替换为最大值，再从该叶节点向上调整
	for (int i = 0; i < data_len; i++)
	{
		data[i] = trees[0].nData;//输出
		int id_in_tree = winner_tree_len - data_len + trees[0].id;//该叶结点在胜者树中的下标
		trees[id_in_tree].nData = WINNER_TREE_MAX;//替换叶结点为最大值
#ifdef WINNER_TREE_DEBUG
		print_winner_tree(trees, winner_tree_len);
#endif
		adjust_winner_tree(trees, id_in_tree);//调整树
	}



	std::cout << "胜者树排序: " << std::endl;
	for (int i = 0; i < data_len; i++)
	{
		if (data[i] != WINNER_TREE_MAX)
			std::cout << data[i] << " ";
	}
	std::cout << std::endl;
	delete data;

}



//test
void winner_tree_test_case_0()
{
	//生成长度为20的随机序列，范围0-100
	std::default_random_engine e(time(0));
	std::uniform_int_distribution<unsigned> u(0, 100);
	int arr[20];
	std::cout << "胜者树随机序列：" << std::endl;
	for (int i = 0; i < 20; i++)
	{
		arr[i] = u(e);
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	//胜者树排序
	int winner_tree_len = 0;//生成的胜者树的长度
	tree_node * trees = NULL;
	trees = build_winner_tree(arr, 20, winner_tree_len);
	winner_tree_sort(trees, winner_tree_len);

	//释放内存
	clear_tree(trees);

}

int main()
{
	//生成长度为20的随机序列，范围0-100
	std::default_random_engine e(time(0));
	std::uniform_int_distribution<unsigned> u(0, 100);
	int arr[20];
	std::cout << "胜者树随机序列：" << std::endl;
	for (int i = 0; i < 20; i++)
	{
		arr[i] = u(e);
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	//胜者树排序
	int winner_tree_len = 0;//生成的胜者树的长度
	tree_node * trees = NULL;
	trees = build_winner_tree(arr, 20, winner_tree_len);
	winner_tree_sort(trees, winner_tree_len);

	//释放内存
	clear_tree(trees);
	return 0;
}