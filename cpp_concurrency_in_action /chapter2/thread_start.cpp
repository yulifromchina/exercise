#include <iostream>
#include <thread>

class background_task
{
public:
	void operator()() const
	{
		std::cout << "This is background task." << std::endl;
	}
};

int main()
{
	background_task f;
	std::thread mythread(f);
	mythread.join();
	return 0;
}