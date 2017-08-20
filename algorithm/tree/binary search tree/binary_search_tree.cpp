#include <iostream>
#include <cassert>
#include <queue>
#include <stack>


#define BINARY_SEARCH_TREE_DEBUG  1

//binary search tree
struct BSTNode
{
	int data;
	BSTNode * left;
	BSTNode * right;

	BSTNode()
	{
		left = NULL;
		right = NULL;
	}
};

//创建一个新结点
BSTNode * bst_get_new_node(int data)
{
	BSTNode * new_node = new BSTNode;
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}


//插入一个新结点
BSTNode * bst_insert(BSTNode * root, int data)
{
	if (root == NULL)
		root = bst_get_new_node(data);
	else if (root->data >= data)
		root->left = bst_insert(root->left, data);
	else
		root->right = bst_insert(root->right, data);
	return root;
}


//查询结点是否存在
bool bst_search(BSTNode * root, int data)
{
	if (root == NULL)
		return false;
	if (root->data == data)
		return true;
	if (root->data > data)
		return bst_search(root->left, data);
	else
		return bst_search(root->right, data);
}

//查找指定结点
BSTNode * bst_find(BSTNode * root, int data)
{
	if (root == NULL)
		return root;
	if (root->data == data)
		return root;
	if (root->data > data)
		return bst_find(root->left, data);
	else
		return bst_find(root->right, data);
}


//寻找最小结点（迭代）
BSTNode * bst_find_min_iterator(BSTNode * root)
{
	if (root == NULL)
	{
		std::cout << "Error: empty tree!" << std::endl;
		return root;
	}
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}


//寻找最小结点（递归）
BSTNode * bst_find_min_recusion(BSTNode * root)
{
	if (root == NULL)
	{
		std::cout << "Error: empty tree!" << std::endl;
		return root;
	}
	if (root->left != NULL)
		return bst_find_min_recusion(root->left);
	else
		return root;
}


//由先序序列和中序序列确定二叉树
//参数：先序序列，中序序列，先序序列的开始下标，先序序列的结束下标，中序序列的开始下标，中序序列的结束下标
BSTNode * pre_in_create(int pre_arr[], int in_arr[], int pre_begin, int pre_end, int in_begin, int in_end)
{
	BSTNode * root = new BSTNode();
	root->data = pre_arr[pre_begin];//先序序列的第一个元素为根的值
	int i;
	for (i = in_begin; in_arr[i] != root->data && i <= in_end; i++);//找到根在中序序列中的位置

	int len_lchild = i - in_begin;  //左子树的长度
	int len_rchild = in_end - i;  //右子树的长度

	if (len_lchild)
	{
		//参数：中序序列的下标为以根划分，左边部分
		//先序序列的下标为除去根，长度len_lchild的部分
		root->left = pre_in_create(pre_arr, in_arr, pre_begin + 1, pre_begin + len_lchild, in_begin, in_begin + len_lchild - 1);
	}

	if (len_rchild)
	{
		//参数：中序序列的下标为以根划分，右边部分
		//先序序列的下标为除去根，除去len_lchild的部分
		root->right = pre_in_create(pre_arr, in_arr, pre_end - len_rchild + 1, pre_end, in_end - len_rchild + 1, in_end);
	}

	return root;
}


/*delete a node from BST
case 1: no child
case 2: one child
case 3: two child，then:
way1:find the minum right; copy the value in the targeted node; delete the duplicate from right-subtree
way2:find the max left; copy the value in the targeted node; delete the duplicate from left-subtree

*/
//删除结点
BSTNode * bst_delete_node(BSTNode * root, int data)
{
	if (root == NULL) return root;

	if (root->data < data)
		root->right = bst_delete_node(root->right, data);
	else if (root->data > data)
		root->left = bst_delete_node(root->left, data);
	else
	{
		//case1 :no child
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		//case 2: one child
		else if (root->left == NULL)
		{
			BSTNode * temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL)
		{
			BSTNode * temp = root;
			root = root->left;
			delete temp;
		}
		//case 3: two child
		else
		{
			BSTNode * temp = bst_find_min_iterator(root->right);
			root->data = temp->data;
			root->right = bst_delete_node(root->right, temp->data);
		}
	}
	return root;
}


//树的高度
int bst_get_height(BSTNode * root)
{
	if (root == NULL)
		return 0;
	int left_height = bst_get_height(root->left);
	int right_height = bst_get_height(root->right);
	return (left_height > right_height ? (left_height + 1) : (right_height + 1));
}

//非递归方式取得树的高度
int bst_get_height_by_iterator(BSTNode *root)
{
	if (root == NULL)
		return 0;

	int height = 0;
	std::queue<BSTNode * >queue_;
	queue_.push(root);
	while (!queue_.empty())
	{
		height++;
		int cur_level_size = queue_.size();
		int cnt = 0;
		while (cnt < cur_level_size)
		{
			BSTNode * current = queue_.front();
			queue_.pop();

			cnt++;
			if (current->left)
				queue_.push(current->left);
			if (current->right)
				queue_.push(current->right);
		}
	}
	return height;
}


//层序遍历
void bst_level_order(BSTNode * root)
{
	if (root == NULL)
		return;
	std::queue<BSTNode*> queue_;
	queue_.push(root);

	while (!queue_.empty())
	{
		BSTNode * current = queue_.front();
		std::cout << current->data << " ";
		if (current->left) queue_.push(current->left);
		if (current->right) queue_.push(current->right);
		queue_.pop();
	}
	std::cout << std::endl;
}


//层序遍历：从右至左，从下至上
void bst_level_order_reverse(BSTNode * root)
{
	if (root == NULL)
		return;
	std::queue<BSTNode*> queue_;
	std::stack<BSTNode*> stack_;
	queue_.push(root);

	while (!queue_.empty())
	{
		BSTNode * current = queue_.front();
		stack_.push(current);
		if (current->left) queue_.push(current->left);
		if (current->right) queue_.push(current->right);
		queue_.pop();
	}
	while (!stack_.empty())
	{
		BSTNode * current = stack_.top();
		std::cout << current->data << " ";
		stack_.pop();
	}
	std::cout << std::endl;
}



//前序遍历
void bst_preorder(BSTNode * root)
{
	if (root == NULL)
		return;
	std::cout << root->data << " ";
	bst_preorder(root->left);
	bst_preorder(root->right);
}


//#define DEBUG_1 1
//非递归先序遍历二叉树
void bst_preorder_by_iterator(BSTNode * root)
{
	BSTNode *p = root;
	std::stack<BSTNode *> stack_;
	while (p || !stack_.empty())
	{
		while (p != NULL)
		{
			std::cout << p->data << " ";
			stack_.push(p);
			p = p->left;
		}
#ifdef DEBUG_1
		std::cout << std::endl << "栈顶 -";
		std::stack<BSTNode *>temp = stack_;
		while (!temp.empty())
		{
			std::cout << temp.top()->data << " ";
			temp.pop();
		}
		std::cout << "-栈底" << std::endl;
#endif
		if (!stack_.empty())
		{
			p = stack_.top();
			stack_.pop();
			p = p->right;
		}
	}
}

//中序遍历
void bst_inorder(BSTNode * root)
{
	if (root == NULL)
		return;
	bst_inorder(root->left);
	std::cout << root->data << " ";
	bst_inorder(root->right);
}


//非递归中序遍历二叉树
void bst_inorder_by_iterator(BSTNode * root)
{
	BSTNode * p = root;
	std::stack<BSTNode *>stack_;

	while (p || !stack_.empty())
	{
		while (p != NULL)
		{
			stack_.push(p);
			p = p->left;
		}
#ifdef DEBUG_1
		std::cout << std::endl << "栈顶 -";
		std::stack<BSTNode *>temp = stack_;
		while (!temp.empty())
		{
			std::cout << temp.top()->data << " ";
			temp.pop();
		}
		std::cout << "-栈底" << std::endl;
#endif
		if (!stack_.empty())
		{
			p = stack_.top();
			stack_.pop();
			std::cout << p->data << " ";
			p = p->right;
		}
	}

}

//后续遍历
void bst_postorder(BSTNode * root)
{
	if (root == NULL)
		return;
	bst_postorder(root->left);
	bst_postorder(root->right);
	std::cout << root->data << " ";
}


//非递归后续遍历
void bst_postorder_by_iterator(BSTNode * root)
{
	BSTNode * p = root, *r = NULL;
	std::stack<BSTNode *>stack_;
	while (p || !stack_.empty())
	{
		//从根结点起，往左走，路径上的每一个结点都入栈
		while (p != NULL)
		{
			stack_.push(p);
			p = p->left;
		}
#ifdef DEBUG_1
		std::cout << std::endl << "栈顶 -";
		std::stack<BSTNode *>temp = stack_;
		while (!temp.empty())
		{
			std::cout << temp.top()->data << " ";
			temp.pop();
		}
		std::cout << "-栈底" << std::endl;
#endif
		if (!stack_.empty())
		{
			p = stack_.top();

			//任何一个结点n，在它入栈后，只要它有左孩子，左孩子必定跟这入栈，
			//因此，取出的栈顶元素，要么没有左孩子，要么左孩子已经被访问过了
			//所以我们只用关系它的右孩子了

			if (p->right && p->right != r)//右子树存在且未被访问过
			{
				p = p->right;
				stack_.push(p);
				p = p->left;
			}
			else//右子树存在且被访问过 或 右子树不存在
			{
				std::cout << p->data << " ";
				stack_.pop();
				r = p;
				p = NULL;//接下来继续执行出栈操作
			}

		}


	}

}



//非递归后续遍历2
void bst_postorder_by_iterator_2(BSTNode * root)
{
	struct SNode
	{
		BSTNode *p; int visited;  //visited代表p所指向结点的右结点是否被访问过
		SNode(BSTNode *p_, int visited_)
		{
			p = p_;
			visited = visited_;
		}
	};
	using SNode = struct SNode;

	std::stack<SNode *>stack_;
	BSTNode * node = root;

	//从根结点，往左下方走，把路径上的每一个结点入栈
	while (node)
	{
		stack_.push(new SNode(node, 0));//node指向的右结点没有被访问过
		node = node->left;
	}

	while (!stack_.empty())
	{
		SNode * sn = stack_.top();

		//任何一个结点n，在它入栈后，只要它有左孩子，左孩子必定跟这入栈，
		//因此，取出的栈顶元素，要么没有左孩子，要么左孩子已经被访问过了
		//所以我们只用关系它的右孩子了


		//如果没有右结点，或者右结点已经被访问过，由后续遍历定义，可以访问该结点了
		if (!sn->p->right || sn->visited)
		{
			stack_.pop();
			std::cout << sn->p->data << " ";
		}
		//如果右结点存在，且visited=0,说明没有处理过它的右孩子，于是去处理下
		else
		{
			sn->visited = 1;
			node = sn->p->right;
			//向左走到尽头，把路径上所有的元素入栈
			while (node != NULL)
			{
				stack_.push(new SNode(node, 0));
				node = node->left;
			}
		}

	}
}

//打印结点值为x的所有祖先
//采用后续遍历的方式
void print_ancestor(BSTNode * root, int x)
{
	struct SNode
	{
		BSTNode *p; int visited;  //visited代表p所指向结点的右结点是否被访问过
		SNode(BSTNode *p_, int visited_)
		{
			p = p_;
			visited = visited_;
		}
	};
	using SNode = struct SNode;

	std::stack<SNode *>stack_;
	BSTNode * node = root;


	while (node || !stack_.empty())
	{
		while (node != NULL)
		{
			//后续遍历，当值为x的结点即将入栈时，此时栈中存放的是它的祖先
			if (node->data == x)
			{
				while (!stack_.empty())
				{
					std::cout << stack_.top()->p->data << " ";
					stack_.pop();
				}
				return;
			}

			stack_.push(new SNode(node, 0));
			node = node->left;
		}
		if (!stack_.empty())
		{
			SNode * sn = stack_.top();
			//如果没有右结点，或者右结点已经被访问过，由后续遍历定义，可以访问该结点了
			if (!sn->p->right || sn->visited)
			{
				stack_.pop();
			}
			//如果右结点存在，且visited=0,说明没有处理过它的右孩子，于是去处理下
			else
			{
				sn->visited = 1;
				node = sn->p->right;
			}
		}
	}

}


//找到p和q的最近公共祖先r
int common_ancestor(BSTNode * root, int p, int q)
{
	struct SNode
	{
		BSTNode *p; int visited;  //visited代表p所指向结点的右结点是否被访问过
		SNode(BSTNode *p_, int visited_)
		{
			p = p_;
			visited = visited_;
		}
	};
	using SNode = struct SNode;

	std::stack<SNode *>stack_;
	std::stack<SNode *>stack_for_p;
	std::stack<SNode *>stack_for_q;

	BSTNode * node = root;


	while (node || !stack_.empty())
	{
		while (node != NULL)
		{
			if (node->data == p)
			{
				stack_for_p = stack_;
			}
			else if (node->data == q)
			{
				stack_for_q = stack_;
			}

			while (!stack_for_p.empty() && !stack_for_q.empty())
			{
				int temp1 = stack_for_p.top()->p->data;
				int temp2 = stack_for_q.top()->p->data;
				if (temp1 == temp2)
					return temp1;
				else
				{
					if (stack_for_p.size() < stack_for_q.size())
					{
						stack_for_q.pop();
					}
					else if (stack_for_p.size() > stack_for_q.size())
					{
						stack_for_p.pop();
					}
					else
					{
						stack_for_q.pop();
						stack_for_p.pop();
					}
				}
			}

			stack_.push(new SNode(node, 0));
			node = node->left;
		}
		if (!stack_.empty())
		{
			SNode * sn = stack_.top();
			//如果没有右结点，或者右结点已经被访问过，由后续遍历定义，可以访问该结点了
			if (!sn->p->right || sn->visited)
			{
				stack_.pop();
			}
			//如果右结点存在，且visited=0,说明没有处理过它的右孩子，于是去处理下
			else
			{
				sn->visited = 1;
				node = sn->p->right;
			}
		}
	}
}



//取得树的宽度
int tree_width(BSTNode * root)
{
	if (root == NULL)
		return 0;

	std::queue<BSTNode * >queue_;
	std::vector<int> width;
	queue_.push(root);
	while (!queue_.empty())
	{
		int cur_level_size = queue_.size();
		width.push_back(cur_level_size);
		int cnt = 0;
		while (cnt < cur_level_size)
		{
			BSTNode * current = queue_.front();
			queue_.pop();

			cnt++;
			if (current->left)
				queue_.push(current->left);
			if (current->right)
				queue_.push(current->right);
		}
	}
	auto max = width.begin();
	for (auto it = width.begin(); it != width.end(); it++)
	{
		if (*it > *max)
		{
			max = it;
		}
	}
	return *max;
}



//满二叉树先序序列转化成后续序列
//low, low2为最低下标
//high, high2为最高下标
void full_tree_get_postorder(int pre_arr[], int low, int high, int post_arr[], int low2, int high2)
{
	if (low > high)
		return;
	post_arr[high2] = pre_arr[low];

	int len_child = (high - low) / 2;
	//左子树
	full_tree_get_postorder(pre_arr, low + 1, low + len_child, post_arr, low2, low2 + len_child - 1);
	//右子树
	full_tree_get_postorder(pre_arr, high - len_child + 1, high, post_arr, high2 - len_child, high2 - 1);
}



//把所有的叶结点从左到右连接成一个单链表
void link_list_fun(BSTNode * root, BSTNode * & head)
{
	static BSTNode * pre = NULL;
	if (root == NULL)
		return;

	link_list_fun(root->left, head);
	if (root->left == NULL && root->right == NULL)
	{
		if (pre == NULL)
		{
			head = root;
			pre = head;
		}
		else
		{
			pre->right = root;
			pre = root;
		}
	}
	link_list_fun(root->right, head);
	pre->right = NULL;

}



//判断两棵二叉树是否相似
bool is_similar_tree(BSTNode * root1, BSTNode * root2)
{
	int left_s, right_s;
	if (root1 == NULL && root2 == NULL)
		return true;
	else if (root1 == NULL || root2 == NULL)
		return false;
	else
	{
		left_s = is_similar_tree(root1->left, root2->left);
		right_s = is_similar_tree(root1->right, root2->right);
		return left_s && right_s;
	}
}


//判断树的所有结点是否小于指定值
bool is_bst_lesser(BSTNode * root, int value)
{
	if (root == NULL)
		return true;
	if (root->data <= value && is_bst_lesser(root->left, value) && is_bst_lesser(root->right, value))
		return true;
	else
		return false;
}



//基于先序遍历，计算二叉树的所有 叶节点的带权路径长度（叶结点的权值*路径长度）


int wpl_preorder(BSTNode * node, int deep)
{
	static int wpl = 0;
	if (node->left == NULL && node->right == NULL)
	{
		wpl += deep * node->data;
	}
	if (node->left != NULL)
		wpl_preorder(node->left, deep + 1);
	if (node->right != NULL)
		wpl_preorder(node->right, deep + 1);

	return wpl;
}


int WPL(BSTNode * root)
{
	return wpl_preorder(root, 0);
}

//判断树的所有结点是否大于指定值
bool is_bst_greater(BSTNode * root, int value)
{
	if (root == NULL)
		return true;
	if (root->data >= value && is_bst_greater(root->left, value) && is_bst_greater(root->right, value))
		return true;
	else
		return false;
}

//判断是否BST
bool is_bst(BSTNode * root)
{
	if (root == NULL)
		return true;
	if (is_bst_lesser(root->left, root->data)
		&& is_bst_greater(root->right, root->data)
		&& is_bst(root->left)
		&& is_bst(root->right))
		return true;
	else
		return false;

}

//取得后继结点
BSTNode * get_successor(BSTNode * root, int data)
{
	BSTNode * current = bst_find(root, data);
	if (current == NULL) return current;

	//如果有右子树，后继结点为右子树中的最小值
	if (current->right)
	{
		return bst_find_min_iterator(current->right);
	}
	//如果只有左子树，则从根结点开始往下找
	else
	{
		BSTNode * ancestor = root;
		BSTNode * successor = NULL;
		while (ancestor != current)
		{
			if (data <= ancestor->data)
			{
				successor = ancestor;//后继是最近的一个比current大的祖先结点
				ancestor = ancestor->left;
			}
			else
			{
				ancestor = ancestor->right;
			}
		}
		return successor;
	}
}



//获取所有双分支结点的个数
int double_son_nodes(BSTNode * root)
{
	if (root == NULL)
		return 0;
	else if (root->left != NULL && root->right != NULL)
		return double_son_nodes(root->left) + double_son_nodes(root->right) + 1;
	else
		return double_son_nodes(root->left) + double_son_nodes(root->right);
}

//判断二叉树是否完全二叉树
bool is_complete(BSTNode * root)
{
	std::queue<BSTNode *>queue_;
	if (root == NULL)
		return true;
	queue_.push(root);
	while (!queue_.empty())
	{
		BSTNode * node = queue_.front();
		queue_.pop();
		//node非空，则node的左右孩子入队列
		if (node)
		{
			queue_.push(node->left);
			queue_.push(node->right);
		}
		//node为空
		else
		{
			//检查队列中是否有非空结点
			while (!queue_.empty())
			{
				node = queue_.front();
				if (node)  //队列中存在非空结点，说明不是完全二叉树
					return false;
				queue_.pop();
			}
		}

	}
	return true;
}



//交换二叉树的左右子树
void swap_child(BSTNode * root)
{
	if (root)
	{
		swap_child(root->left);
		swap_child(root->right);
		BSTNode * temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}



//求先序遍历第K个结点的值
int pre_node_to_find_kth(BSTNode * root, int k)
{
	if (k <= 0 || root == NULL)
		return -1;

	static int count = -1;
	count++;

	if (k == count)
		return root->data;
	else
	{
		int temp = pre_node_to_find_kth(root->left, k);
		if (temp != -1)
			return temp;
		temp = pre_node_to_find_kth(root->right, k);
		if (temp != -1)
			return temp;
	}
	return -1;
}


//删除子树
void delete_child_tree(BSTNode * root)
{
	if (root)
	{
		delete_child_tree(root->left);
		delete_child_tree(root->right);
		delete root;
	}
}


//删除以元素值x为根的子树
void delete_child_tree_of_x(BSTNode * root, int x)
{
	std::queue<BSTNode *>queue_;
	if (root)
	{
		if (root->data == x)
		{
			delete_child_tree(root);
			return;
		}
		//层次遍历
		queue_.push(root);
		while (!queue_.empty())
		{
			BSTNode * node = queue_.front();
			queue_.pop();
			if (node->left)
			{
				if (node->left->data == x)
				{
					delete_child_tree(node->left);
					node->left = NULL;
					return;
				}
				else
				{
					queue_.push(node->left);
				}
			}

			if (node->right)
			{
				if (node->right->data == x)
				{
					delete_child_tree(node->right);
					node->right = NULL;
					return;
				}
				else
				{
					queue_.push(node->right);
				}
			}
		}

	}
}


//test case  1
void binary_search_tree_test_case_1()
{
	BSTNode * root = NULL;
	root = bst_insert(root, 15);
	root = bst_insert(root, 200);
	root = bst_insert(root, 7);
	root = bst_insert(root, 95);
	root = bst_insert(root, 101);
	root = bst_insert(root, 2);
	root = bst_insert(root, 9);
	root = bst_insert(root, 300);
	root = bst_insert(root, 80);


	int find_num = 7;
	assert(bst_search(root, find_num));
	find_num = 10;
	assert(bst_search(root, find_num) == false);
	std::cout << "search test success!" << std::endl;

	root = bst_delete_node(root, 7);
	assert(bst_search(root, find_num) == false);
	std::cout << "delete test success!" << std::endl;

	int height = bst_get_height(root);
	std::cout << "height: " << height << std::endl;

	bst_level_order(root);

	std::cout << std::endl << "前序遍历：" << std::endl;
	bst_preorder(root);
	std::cout << std::endl << "中序遍历：" << std::endl;
	bst_inorder(root);
	std::cout << std::endl << "后序遍历：" << std::endl;
	bst_postorder(root);



	bool b_is_bst = is_bst(root);
	std::cout << std::endl << (b_is_bst ? "是BST." : "不是BST") << std::endl;

	int find_num2 = 101;
	BSTNode * successor = get_successor(root, find_num2);
	if (successor)
		std::cout << find_num2 << "的后继结点为：" << successor->data << std::endl;

}





//test case 2
void binary_search_tree_test_case_2()
{
	BSTNode * root = NULL;
	root = bst_insert(root, 15);
	root = bst_insert(root, 200);
	root = bst_insert(root, 7);
	root = bst_insert(root, 95);
	root = bst_insert(root, 101);
	root = bst_insert(root, 2);
	root = bst_insert(root, 9);
	root = bst_insert(root, 300);
	root = bst_insert(root, 80);

	BSTNode * head = NULL;
	link_list_fun(root, head);
	std::cout << "各叶结点为：" << std::endl;
	while (head != NULL)
	{
		std::cout << head->data << " ";
		head = head->right;
	}

	std::cout << std::endl << "前序遍历：" << std::endl;
	bst_preorder(root);
	std::cout << std::endl << "非递归前序遍历：" << std::endl;
	bst_preorder_by_iterator(root);
	std::cout << std::endl << "中序遍历：" << std::endl;
	bst_inorder(root);
	std::cout << std::endl << "非递归中序遍历：" << std::endl;
	bst_inorder_by_iterator(root);
	std::cout << std::endl << "后序遍历：" << std::endl;
	bst_postorder(root);
	std::cout << std::endl << "非递归后序遍历：" << std::endl;
	bst_postorder_by_iterator(root);
	std::cout << std::endl << "非递归后序遍历2：" << std::endl;
	bst_postorder_by_iterator_2(root);
	std::cout << std::endl << "结点300的所有祖先：" << std::endl;
	print_ancestor(root, 300);


	int common = common_ancestor(root, 200, 95);
	std::cout << std::endl << "200和95的最低公共祖先：" << common << std::endl;
	common = common_ancestor(root, 300, 9);
	std::cout << std::endl << "300和9的最低公共祖先：" << common << std::endl;
	common = common_ancestor(root, 101, 80);
	std::cout << std::endl << "80和101的最低公共祖先：" << common << std::endl;

	std::cout << std::endl << "树的宽度为：" << tree_width(root) << std::endl;
}


//test case 3
void binary_search_tree_test_case_3()
{
	BSTNode * root = NULL;
	root = bst_insert(root, 15);
	root = bst_insert(root, 200);
	root = bst_insert(root, 7);
	root = bst_insert(root, 95);
	root = bst_insert(root, 101);
	root = bst_insert(root, 2);
	root = bst_insert(root, 9);
	root = bst_insert(root, 300);
	root = bst_insert(root, 80);

	std::cout << "层序遍历：" << std::endl;
	bst_level_order(root);
	std::cout << "层序遍历(从右向左，从下向上)：" << std::endl;
	bst_level_order_reverse(root);

	std::cout << "结点80的祖先为：" << std::endl;
	print_ancestor(root, 80);
	std::cout << std::endl;



	std::cout << "递归遍历获取树的高度：" << bst_get_height(root) << std::endl;
	std::cout << "非递归遍历获取树的高度：" << bst_get_height_by_iterator(root) << std::endl;


	swap_child(root);
	std::cout << "交换左右子树后，层序遍历：" << std::endl;
	bst_level_order(root);


	int sum1 = WPL(root);
	std::cout << "WPL计算的所有叶结点的带全路径和：" << sum1 << std::endl;




}



//test case 4
void binary_search_tree_test_case_4()
{
	int pre_arr[] = { 15,7,2,9,200,95,80,101,300 };
	int in_arr[] = { 2,7,9,15,80,95,101,200,300 };
	BSTNode * root = pre_in_create(pre_arr, in_arr, 0, sizeof(pre_arr) / sizeof(pre_arr[0]) - 1,
		0, sizeof(in_arr) / sizeof(in_arr[0]) - 1);

	std::cout << "先序输入：" << std::endl;
	for (int i = 0, len = sizeof(pre_arr) / sizeof(pre_arr[0]); i < len; i++)
		std::cout << pre_arr[i] << " ";

	std::cout << std::endl << "先序遍历：" << std::endl;
	bst_preorder(root);

	std::cout << std::endl << "先序遍历第8个元素为：" << std::endl;
	std::cout << pre_node_to_find_kth(root, 8) << std::endl;

	std::cout << std::endl << "中序输入：" << std::endl;
	for (int i = 0, len = sizeof(in_arr) / sizeof(in_arr[0]); i < len; i++)
		std::cout << in_arr[i] << " ";

	std::cout << std::endl << "中序遍历：" << std::endl;
	bst_inorder(root);

	int double_son_num = double_son_nodes(root);
	std::cout << "双分支结点个数：" << double_son_num << std::endl;

	int is_complete_tree = is_complete(root);
	std::cout << ((is_complete_tree) ? "这是一棵完全二叉树" : "这不是完全二叉树") << std::endl;


	std::cout << "删除以200为根的子树后层次遍历：" << std::endl;
	delete_child_tree_of_x(root, 200);
	bst_level_order(root);

	std::cout << ((is_similar_tree(root, root)) ? "两棵树相似" : "两棵树不相似") << std::endl;
}



//test case 5
void binary_search_tree_test_case_5()
{
	int pre_order[7] = { 1,2,4,5,3,6,7 };
	int post_order[7] = { 0 };
	full_tree_get_postorder(pre_order, 0, 6, post_order, 0, 6);
	std::cout << "满二叉树的后序序列为：" << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << post_order[i] << " ";
	std::cout << std::endl;
}

int main()
{

	binary_search_tree_test_case_1();
	binary_search_tree_test_case_2();
	binary_search_tree_test_case_3();
	binary_search_tree_test_case_4();
	binary_search_tree_test_case_5();


	return 0;
}
