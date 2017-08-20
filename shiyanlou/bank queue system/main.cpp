#include "QueueSystem.h"
#include "const_varible.h"
#include <iostream>


int main()
{
	QueueSystem qs(open_time, window_num);
	qs.simulate(simulate_times);


	std::cout << "平均每顾客服务时间：" << qs.get_avg_customer_duration() << std::endl;
	std::cout << "平均每分钟到达顾客：" << qs.get_avg_customer_num() << std::endl;


	
	return 0;
}