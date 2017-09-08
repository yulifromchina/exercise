#include <iostream>
#include <memory>
#include <string>
#include <algorithm>

int main()
{
	const int n = 10;
	std::allocator<std::string> alloca;
	std::string * p = alloca.allocate(n);
	std::string s;
	std::string * q = p;
	while (std::cin >> s && q != p + n)
	{
		alloca.construct(q++,s);
	}

	const int size = q - p;
	std::cout << "input " << size << " strings." << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << *(p + i) << std::endl;
		alloca.destroy(p+i);
	}
	alloca.deallocate(p, n);
	return 0;
}