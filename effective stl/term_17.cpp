#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vi{1,2,3};
	vi.reserve(1000);
	std::cout << vi.capacity() << std::endl;
	std::vector<int>(vi).swap(vi);
	//test:except 3
	std::cout << vi.capacity() << std::endl;
}