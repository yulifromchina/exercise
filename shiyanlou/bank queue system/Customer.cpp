#include "Customer.h"


Customer::~Customer()
{

}


void Customer ::set_duration(double duration)
{
	duration_ = duration;
}


double Customer::get_arrive_time()
{
	return arrive_time_;
}


//int Customer::get_window_num()
//{
//	return window_num_;
//}
//
//
//void Customer::set_window_num(int num)
//{
//	window_num_ = num;
//}


double Customer::get_duration_time()
{
	return duration_;
}