//输入入栈序列和出栈序列
//判断在该入栈序列的情况下，出栈序列是否可能
#include <iostream>
#include <stack>


bool IsCorrentOrder(int * pop_arr, int * push_arr, int len)
{
	bool is_correct = false;
	if (pop_arr != NULL && push_arr != NULL && len >= 1)
	{
		//只有一个元素的情况
		if (len == 1)
		{
			if (pop_arr[0] == pop_arr[0])
				is_correct = true;
			goto Return;
		}

		//至少2个元素的情况
		int cur_pop_arr = 0;
		int cur_push_arr = 0;
		std::stack<int> help_stack;

		while (cur_pop_arr < len && cur_push_arr < len)
		{
			help_stack.push(push_arr[cur_push_arr]);
			++cur_push_arr;

			while (cur_pop_arr <len &&help_stack.top() == pop_arr[cur_pop_arr])
			{
				help_stack.pop();
				++cur_pop_arr;
			}
		}

		if (help_stack.empty())
			is_correct = true;
	}
Return:
	return is_correct;
}

int main()
{
	using namespace std;
	//test case 1:except true
	int push_arr[] = {1,2,3,4,5};
	int pop_arr[] = {4,5,3,2,1};
	cout << IsCorrentOrder(pop_arr, push_arr, 5) << endl;;

	//test case 2:except false
	int pop_arr1[] = {4,3,5,1,2};
	cout << IsCorrentOrder(pop_arr1, push_arr, 5) << endl;;
	return 0;
}