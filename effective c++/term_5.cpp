//����������Ϊclass������default���캯����copy ���캯����copy assignment���캯������������
#include <iostream>


//������ΪEmpty������4��Ĭ�Ϻ���
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
