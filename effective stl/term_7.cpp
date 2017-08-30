#include <vector>
#include <memory>
#include <iostream>

class Widget {};
void doSomething()
{
	typedef std::shared_ptr<Widget> SPW;
	std::vector<SPW> vwp;
	for (int i = 0; i < 10; i++)
	{
		vwp.push_back(SPW(new Widget));
	}
}

int main()
{
	doSomething();
	return 0;
}