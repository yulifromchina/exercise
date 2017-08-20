//ʤ����
//�ֽн���������
//ʱ�临�Ӷ�ΪO(n * logn)
//�ռ临�Ӷ�ΪO(n-1)
//���ÿռ任ʱ����㷨

#include <iostream>
#include <ctime>
#include <random>
#include <cassert>

#define WINNER_TREE_MAX 65535
//#define WINNER_TREE_DEBUG 1

//ʤ�����Ľ��
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
	std::default_random_engine e(time(0));//���棬��������unsigned�������
	std::uniform_int_distribution<unsigned> u(0, max);//����[0,max]�ھ��ȷֲ�����
													  //arr[0]��ʹ��
	for (int i = 1; i < n; i++)
	{
		arr[i] = u(e);
	}
	std::cout << "������У�" << std::endl;
	arr_print(arr, n);
}



//���ݴ���������飬��ʼ����ʤ����
tree_node *  build_winner_tree(int arr[], int arr_len, int & winner_tree_len)
{
	//��������������Ҷ���Ҫ��2��n�η���������Ҫ��
	int nNode = 1;
	while (nNode < arr_len)
		nNode <<= 1;

	winner_tree_len = 2 * nNode - 1;
	tree_node * trees = new tree_node[winner_tree_len]();
	memset(trees, 0, winner_tree_len * sizeof(tree_node));
	assert(trees);

	//trees�У��±�Ϊ0-(nNode-2)�Ľ�����м���
	//�±�Ϊ(nNode-1)-(winner_tree_len-1)�Ľ����Ҷ�ӽ��
	for (int i = nNode - 1; i < winner_tree_len; i++)
	{
		int index = i - (nNode - 1);
		if (index < arr_len)
			trees[i] = tree_node(arr[index], index);
		else
			trees[i] = tree_node(WINNER_TREE_MAX, -1); //���ڲ�������ݣ���ʼ��Ϊ���
	}

#ifdef WINNER_TREE_DEBUG
	print_winner_tree(trees, winner_tree_len);
#endif

	//����Ҷ�ӽ���������ɸ����
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



//��ӡʤ����
void print_winner_tree(tree_node * trees, int winner_tree_len)
{
	std::cout << "ʤ������" << std::endl;
	assert(trees && winner_tree_len > 0);
	for (int i = 0; i < winner_tree_len; i++)
	{
		std::cout << trees[i].nData << " ";
	}
	std::cout << std::endl;
}


//�ͷ��ڴ�
void clear_tree(tree_node * trees)
{
	delete trees;
	trees = NULL;

}


//���ϵ���ʤ����
void  adjust_winner_tree(tree_node * trees, int id_in_tree)
{
	//�����������ͽ���
	while (id_in_tree != 0)
	{
		//����/ż����㣬���ֵܽ���±겻ͬ����������
		int brother_id_in_tree;
		if (id_in_tree % 2 == 0)
		{
			brother_id_in_tree = id_in_tree - 1;
		}
		else
		{
			brother_id_in_tree = id_in_tree + 1;
		}

		//���¸����
		trees[(id_in_tree - 1) / 2] = (trees[id_in_tree].nData < trees[brother_id_in_tree].nData) ?
			trees[id_in_tree] : trees[brother_id_in_tree];

		id_in_tree = (id_in_tree - 1) / 2;
	}

}


//ʤ��������
void winner_tree_sort(tree_node * trees, int winner_tree_len)
{
	//data������ʱ�洢�������ӡ���ͷ�
	int data_len = winner_tree_len / 2 + 1;
	int * data = new int[data_len]();
	memset(data, 0, data_len * sizeof(int));
	assert(data);


	//ÿ��������󣬰Ѷ�Ӧ��Ҷ�ڵ��滻Ϊ���ֵ���ٴӸ�Ҷ�ڵ����ϵ���
	for (int i = 0; i < data_len; i++)
	{
		data[i] = trees[0].nData;//���
		int id_in_tree = winner_tree_len - data_len + trees[0].id;//��Ҷ�����ʤ�����е��±�
		trees[id_in_tree].nData = WINNER_TREE_MAX;//�滻Ҷ���Ϊ���ֵ
#ifdef WINNER_TREE_DEBUG
		print_winner_tree(trees, winner_tree_len);
#endif
		adjust_winner_tree(trees, id_in_tree);//������
	}



	std::cout << "ʤ��������: " << std::endl;
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
	//���ɳ���Ϊ20��������У���Χ0-100
	std::default_random_engine e(time(0));
	std::uniform_int_distribution<unsigned> u(0, 100);
	int arr[20];
	std::cout << "ʤ����������У�" << std::endl;
	for (int i = 0; i < 20; i++)
	{
		arr[i] = u(e);
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	//ʤ��������
	int winner_tree_len = 0;//���ɵ�ʤ�����ĳ���
	tree_node * trees = NULL;
	trees = build_winner_tree(arr, 20, winner_tree_len);
	winner_tree_sort(trees, winner_tree_len);

	//�ͷ��ڴ�
	clear_tree(trees);

}

int main()
{
	//���ɳ���Ϊ20��������У���Χ0-100
	std::default_random_engine e(time(0));
	std::uniform_int_distribution<unsigned> u(0, 100);
	int arr[20];
	std::cout << "ʤ����������У�" << std::endl;
	for (int i = 0; i < 20; i++)
	{
		arr[i] = u(e);
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	//ʤ��������
	int winner_tree_len = 0;//���ɵ�ʤ�����ĳ���
	tree_node * trees = NULL;
	trees = build_winner_tree(arr, 20, winner_tree_len);
	winner_tree_sort(trees, winner_tree_len);

	//�ͷ��ڴ�
	clear_tree(trees);
	return 0;
}