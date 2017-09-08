#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> vi{1,3,9};
	int firstNum = 9;
	int result = std::count_if(vi.begin(), vi.end(), std::bind1st(std::modulus<int>(), firstNum));
	if (result == 0)
		std::cout << "yes" << std::endl;
	return 0;
}