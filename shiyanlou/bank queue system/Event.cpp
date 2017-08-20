#include "Event.h"

Event::~Event()
{

}


event_type Event::get_event_type()
{
	return type_;
}


void Event::set_time(double occur_time)
{
	time_ = occur_time;
}


double Event::get_time()
{
	return time_;
}


//void Event::set_customer(std::shared_ptr<Customer> c)
//{
//	event_customer_ = c;
//}
//
//
//std::shared_ptr<Customer> Event::get_customer()
//{
//	return event_customer_;
//}



void Event::set_window_num(int num)
{
	window_num = num;
}


int  Event::get_window_num()
{
	return window_num;
}




