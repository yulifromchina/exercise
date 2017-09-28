#include <iostream>
#include <thread>

class scoped_thread
{
	std::thread t;
public:
	explicit scoped_thread(std::thread t_):t(std::move(t_))
	{
		if (!t.joinable())
			throw std::logic_error("No thread");
	}
	~scoped_thread()
	{
		t.join();
	}
	scoped_thread(scoped_thread const&) = delete;
	scoped_thread& operator=(scoped_thread const &) = delete;
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
	int some_locale_state;
	scoped_thread t((std::thread(func(some_locale_state))));
}

int main()
{
	f();
	return 0;
}