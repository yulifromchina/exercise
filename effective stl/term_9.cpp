#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <memory>
#include <algorithm>

bool is_odd(int i)
{
	return (i % 2 != 0);
}


void print(const std::vector<int> &vec)
{
	for (const auto & i : vec)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
int main()
{
	
	std::vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
	print(vi);

	vi.erase(std::remove(vi.begin(), vi.end(), 5), vi.end());
	print(vi);

	vi.erase(std::remove_if(vi.begin(), vi.end(), is_odd), vi.end());
	print(vi);

	return 0;
}
