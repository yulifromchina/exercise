#include <iostream>
#include "QueueSystem.h"


//����QueueSystem���event_sort()�������ܣ����¼�����ʱ������
void test_print_event(QueueSystem & qs)
{
	qs.v_event.push_back(std::make_shared<Event>());
	qs.v_event[0]->set_time(3);
	qs.v_event.push_back(std::make_shared<Event>());
	qs.v_event[1]->set_time(2);
	qs.v_event.push_back(std::make_shared<Event>());
	qs.v_event[2]->set_time(1);

	std::cout << "����ǰ��" << std::endl;
	for_each(qs.v_event.begin(), qs.v_event.end(), [](std::shared_ptr<Event> e1)
	{std::cout << e1->get_time() << std::endl; });

	qs.event_sort();

	std::cout << "�����" << std::endl;
	for_each(qs.v_event.begin(), qs.v_event.end(), [](std::shared_ptr<Event> e1)
	{std::cout << e1->get_time() << std::endl; });
}
//int  main()
//{
//	QueueSystem qs(100, 10);
//	test_print_event(qs);
//	return 0;
//}