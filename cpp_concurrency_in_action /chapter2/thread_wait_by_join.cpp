#include <iostream>
#include <thread>
#include <exception>

struct func
{
	int& i;//赋值给i的是某值的引用
	func(int &i_) :i(i_) {}
	void operator()()
	{
		for (unsigned j = 0; j < 100; ++j)
		{
			std::cout << "do task " << j << std::endl;
		}
	}
};

void f()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	std::thread t(my_func);
	try
	{

	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		t.join();
		throw;
	}
	t.join();
}

int main()
{
	f();
	return 0;
}