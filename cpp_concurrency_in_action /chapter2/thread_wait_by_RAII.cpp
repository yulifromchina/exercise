#include <thread>
#include <iostream>

class thread_guard
{
	std::thread & t;
public:
	explicit thread_guard(std::thread &t_) :t(t_) {}
	~thread_guard()
	{
		if (t.joinable())
		{
			t.join();
		}
	}
	thread_guard(thread_guard const &) = delete;
	thread_guard& operator=(thread_guard const &) = delete;
};

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
	int some_locale_state = 0;
	func my_func(some_locale_state);
	std::thread t(my_func);
	thread_guard g(t);
}

int main()
{
	f();
	return 0;
}