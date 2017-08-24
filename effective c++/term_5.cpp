//编译器暗自为class创建了default构造函数、copy 构造函数、copy assignment构造函数、析构函数
#include <iostream>


//编译器为Empty创建了4个默认函数
class Empty{};

class NoEmpty
{
public:
	NoEmpty() { std::cout << "construct" << std::endl;; }
	~NoEmpty() { std::cout << "destruct" << std::endl; }
	NoEmpty(const NoEmpty&t) { std::cout << "copy constructor"<<std::endl; }
	NoEmpty& operator=(const NoEmpty&t) { std::cout << "copy assign" << std::endl; return *this; }
};

int main()
{
	Empty e1;
	NoEmpty n1;
	NoEmpty n2(n1);
	n2 = n1;
	return 0;
}
