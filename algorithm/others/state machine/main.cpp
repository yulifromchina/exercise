/*
利用状态机去除文件里的 单行注释 和 多行注释
状态转移表：
*/

#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
using std::ifstream;
using std::ofstream;

#define BUFFER_LEN 256
char c[BUFFER_LEN] = {0};

//#define DEBUG

void DFA(ifstream & in, ofstream & out)
{
	assert(in && out);

	int state = 0;

	while ((c[0] = in.get()) != EOF)
	{
#ifdef DEBUG
		std::cout<<std::endl << "old state:" << state << std::endl;
#endif // DEBUG


		//根据状态转移表：
		//state=0
		if (state == 0 && c[0] == '/')
			state = 1;
		else if (state == 0 && c[0] == '\'')
			state = 5;
		else if (state == 0 && c[0] == '\"')
			state = 6;
		//其余情况state 不变
		else if (state == 0)
			state = 0;

		//state=1
		else if (state == 1 && c[0] == '/')
			state = 2;
		else if (state == 1 && c[0] == '*')
			state = 3;
		else if (state == 1)
		{
			out << '/';
			state = 0;
		}

		//state=2
		else if (state == 2 && c[0] == '\n')
			state = 0;
		//其余情况state保持2不变
		else if (state == 2)
			state = 2;



		//state=3
		else if (state == 3 && c[0] == '*')
		{
#ifdef DEBUG
			std::cout << "3->4" << std::endl;
#endif // DEBUG

			state = 4;
		}
		//其余情况state保持3不变
		else if (state == 3)
		{
#ifdef DEBUG
			std::cout << "3->3" << std::endl;
#endif // DEBUG

			state = 3;
		}



		//state=4
		else if (state == 4 && c[0] == '/')
			state = 0;
		//输入除/之外的，保持3
		else if (state == 4)
			state = 3;

		//state=5
		else if (state == 5 && c[0] == '\'')
			state = 0;
		else if (state == 5 && c[0] == '\\')
			state = 7;
		//其余情况state保持5不变
		else if (state == 5)
			state = 5;


		//state=6
		else if (state == 6 && c[0] == '\\')
			state = 8;
		else if (state == 6 && c[0] == '"')
			state = 0;
		//其余情况保持state=6不变
		else if (state == 6)
			state = 6;


		//state=7
		else if (state == 7)
			state = 5; //无论输入什么，状态均转化为5

		//state=8
		else if (state == 8)
			state = 6; //无论输入什么，状态均转化为6

		if ((state == 0 && c[0]!='/') 
			|| state==5 || state==6 || state==7 || state==8)
			out << c;
#ifdef DEBUG
		std::cout << "new state:" << state << std::endl;
		std::cout << "input:" << c << std::endl<<std::endl;
#endif // DEBUG

	}
}

int main(int argc, char * argv[])
{
	ifstream in(argv[1]);
	assert(in.is_open());

	ofstream out(argv[2]);
	assert(out.is_open());

	DFA(in,out);

	in.close();
	out.close();

	return 0;
}