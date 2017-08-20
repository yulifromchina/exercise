#pragma once
#include "ServiceWindow.h"


//顾客类
class Customer
{
public:
	Customer(double arrive_time) :arrive_time_(arrive_time), duration_(0){}

	//设置顾客的服务时间
	void set_duration(double duration);

	//获取顾客的服务时间
	double get_duration_time();

	//获取顾客的到达时间
	double get_arrive_time();

	//设置服务顾客的窗口号
	//void set_window_num(int num);

	////获取服务顾客的窗口号
	//int get_window_num();

	~Customer();

private:

	//顾客到达的时间
	double arrive_time_;

	//顾客服务的时间
	double duration_;

	////如果有窗口服务的话，保存对应的窗口号
	//int window_num_;

};

