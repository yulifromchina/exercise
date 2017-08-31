#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vi1;
	for (int i = 0; i < 1000; i++)
	{
		vi1.push_back(i);
		if (vi1.size() == vi1.capacity())
		{
			std::cout <<"vi1.size()="<<vi1.size()<< "时，重新分配内存" << std::endl;
		}
	}

	std::vector<int> vi2;
	vi2.reserve(1000);
	for (int i = 0; i < 1000; i++)
	{
		vi2.push_back(i);
		if (vi2.size() == vi2.capacity())
		{
			std::cout << "vi2.size()=" << vi2.size() << "时，重新分配内存" << std::endl;
		}
	}
	return 0;
}