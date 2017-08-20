#include <iostream>
#include "QueueSystem.h"


//测试QueueSystem类的event_sort()的排序功能（按事件发生时间排序）
void test_print_event(QueueSystem & qs)
{
	qs.v_event.push_back(std::make_shared<Event>());
	qs.v_event[0]->set_time(3);
	qs.v_event.push_back(std::make_shared<Event>());
	qs.v_event[1]->set_time(2);
	qs.v_event.push_back(std::make_shared<Event>());
	qs.v_event[2]->set_time(1);

	std::cout << "排序前：" << std::endl;
	for_each(qs.v_event.begin(), qs.v_event.end(), [](std::shared_ptr<Event> e1)
	{std::cout << e1->get_time() << std::endl; });

	qs.event_sort();

	std::cout << "排序后：" << std::endl;
	for_each(qs.v_event.begin(), qs.v_event.end(), [](std::shared_ptr<Event> e1)
	{std::cout << e1->get_time() << std::endl; });
}
//int  main()
//{
//	QueueSystem qs(100, 10);
//	test_print_event(qs);
//	return 0;
//}