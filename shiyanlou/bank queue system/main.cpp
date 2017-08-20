#include "QueueSystem.h"
#include "const_varible.h"
#include <iostream>


int main()
{
	QueueSystem qs(open_time, window_num);
	qs.simulate(simulate_times);


	std::cout << "ƽ��ÿ�˿ͷ���ʱ�䣺" << qs.get_avg_customer_duration() << std::endl;
	std::cout << "ƽ��ÿ���ӵ���˿ͣ�" << qs.get_avg_customer_num() << std::endl;


	
	return 0;
}