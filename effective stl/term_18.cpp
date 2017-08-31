#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	std::vector<bool> vb{true, true, false, true,true, true, false, true ,true, true, false, true };
	for_each(vb.begin(), vb.end(), [](bool b) {std::cout << b << std::endl; });
	return 0;
}